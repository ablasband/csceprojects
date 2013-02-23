import java.util.Random;
import java.lang.Thread;

class TestMax
{
	public static int arraySize = 1000;
	
	// create the shared max
	public static volatile long theMax = (long)0;
	
	// classes
	public static class rowSearchRunnable implements Runnable
	{
		long a[][];
		int myRow;
		public long myMax = (long)0;
		
		//rowSearch constructor
		rowSearchRunnable(long a[][], int myRow)
		{
			this.a = a;
			this.myRow = myRow;
		}
		
		public void run()
		{
			for (int i = 0; i < arraySize; i ++)
				if (a[myRow][i] > myMax)
					myMax = a[myRow][i];
		}
	}
	
	public static class rowSearchRunnableShared implements Runnable
	{
		long a[][];
		int myRow;
		
		//rowSearch constructor
		rowSearchRunnableShared(long a[][], int myRow)
		{
			this.a = a;
			this.myRow = myRow;
		}
		
		public void run()
		{
			for (int i = 0; i < arraySize; i ++)
				if (a[myRow][i] > theMax)
					theMax = a[myRow][i];
		}
	}
	
	// functions
	public static long[][] populateArray(long seed)
	{
		Random r = new Random(seed);
		
		long a[][] = new long[arraySize][arraySize];
		for (int i = 0; i < arraySize; i ++)
			for (int j = 0; j < arraySize; j ++)
				a[i][j] = r.nextLong();
				
		return a;
	}
	
	public static long maxOf2DArray(long a[][])
	{
		// create an array of runnables for each row
		rowSearchRunnable rowSR[] = new rowSearchRunnable[arraySize];
		
		// fill the thread array with runnables
		for (int i = 0; i < arraySize; i ++)
			rowSR[i] = new rowSearchRunnable(a,i);
			
		// create an array of threads for each row
		Thread rowST[] = new Thread[arraySize];
		
		// fill the thread array with threads
		for (int i = 0; i < arraySize; i ++)
			rowST[i] = new Thread(rowSR[i]);
			
		// create an array to store row maxs
		long maxS[] = new long[arraySize];
			
		// run each thread, when done store its row max
		for (int i = 0; i < arraySize; i ++)
			try { rowST[i].run(); }
			finally { maxS[i] = rowSR[i].myMax; }
		
		// variable for the final max
		long theMax = (long)0;
		
		// find the actual max from the array of row maxs
		for (int i = 0; i < arraySize; i ++)
			if (maxS[i] > theMax) theMax = maxS[i];
		
		return theMax;
	}
	
	public static synchronized long sharedMaxOf2DArray(long a[][])
	{
		// create an array of runnables for each row
		rowSearchRunnableShared rowSR[] = new rowSearchRunnableShared[arraySize];
		
		// fill the thread array with runnables
		for (int i = 0; i < arraySize; i ++)
			rowSR[i] = new rowSearchRunnableShared(a,i);
			
		// create an array of threads for each row
		Thread rowST[] = new Thread[arraySize];
		
		// fill the thread array with threads
		for (int i = 0; i < arraySize; i ++)
			rowST[i] = new Thread(rowSR[i]);
			
		// create an array to store row maxs
		long maxS[] = new long[arraySize];
			
		// run each thread, when done store its row max
		for (int i = 0; i < arraySize; i ++)
			try { rowST[i].run(); }
			finally {  }
		
		return theMax;
	}
	
	// main
	public static void main(String args[])
	{
		// unsynchronized test
		// make an array
		long a[][] = new long[arraySize][arraySize];
		a = populateArray((long)1230123);
		
		// print the final
		long start = System.currentTimeMillis();
		System.out.print("unsynchronized test:\t" + maxOf2DArray(a));
		long end = System.currentTimeMillis();
		System.out.println("\t" + (end-start) + "ms");
			
		// print the final
		start = System.currentTimeMillis();
		System.out.print("synchronized test:\t   " + sharedMaxOf2DArray(a));
		end = System.currentTimeMillis();
		System.out.println("\t" + (end-start) + "ms");
	}
	
	// references
}
