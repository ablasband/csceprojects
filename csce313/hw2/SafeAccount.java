// Graham Leslie
// SafeAccount Java class

public class SafeAccount {

	// members
	private static int balance;
	private static final int N;
	private final Semaphore lock = new Semaphore(100, true);

	// methods
	public SafeAccount(int _n) {
		N = _n;
	}
	
	// do not credit if balance exceeds n
	public void credit(int _amount) {
		lock.acquire();
		/* critical section */
		if (balance < N) balance += _amount;
		/* /critical section */
		lock.release();
	}
	
	// hold debits until acct is large enough to permit
	public void debit(int _amount) {
		lock.acquire();
		/* critical section */
		if (balance >= _amount) balance -= _amount;
		/* /critical section */
		lock.release();
	}
}