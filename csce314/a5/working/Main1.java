class Main1
{
	// classes
	public static final class Node 
	{
		public final int i;       
		public Node next;
		public Node (int i_, Node next_) { i = i_; next = next_; }
		
		public boolean equals(Object o)
		{
			// case where o is not a Node
			// relation defined is an equivalence relation?
			
			// check if both are linear or cyclical
			// linear easy
			// either not equal
			// cyclical det structure then parse
				// has a handle then a cycle (h,c)
				// linear h and cycle c
			
			// if other is null
			if (o == null) return false;
			else 
			{
				// if they don't have the same structure
				if (listStructure(this).hashCode() != listStructure((Node)o).hashCode()) return false;
				else
				{
					// iterate thru and check int values for each
					int ll = listStructure(this).fst;
					int cl = listStructure(this).snd;
					int tl = ll + cl;
					int j = 0;
					
					Node a = this;
					Node b = (Node)o;
					
					while (j < tl)
					{
						if (a.i != b.i) return false;
						else { a = a.next; b = b.next; }
						j++;
					}
				}
			}
				
			
			return true;
		}     
		
		@Override
		public int hashCode()
		{
			int nextHash = 0;
			if (next == null) nextHash = 0;
			else nextHash = next.hashCode();
			
			int result = 0;
			result = 37 * result + (int)i;
			result = 37 * result + nextHash;
			return result;
		}
	}
	
	
	
	public static final class Pair 
	{
		public int fst;
		public int snd;
		Pair(int x, int y) { fst = x; snd = y; }
		public String toString() { return "(" + fst + "," + snd + ")"; }
		
		@Override
		public int hashCode()
		{
			int result = 0;
			result = 37 * result + (int)fst;
			result = 37 * result + (int)snd;
			return result;
		}
	}
	
	public static final class IntNodeEnumerator
	{
		public Node current;
		IntNodeEnumerator(Node current_) { current = current_; }
		
		public boolean hasMoreElements()
		{
			if (current.next == null) return false;
			else return true;
		}
		
		public Node nextElement()
		{
			if (hasMoreElements()) return current.next;
			else return null;
		}
		
		@Override
		public int hashCode()
		{
			int currentHash = 0;
			if (current == null) currentHash = 0;
			else currentHash = current.hashCode();
			
			int result = 0;
			result = 37 * result + currentHash;
			return result;
		}
	}
	
	// functions
	public static Pair listStructure(Node startingNode)
	{
		if (startingNode == null) return new Pair(0,0);
		
		Node slow, fast, loopRef;
		slow = fast = startingNode;
		
		int lc = 0, cc = 0;
				
		while (true)
		{	
			//System.out.println("main");
			
			// detect loop
			if (fast == null || fast.next == null)
			{
				//System.out.println("case1");
				// CASE 1: we have a linear list
				slow = startingNode;
				
				while (slow != null)
				{
					lc++;
					slow = slow.next;
				}
				
				return new Pair(lc,cc);
				
			}
			// detect cycle alternatively
			else if (fast == slow && fast != startingNode)
			{
				//System.out.println("case2");
				// CASE 2: we have a cycle in the list
				loopRef = slow;
				
				// find cycle size
				fast = startingNode;
				slow = loopRef.next;
				while (slow != loopRef)
				{
					//System.out.println("ccloop");
					cc++;
					slow = slow.next;
				}
				
				// find linear size
				fast = startingNode;
				
				while (fast != slow)
				{
					//System.out.println("lcloop");
					lc++;
					slow = loopRef.next;
					
					while (slow != loopRef)
					{
						//System.out.println("lcsubloop");
						if (fast == slow) break;
						else slow = slow.next;
					}
					
					if (fast == slow) break;

					fast = fast.next;
				}
				
				lc--;
				cc++;
				return new Pair(lc,cc);
			}
			// iterate errything
			else 
			{
				//System.out.println("caseIterate");
				fast = fast.next.next;  // iterate fast
				slow = slow.next; // iterate slow
			}
			
			//return new Pair(lc,cc);
		}
	}
	
	// main
	public static void main(String args[])
	{
		
		System.out.println("[1] -- [2] -- [3] -- [4] -- [5] -- [6] -- [7]");
		System.out.println("                      |                    |");
		System.out.println("                      ----------------------");
		
		Node g = new Node(7,null);
		Node f = new Node(6,g);
		Node e = new Node(5,f);
		Node d = new Node(4,e);
		Node c = new Node(3,d);
		Node b = new Node(2,c);
		Node a = new Node(1,b);
		g.next = d;
		
		// check list structure
		Pair p = listStructure(a);
		System.out.println(p.toString());
		
		// check enumerator
		IntNodeEnumerator enumunator = new IntNodeEnumerator(a);
		System.out.println("hasmorelements: " + enumunator.hasMoreElements());
		System.out.println("next: " + enumunator.nextElement().i);
		
		Node b1 = new Node(1,null);
		Node a1 = new Node(0,b1);
		
		// check equality
		System.out.println(a1.equals(a));
		System.out.println(a1.equals(a1));
	}
	
	// references
	
	// hash code implementation
		// http://stackoverflow.com/questions/113511/hash-code-implementation
	// 
}