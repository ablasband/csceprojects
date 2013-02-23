import java.util.*;

class Main2
{	
	// classes
	public static class Shop<T> 
	{
		List<T> stock;
	
		public Shop() { stock = new LinkedList<T>(); }
		public T buy() 
		{ 
			return stock.remove(0);
		}
		void sell(T item) 
		{
			stock.add(item);
		}
	
		void buy(int n, Collection<? super T> items)
		{
			for (T e : stock.subList(0, n)) 
			{
				items.add(e);
			}
			for (int i=0; i<n; ++i) stock.remove(0);
		}
	
		void sell(Collection<? super T> items) 
		{
			Iterator ir = items.iterator();
			
			while (ir.hasNext())
			{
				stock.add((T)ir.next());
			}
		}
	}
	
	// functions
	
	// main
	public static void main(String args[])
	{
		final Shop<String> myShop = new Shop<String>();
		
		// sell a linkedlist of darth and ron
		List<String> sellList = new LinkedList<String>();
		sellList.add("darth vader");
		sellList.add("ron swanson");
		
		myShop.sell(sellList);
		
		// buy back darth
		List<String> buyList = new LinkedList<String>();
		myShop.buy(1,buyList);
		
		// did it work?
		System.out.println(buyList);
		
		
	}
	
	// references
	
	// hash code implementation
		// http://stackoverflow.com/questions/113511/hash-code-implementation
	// 
}