import java.util.Random;
import java.lang.Thread;

class TestMax
{
	public static int arraySize = 100;
	
	public interface Runnable
	{	
		void run();
	}
	
	
	public class rowSearch implements Runnable
	{
		long a[][];
		int row = 0;
		
		rowSearch(long a[][], int row)
		{
			this.a = a;
			this.row = row;
		}
		
		public void run()
		{
			long myMax = (long)0;
			
			for (int i = 0; i < arraySize; i ++)
				if (a[row][i] > myMax)
					myMax = a[row][i];
		}	
	}
	
	// functions
	public static long[][] populateArray()
	{
		Random r = new Random((long)1230123);
		
		long a[][] = new long[arraySize][arraySize];
		for (int i = 0; i < arraySize; i ++)
			for (int j = 0; j < arraySize; j ++)
				a[i][j] = r.nextLong();
				
		return a;
	}
	
	// main
	public static void main(String args[])
	{
		Runnable r = new rowSearch();
		Thread t = new Thread(r);
		t.start();
	}
	
	// references
}
