//Weird.java
//Graham Leslie

import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.*;

public class weird extends JApplet
{
	Graphics g;
	int step = 0;
	int c = 0;
	
	int x = 0;
	int y = 0;
	
	int csize = 500;
	boolean cup = true;
	
	public void init()
	{
		//
	}
	
	public void paint(Graphics g)
	{
		Random generator = new Random();
		
		int i = generator.nextInt(50);
		
		if (i == 3)
		{
			incStep();
		}
		
		reDraw(g);
		repaint();
	}
	
	public void incStep()
	{
		Random generator = new Random();
		step = generator.nextInt(8);
	}
	
	public void reDraw(Graphics g)
	{
		Random generator = new Random();
		
		Color cIndex[] = new Color[8];
		cIndex[0] = Color.red;
		cIndex[1] = Color.yellow;
		cIndex[2] = Color.orange;
		cIndex[3] = Color.green;
		cIndex[4] = Color.blue;
		cIndex[5] = Color.magenta;
		cIndex[6] = Color.white;
		cIndex[7] = Color.black;
		
		if (step == 0)
		{		
			drawBlock(cIndex[generator.nextInt(8)],0,0,1280,g);
			
			for (int i = 0; i < 15; i ++)
			{
				drawCircle(cIndex[generator.nextInt(8)],generator.nextInt(1280),generator.nextInt(1280),generator.nextInt(500),g);
			}
			
			for (int i = 0; i < 15; i ++)
			{
				drawBlock(cIndex[generator.nextInt(8)],generator.nextInt(1280),generator.nextInt(1280),generator.nextInt(500),g);
			}
			
			for (int i = 0; i < 23; i ++)
			{
				draw3dThing(cIndex[generator.nextInt(8)],generator.nextInt(1280),generator.nextInt(1280),generator.nextInt(500),g);
			}
		}
		if (step == 1)
		{
			for (int i = 0; i < 32; i ++)
			{
				drawBlock(cIndex[generator.nextInt(8)],0,32*i,1280,g);
			}
		}
		if (step == 2)
		{
			drawCircle(cIndex[generator.nextInt(8)],generator.nextInt(1280),generator.nextInt(1280),generator.nextInt(500),g);
		}
		if (step == 3)
		{
			if (c == 0)
			{
				drawBlock(cIndex[7],0,0,1280,g);
				c = 1;
			}
			else
			{
				drawBlock(cIndex[6],0,0,1280,g);
				c = 0;
			}
		}
		if (step == 4)
		{
			for (int i = 0; i < 40; i ++)
			{
				drawBlock(cIndex[generator.nextInt(8)],32*i,0,1280,g);
			}
		}
		if (step == 5)
		{
			drawBlock(cIndex[7],0,0,1280,g);
			drawCircle(Color.white,x,y,25,g);
				
			if (generator.nextInt(8) > 4)
			{			
				x += generator.nextInt(8);
				y += generator.nextInt(8);
			}
			else
			{
				x -= generator.nextInt(8);
				y -= generator.nextInt(8);
			}
			
			if (x < 0) {x = 600;}
			if (x > 1280) {x = 600;}
			if (y < 0) {y = 600;}
			if (y > 1024) {y = 600;}
		}
		if (step == 6)
		{
			drawBlock(cIndex[6],0,0,1280,g);
			drawCircle(Color.yellow,200,200,csize,g);
			
			if (csize < 300)
			{
				cup = true;
			}
			
			if (csize > 800)
			{
				cup = false;
			}
			
			if (cup)
			{
				csize += 5;
			}
			else
			{
				csize -= 5;
			}
		}
		if (step == 7)
		{		
			drawBlock(cIndex[generator.nextInt(8)],0,0,1280,g);
		}
	}
	
	//drawing
		public void drawBlock(Color c,int x,int y,int len,Graphics g)
		{
			g.setColor(c);
			g.fillRect(x,y,len,len);
		}
		
		public void drawCircle(Color c,int x,int y,int len,Graphics g)
		{
			g.setColor(c);
			g.fillOval(x,y,len,len);
		}
		
		public void draw3dThing(Color c,int x,int y,int len,Graphics g)
		{
			g.setColor(c);
			g.fill3DRect(x,y,len,len,true);
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
	
	private void doPause(int iTimeInSeconds) //pause
	{
		long t0, t1;
		t0 = System.currentTimeMillis( );
		t1 = System.currentTimeMillis( )+(iTimeInSeconds*50); //shortened to speed it up

		do
		{
			t0 = System.currentTimeMillis( );
		}
		
		while (t0 < t1);
	}
}