import java.lang.Class;
import java.lang.reflect.*;

class MethodInfoTest
{
	// classes
	public static class A 
	{
  		void foo(int T1, char T2) { }
  		int bar(int T1, long T2, float T3) { return 1; }
	}
	
	// functions
	static void displayMethodInfo(Object obj)
	{
		// foo (A, T1, T2) -> void

		Class c = obj.getClass();
		
		Method methodsList[] = c.getDeclaredMethods();
		for (Method m : methodsList)
		{
			// method's name
			System.out.print(m.getName() + "(");
			
			// method's class
			System.out.print(m.getDeclaringClass().toString());
			
			// list of types for method
			Type[] typesList = m.getGenericParameterTypes();
			for (Type t : typesList)
			{
				System.out.print(", " + t.toString());
			}
			
			// method's return type
			System.out.print(") -> " + m.getGenericReturnType().toString());
			System.out.println();
		}
	}
	
	// main
	public static void main(String args[])
	{
		A a = new A();
		displayMethodInfo(a);
		
	}
	
	// references
}
