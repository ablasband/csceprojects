import java.lang.Class;
import java.lang.reflect.*;
import java.lang.String;

class Tester
{
	// classes
	public static class A 
	{
  		public static boolean fooo(int T1, char T2) { return false;}
  		public static int barr(int T1, long T2, float T3) { return 1; }
		public static int testie() { return 1; }
		public static int testlie(int T1, long T2, float T3) { return 1; }
		public static boolean testdonkey() { return false; }
		public static boolean testhorse() { return true; }
		public static boolean testzedonk() { return false; }
	}
	
	public static class B 
	{
  		public static boolean fooo(int T1, char T2) { return false;}
  		public static int barr(int T1, long T2, float T3) { return 1; }
		public static int testie() { return 1; }
		public static int testlie(int T1, long T2, float T3) { return 1; }
		public static boolean testdonkey() { return false; }
		public static boolean testzedonk() { return false; }
	}
	
	// functions
	static void findParamaterlessBoolReturningMethodsWhoseNameStartsWithTest(Object obj)
	{
		Class c = obj.getClass();
		
		Method methodsList[] = c.getDeclaredMethods();
		for (Method m : methodsList)
		{
			String mName = m.getName();
			String mClass = m.getDeclaringClass().toString();
			Type[] mTypesList = m.getGenericParameterTypes();
			String mReturn = m.getGenericReturnType().toString();
			
			if (mName.substring(0,4).equals("test") && mTypesList.length == 0 && mReturn.equals("boolean"))
			{
				// good
				System.out.println("Test " + mName + " succeeded");
			}
			else
			{
				// NOT good SCURVY
				System.out.println("Test " + mName + " FAILED!");
				
			}
		}
	}
	
	// main
	public static void main(String args[])
	{
		if (args.length > 0) 
		{
			String classSelection = args[0];
			
			System.out.println(classSelection);
			
			A a = new A();
			B b = new B();
			
			if (classSelection.equals("A")) findParamaterlessBoolReturningMethodsWhoseNameStartsWithTest(a);
			else if (classSelection.equals("B")) findParamaterlessBoolReturningMethodsWhoseNameStartsWithTest(b);
			else System.out.println("class DNE!"); System.exit(1);
		}
		else 
		{
			System.out.println("error"); 
			System.exit(1);
		}		
	}
	
	// references
}
