//ZOMBIE

import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.*;
import javax.imageio.*;
import java.awt.event.*;
import java.awt.image.*; 

public class zombie extends JApplet implements KeyListener
{
	Graphics g;
	
	int roomSpeed = 1;
	int roomWidth = 40;
	int roomHeight = 30;
	String roomBack = "night";
	char[][] roomMap = new char[roomWidth][roomHeight];
	
	BufferedImage imageIndex[] = new BufferedImage[50];
	
	/*
	 * 0 - wall
	 * 1 - 
	 */
	
	boolean keyMap[] = new boolean[5];
	
	Player player = new Player(1,1);
	
	Zombie zombie = new Zombie(38,1,50,100);
	
	//CLASSES ******************************************************************
	public class Player
	{
		//VARIABLES
		public int x;
		public int y;
		public int h = 100;
		
		public int facing = 1;
		private int swordStep = 0;
		public boolean swinging = false;
		
		private int jumpTimer = 0;
		private boolean jumping = false;
		
		private BufferedImage myImageL = null;
		private BufferedImage myImageR = null;
		
		private BufferedImage[] swordImg = new BufferedImage[6];
		
		//CONSTRUCTOR
		public Player(int ix,int iy)
		{
			x = ix*16;
			y = iy*16;
		
			try
			{
	    		myImageL = ImageIO.read(new File("littleManL.PNG"));
	    		myImageR = ImageIO.read(new File("littleManR.PNG"));
	    		
	    		swordImg[0] = ImageIO.read(new File("sword1R.PNG"));
	    		swordImg[1] = ImageIO.read(new File("sword2R.PNG"));
	    		swordImg[2] = ImageIO.read(new File("sword3R.PNG"));
	    		swordImg[3] = ImageIO.read(new File("sword1L.PNG"));
	    		swordImg[4] = ImageIO.read(new File("sword2L.PNG"));
	    		swordImg[5] = ImageIO.read(new File("sword3L.PNG"));
			}
			catch (IOException e)
			{
				System.out.println(e);
			}
		}
		
		//METHODS
		public void checkFall()
		{
			if (keyMap[1] && jumpTimer > 0)
			{
				if (jumpTimer > 0)
				{
					if (roomMap[pMod(x)][pMod(y) + 1] == 'x')
					{
						jumping = true;
						jumpTimer = -4;
					}
				}
			}
			
			if (x % 16 == 0)
			{
				if (roomMap[pMod(x)][pMod(y) + 1] != 'x' && !jumping)
				{
					y += 16;
				}
			}
			else
			{
				if ((roomMap[pMod(x)][pMod(y) + 1] != 'x') &&
				(roomMap[pMod(x) - 1][pMod(y) + 1] != 'x') && !jumping)
				{
					y += 16;
				}
			}
		}
		
		public void checkMove()
		{
			if (keyMap[0] && (roomMap[pMod(x) + 1][pMod(y)] != 'x'))
			{
				x += 8;
				facing = 1;
			}
			
			if (keyMap[2] && (roomMap[pMod(x) - 1][pMod(y)] != 'x'))
			{
				x -= 8;
				facing = -1;
			}
		}
		
		public void swordSwing()
		{
			if (swordStep == 0)
			{
				swinging = true;
			}
		}
		
		public void run()
		{
			checkFall();
			
			if (h > 0)
			{
				checkMove();
				
				jumpTimer ++;
			
				if (jumpTimer > 0)
				{
					jumping = false;
				}
				
				if (swinging)
				{
					swordStep ++;
					
					if (swordStep >= 3)
					{
						swinging = false;
						swordStep = 0;
					}
				}
				
				if (jumping)
				{
					if (x % 16 == 0)
					{
						if (roomMap[pMod(x)][pMod(y) - 1] != 'x')
						{
							y -= 16;
						}
					}
					else
					{
						if ((roomMap[pMod(x)][pMod(y) - 1] != 'x') &&
						(roomMap[pMod(x) - 1][pMod(y) - 1] != 'x'))
						{
							y -= 16;
						}
					}
				}
			}
		}
		
		public BufferedImage getImage()
		{
			if (facing == 1)
			{
				return myImageR;
			}
			else
			{
				return myImageL;
			}
		}
		
		public BufferedImage getSwordImage()
		{
			int n = 0;
			
			if (facing == -1)
			{
				n = 3;
			}
			else
			{
				n = 0;
			}
			
			return swordImg[n + swordStep];
		}
	}
	
	public class Zombie
	{
		//VARIABLES
		public int x;
		public int y;
		private int canMove = 1;
		private int jumpTimer = 0;
		private boolean jumping = false;
		private int attackDist = 1000;
		public int h = 10;
		
		public BufferedImage myImage = null;
		
		//CONSTRUCTOR
		public Zombie(int ix,int iy,int ih,int iattackDist)
		{
			x = ix * 16;
			y = iy * 16;
			h = ih;
			attackDist = iattackDist;
			
			try
			{
	    		myImage = ImageIO.read(new File("zombieMan.PNG"));
			}
			catch (IOException e)
			{
				System.out.println(e);
			}
		}
		
		//METHODS
		public void move()
		{
			if (Math.abs(player.x-x) < attackDist)
			{
				if (Math.abs(player.y-y) < attackDist)
				{
					if (player.x < x)
					{
						if (roomMap[pMod(x) - 1][pMod(y)] != 'x')
						{
							x -= 8;
						}
					}
					else
					{
						if (roomMap[pMod(x) + 1][pMod(y)] != 'x')
						{
							x += 8;
						}
					}
					
					if (player.y < y && jumpTimer > 0)
					{
						if (roomMap[pMod(x)][pMod(y) + 1] == 'x')
						{
							jumping = true;
							jumpTimer = -4;
						}
					}
				}
			}
		}
		
		public void checkFall()
		{				
			if (roomMap[pMod(x)][pMod(y) + 1] != 'x' && !jumping)
			{
				y += 16;
			}
			else
			{
				//
			}
		}
		
		public void checkHealth()
		{
			if (player.facing == 1 && player.swinging)
			{
				if (x >= player.x && x < player.x + 16)
				{
					h -= 10;
				}
			}
			else if (player.facing == -1 && player.swinging)
			{
				if (x <= player.x && x > player.x - 16)
				{
					h -= 10;
				}
			}
		}
		
		public void hitPlayer()
		{
			if (x == player.x && y == player.y)
			{
				canMove = - 10;
				
				if (player.h > 0)
				{
					player.h -= 10;
				}
			}
		}
		
		public void run()
		{
			checkFall();
			hitPlayer();
			checkHealth();
			
			if (canMove > 0)
			{
				move();
			}
			
			canMove ++;
			jumpTimer ++;
			
			if (jumpTimer > 0)
			{
				jumping = false;
			}
			
			if (jumping)
			{
				if (roomMap[pMod(x)][pMod(y) - 1] != 'x')
				{
					y -= 16;
				}
			}
			
			if (h <= 0)
			{
				zombie = null;
			}
		}
		
		public BufferedImage getImage()
		{
			return myImage;
		}
	}
	
	//MAIN METHODS *************************************************************
	public void init()
	{
		addKeyListener(this);
		resetKeyMap();
		loadMap("map1.txt");
		
		try
		{
    		imageIndex[0] = ImageIO.read(new File("pathBlock.PNG"));
		}
		catch (IOException e)
		{
			System.out.println(e);
		}
	}
	
	public void paint(Graphics g)
	{	
		doPause(roomSpeed);
		
		player.run();
		zombie.run();
		
		reDraw(g);
		repaint();
	}
	
	public void reDraw(Graphics g)
	{
		clearScreen(g);	
		
		//draw background
		drawBlock(Color.black,0,0,640,g);
		
		int x = 0,y = 0;
		
		for (y = 0; y < roomHeight; y ++)
		{
			for (x = 0; x < roomWidth; x ++)
			{
				if (roomMap[x][y] == 'x')
				{
					drawSprite(imageIndex[0],x*16,y*16,g);
				}	
			}
		}
		
		//draw player
		drawSprite(player.getImage(),player.x,player.y,g);
		
		if (player.facing == 1)
		{
			drawSprite(player.getSwordImage(),player.x + 16,player.y,g);
		}
		else
		{
			drawSprite(player.getSwordImage(),player.x - 16,player.y,g);
		}
		
		//draw zombies
		drawSprite(zombie.getImage(),zombie.x,zombie.y,g);
		
		//draw health
		drawRect(Color.black,20,20,100,20,g);
		
		int h = player.h;
		drawRect(Color.red,20,20,h,20,g);
		
		
	}
	
	//DRAWING ******************************************************************
	public void drawBlock(Color c,int x,int y,int len,Graphics g)
	{
		g.setColor(c);
		g.fillRect(x,y,len,len);
	}
	
	public void drawRect(Color c,int x,int y,int len1,int len2,Graphics g)
	{
		g.setColor(c);
		g.fillRect(x,y,len1,len2);
	}
	
	public void draw3dThing(Color c,int x,int y,int len,Graphics g)
	{
		g.setColor(c);
		g.fill3DRect(x,y,len,len,true);
	}
	
	public void drawCircle(Color c,int x,int y,int len,Graphics g)
	{
		g.setColor(c);
		g.fillOval(x,y,len,len);
	}
	
	public void drawBlockImg(Color c,int x,int y,int len,Graphics g)
	{
		g.setColor(c);
		g.fillRect(x,y,len,len);
	}
	
	public void drawText(Color c,int x,int y,String str,Graphics g)
	{
		g.setColor(c);
		g.drawString(str,x,y);
	}
	
	public void clearScreen(Graphics g)
	{
		g.setColor(Color.white);
		g.fillRect(0,0,640,480);
	}
	
	public void drawSprite(Image img,int x,int y,Graphics g)
	{
		g.drawImage(img,x,y,null);
	}
	
	//KEY LISTENER *************************************************************
	public void keyPressed(KeyEvent e)
	{
		if (e.getKeyCode() == KeyEvent.VK_RIGHT)
		{
			keyMap[0] = true;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_UP)
		{
			keyMap[1] = true;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_LEFT)
		{
			keyMap[2] = true;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_DOWN)
		{
			keyMap[3] = true;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_SPACE)
		{
			keyMap[4] = true;
			player.swordSwing();
		}
	}
	
	public void keyReleased(KeyEvent e)
	{
		if (e.getKeyCode() == KeyEvent.VK_RIGHT)
		{
			keyMap[0] = false;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_UP)
		{
			keyMap[1] = false;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_LEFT)
		{
			keyMap[2] = false;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_DOWN)
		{
			keyMap[3] = false;
		}
		
		if (e.getKeyCode() == KeyEvent.VK_SPACE)
		{
			keyMap[4] = false;
		}
	}
	
	public void keyTyped(KeyEvent e)
	{
		//
	}
	
	//EXTRA METHODS ************************************************************
	public void doPause(int iTimeInSeconds) //pause
	{
		long t0, t1;
		t0 = System.currentTimeMillis( );
		t1 = System.currentTimeMillis( )+(iTimeInSeconds*50); 					//shortened to speed it up

		do
		{
			t0 = System.currentTimeMillis( );
		}
		
		while (t0 < t1);
	}
	
	public int[] clearIntArray(int[] in)
	{
		for (int i = 0; i < in.length; i ++)
		{
			in[i] = -1;
		}
		
		return in;
	}
	
	public void resetKeyMap()
	{
		for (int i = 0; i < keyMap.length; i ++)
		{
			keyMap[i] = false;
		}
	}
	
	public void loadMap(String filename)					//loads the text file roomMap
	{
		String[] preMap = new String[100];
		int h = 0;
		
		//load roomMap to 1d string array
		
		try
		{
    		// Open the file that is the first 
    		// command line parameter
    		FileInputStream fstream = new FileInputStream(filename);
    		
    		// Get the object of DataInputStream
    		DataInputStream in = new DataInputStream(fstream);
        	BufferedReader br = new BufferedReader(new InputStreamReader(in));
    		String strLine;
    		
    		//Read File Line By Line
    		while ((strLine = br.readLine()) != null)
    		{
      			preMap[h] = strLine;
      			//width = strLine.length();										//loads roomMap into 1d array of strings before
      			h ++;															//converting to 2d char array
    		}
    		
    		//Close the input stream
    		in.close();
    	}
    	catch (Exception e) //Catch exception if any
    	{
      		System.err.println("Error: " + e.getMessage());
    	}
    	
    	//convert roomMap to 2d char array
    	
    	int ix,iy,p;
    	
    	for (iy = 0; iy < roomHeight; iy ++)
    	{
    		for (ix = 0; ix < roomWidth; ix++)
    		{
    			roomMap[ix][iy] = preMap[iy].charAt(ix);
    		}
    	}
	}
	
	public int pMod(int in)
	{
		return ((int)Math.round((in/(double)16)) * 16)/16;
	}
	
	public void printMap() 									//debug, prints roomMap in terminal
	{
		int ix,iy;
				
		for (iy = 0; iy < roomHeight; iy ++)
		{
			for (ix = 0; ix < roomWidth; ix ++)
			{
				System.out.print(roomMap[ix][iy]);
			}
			
			System.out.println("");
		}
	}
}