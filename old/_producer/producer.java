//Graham Leslie
//producer.java
//Producer

import javax.swing.*;
import java.awt.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;
import java.util.Random;
import java.awt.event.*;
import java.applet.*;
import java.lang.*;
import java.util.*;

public class producer extends JApplet implements KeyListener,MouseListener
{
	Graphics g;
	
	int timer = 1;
	int timerMax = 16;
	double bpm = 140;															//beats per minute
	double bps = bpm/60;														//beats per second
	double sbb = 1 / bps / (timerMax / 4);										//seconds between beats
	double startTime = System.currentTimeMillis();
	
	double reDrawTime = 100;
	
	double timeB = System.currentTimeMillis() + reDrawTime;
	boolean isPaused = false;
	int gridSelected = 0;	
	
	boolean clicked = false;
	int clickedX = 0;
	int clickedY = 0;
	
	int gridSpotSize = 50;
	
	ArrayList<button> gridButtonArray = new ArrayList<button>(9);
	ArrayList<button> topButtonArray = new ArrayList<button>(3);
	ArrayList<button> bottomButtonArray = new ArrayList<button>(9);
	
	ArrayList<grid> gridArray = new ArrayList<grid>(9);
	
	ArrayList<gridSpot> gridSpotArray = new ArrayList<gridSpot>(timerMax * 7);
	
	//CLASSES ******************************************************************
	public class grid
	{
		//VARIABLES
		boolean[][] myGrid = new boolean[timerMax][7];
		
		//CONSTRUCTOR
		public grid()
		{
			reset();
		}
		
		//METHODS		
		public boolean checkActive(int x,int y)
		{
			return myGrid[x][y];
		}
		
		public void set(int x,int y,boolean state)
		{
			myGrid[x][y] = state;
		}
		
		public void reset()
		{
			int i,j;
			
			for (j = 0; j < 7; j ++)
			{
				for (i = 0; i < timerMax; i ++)
				{
					myGrid[i][j] = false;
				}
			}
		}
	}
	
	public class button
	{
		//VARIABLES
		public boolean state = false;
		public int val = 0;
		public int x = 0;
		public int y = 0;
		
		//CONSTRUCTOR
		public button(int initVal,boolean initState)
		{
			val = initVal;
			state = initState;
		}
		
		//METHODS
		public void check()
		{
			if (clicked)
			{
				if (clickedX > x && clickedX < x + 80)
				{
					if (clickedY > y && clickedY < y + 14)
					{
						if (!state)
						{
							state = true;
							clicked = false;
						}
						else
						{
							state = false;
							clicked = false;
						}
					}
				}
			}
		}
		
	}
	
	public class gridSpot
	{
		//VARIABLES
		public int x = 0;
		public int y = 0;
		public int cA = -1;
		public int cB = -1;
		public boolean state = false;
		public boolean active = true;
		
		//CONSTRUCTOR
		public gridSpot(int initX,int initY,boolean initState,boolean initActive)
		{
			x = initX;
			y = initY;
			state = initState;
			active = initActive;
		}
		
		//METHODS
		public void check()
		{
			if (clicked)
			{
				if (clickedX > x && clickedX < x + gridSpotSize)
				{
					if (clickedY > y && clickedY < y + gridSpotSize)
					{
						if (!state)
						{
							state = true;
							clicked = false;
						}
						else
						{
							state = false;
							clicked = false;
						}
						
						if (cA != -1 && cB != -1)
						{
							grid t = gridArray.get(gridSelected);
							
							System.out.println(cA + " " + cB);
						
							t.set(cA,cB,state);
							
							gridArray.remove(gridSelected);
							gridArray.add(gridSelected,t);
						}
					}
				}			
			}
		}
	}
	
	//CORE METHODS *************************************************************
	public void init()
	{
		//ADD LISTENERS
		addKeyListener(this);
		addMouseListener(this);
		
		//INITIALIZE BUTTONS
		gridButtonArray.add(new button(0,true));
		gridButtonArray.add(new button(1,false));
		gridButtonArray.add(new button(2,false));
		gridButtonArray.add(new button(3,false));
		gridButtonArray.add(new button(4,false));
		gridButtonArray.add(new button(5,false));
		gridButtonArray.add(new button(6,false));
		gridButtonArray.add(new button(7,false));
		gridButtonArray.add(new button(8,false));
		
		topButtonArray.add(new button(0,false));
		topButtonArray.add(new button(1,false));
		topButtonArray.add(new button(2,false));
		
		bottomButtonArray.add(new button(0,false));
		bottomButtonArray.add(new button(1,false));
		bottomButtonArray.add(new button(2,false));
		
		//INITIALIZE GRIDS
		gridArray.add(new grid());
		gridArray.add(new grid());
		gridArray.add(new grid());
		gridArray.add(new grid());
		gridArray.add(new grid());
		gridArray.add(new grid());
		gridArray.add(new grid());
		gridArray.add(new grid());
		gridArray.add(new grid());
		
		//INITIALIZE GRIDSPOTS
		int cA = 0,cB = 0;
		
		gridSpot t = null;
		
		for (int i = 0; i < timerMax * 7; i ++)
		{
			if (cA > timerMax - 1)
			{
				cA = 0;
				cB ++;
			}
			
			gridSpotArray.add(new gridSpot(20 + (gridSpotSize*cA) + (17*cA),56 + (gridSpotSize*cB) + (8*cB),false,true));
			t = gridSpotArray.get(i);
			
			t.cA = cA;
			t.cB = cB;
			
			gridSpotArray.remove(i);
			gridSpotArray.add(i,t);
			
			cA ++;
		}
	}
	
	public void paint(Graphics g)
	{
		double timeToSwitch = (sbb*1000);
		
		if (gridSelected == 0 && !isPaused)
		{
			timeToSwitch *= 16;
		}
		
		if ((double)System.currentTimeMillis() >= startTime + timeToSwitch)		//executes functions by the correct
		{																		//timing according to bpm
			if (!isPaused)
			{
				if (timer < timerMax)													//there are 16 steps within
				{																		//a bar
					timer ++;
					//sounds
					
				}
				else																//play pattern samples
				{
					timer = 1;
					//sounds
				}
			}
			
			
			startTime = System.currentTimeMillis();	
		}
		
		if ((double)System.currentTimeMillis() >= timeB)
		{
			reDraw(g);
			timeB = System.currentTimeMillis() + reDrawTime;
		}
		
		checkButtons();
		repaint();
	}
	
	public void reDraw(Graphics g)
	{
		/*
		 * width	= "1100"
		 * height	= "800"
		 */
		 	 
		clearScreen(g);
		
		//BOTTOM BACKGROUND
		drawRect(Color.DARK_GRAY,8,50,1082,730,g);
		
		//HEADER
		drawText(Color.MAGENTA,2,12,"PRODUCER @ " + Double.toString(bpm) + " BPM",g);
		
		//BUTTONS
		int i,x,y;
		button t = null;
		Color c = null;
		String[] buttonsText = new String[9];
		
			//GRID BUTTONS			
			x = 2;
			y = 20;
			
			buttonsText[0] = "Track Grid";
			buttonsText[1] = "Instrument 1";
			buttonsText[2] = "Instrument 2";
			buttonsText[3] = "Instrument 3";
			buttonsText[4] = "Instrument 4";
			buttonsText[5] = "Instrument 5";
			buttonsText[6] = "Instrument 6";
			buttonsText[7] = "Instrument 7";
			buttonsText[8] = "Instrument 8";
			
			for (i = 0; i < gridButtonArray.size(); i ++)
			{
				t = gridButtonArray.get(i);
				
				if (t.state)
				{
					c = Color.MAGENTA;
				}
				else
				{
					c = Color.GRAY;
				}
				
				drawRect(c,				x,		y,		80,14,g);
				drawText(Color.white,	x + 2,	y + 11,	buttonsText[i],g);
				
				t.x = x;
				t.y = y;
				
				//check if clicked
				t.check();
								
				x += 100;
			}
			
			//TOP BUTTONS
			x = 1102;
			y = 2;
			
			buttonsText[0] = "Exit";
			buttonsText[1] = "About";
			buttonsText[2] = "BPM";
			
			for (i = 0; i < topButtonArray.size(); i ++)
			{
				t = topButtonArray.get(i);
				
				if (t.state)
				{
					c = Color.MAGENTA;
				}
				else
				{
					c = Color.GRAY;
				}
				
				drawRect(c,				x - 100,		y,		80,14,g);
				drawText(Color.white,	x - 100 + 2,	y + 11,	buttonsText[i],g);
				
				t.x = x - 100;
				t.y = y;
				
				//check if clicked
				t.check();
								
				x -= 100;
			}
			
			//GRID BUTTONS			
			x = 18;
			y = 485;
			
			buttonsText[0] = "Play / Pause";
			buttonsText[1] = "Restart Timer";
			buttonsText[2] = "Clear Grid";
			
			for (i = 0; i < bottomButtonArray.size(); i ++)
			{
				t = bottomButtonArray.get(i);
				
				if (t.state)
				{
					c = Color.MAGENTA;
				}
				else
				{
					c = Color.GRAY;
				}
				
				drawRect(c,				x,		y,		80,14,g);
				drawText(Color.white,	x + 2,	y + 11,	buttonsText[i],g);
				
				t.x = x;
				t.y = y;
				
				//check if clicked
				t.check();
								
				x += 100;
			}
		
		//GRIDSPOTS
		gridSpot tC = null;
		
		for (i = 0; i < gridSpotArray.size(); i ++)
		{
			tC = gridSpotArray.get(i);
			
			if (tC.state)
			{
				c = Color.MAGENTA;
			}
			else
			{
				c = Color.GRAY;
			}
			
			drawBlock(c,tC.x,tC.y,gridSpotSize,g);
			drawText(Color.LIGHT_GRAY,tC.x+2,tC.y+gridSpotSize-2-14,Integer.toString(i+1),g);
			drawText(Color.LIGHT_GRAY,tC.x+2,tC.y+gridSpotSize-2,"(" +  Integer.toString(tC.cA) + "," + Integer.toString(tC.cB) + ")",g);
			
			//check if clicked
			tC.check();			
		}
		
		//TIMER
		drawRect(Color.BLACK,8,465,1082,10,g);
		drawRect(Color.MAGENTA,20 + (gridSpotSize*(timer-1)) + (17*(timer-1)),465,gridSpotSize,10,g);
		
		//DESC
		String bText = "";
		
		if (gridSelected == 0)
		{
			bText = "This is the Track Grid.  Use it to arrange the patterns of the other instruments.";
		}
		
		if (gridSelected == 1 || gridSelected == 2)
		{
			bText = "Instruments 1 and 2 are for drum tracks.  Each Y-axis value is a different sample.";
		}
		
		if (gridSelected > 2)
		{
			bText = "Instruments 3 - 8 are one sample. The Y-axis modulates pitch.";
		}
		
		drawText(Color.WHITE,18,520,bText,g);
	}
	
	//DRAWING METHODS **********************************************************
		public void drawBlock(Color c,int x,int y,int len,Graphics g)
		{
			g.setColor(c);
			g.fillRect(x,y,len,len);
		}
		
		public void drawRect(Color c,int x,int y,int x2,int y2,Graphics g)
		{
			g.setColor(c);
			g.fillRect(x,y,x2,y2);
		}
				
		public void drawText(Color c,int x,int y,String str,Graphics g)
		{
			g.setColor(c);
			g.drawString(str,x,y);
		}
		
		public void clearScreen(Graphics g)
		{
			g.setColor(Color.black);
			g.fillRect(0,0,1100,800);
		}
		
		public void drawSprite(Image img,int x,int y,Graphics g)
		{
			g.drawImage(img,x,y,null);
		}
		
	//KEY LISTENER *************************************************************
	public void keyPressed(KeyEvent e)
	{
		//
	}

	public void keyReleased(KeyEvent e)
	{
		char lastKey = e.getKeyChar();	//returns char
	}

	public void keyTyped(KeyEvent e)
	{
		//
	}
	
	//MOUSE LISTENER ***********************************************************
	public void mouseExited(MouseEvent e)
	{
		//
	}
	
	public void mouseEntered(MouseEvent e)
	{
		//
	}
	
	public void mouseReleased(MouseEvent e)
	{	
		int x,y;
		
		x = e.getX();
		y = e.getY();
		
		clicked = true;
		clickedX = x;
		clickedY = y;
	}
	
	public void mousePressed(MouseEvent e)
	{
		//
	}
	
	public void mouseClicked(MouseEvent e)
	{
		//
	}
	
	//EXTRA METHODS ************************************************************
	public void checkButtons()
	{
		//BUTTONS
		int x,y;
		button t = null;
		
			//GRID BUTTONS		
			for (int i = 0; i < gridButtonArray.size(); i ++)
			{
				t = gridButtonArray.get(i);
				
				//to do
				if (t.state)
				{
					if (gridButtonArray.get(i).val != gridSelected)
					{
						gridButtonArray.remove(gridSelected);
						gridButtonArray.add(gridSelected,new button(gridSelected,false));
						
						gridSelected = i;
						
						timer = 1;
						
						updateGrid();
					}
				}
			}
						
			//TOP BUTTONS			
			for (int i = 0; i < topButtonArray.size(); i ++)
			{
				t = topButtonArray.get(i);
				
				//to do
				if (t.state)
				{
					if (t.val == 2)
					{
						Double tBPM = Double.parseDouble(JOptionPane.showInputDialog("Enter the new BPM:"));
						
						if (tBPM > 50 && tBPM < 250)
						{
							bpm = tBPM;
						}
						else
						{
							JOptionPane.showMessageDialog(null,"The BPM needs to be > 50 and < 150, and an integer.","BPM Warning",JOptionPane.WARNING_MESSAGE);
						}
						
						t.state = false;
					}
					
					if (t.val == 1)
					{
						JOptionPane.showMessageDialog(null,"PRODUCER by graham.\nFMOD Sound System, copyright © Firelight Technologies Pty, Ltd., 1994-2010.","About",JOptionPane.INFORMATION_MESSAGE);
						t.state = false;
					}
					
					if (t.val == 0)
					{
						this.setVisible(false);
					}
				}
			}
			
			//BOTTOM BUTTONS		
			for (int i = 0; i < bottomButtonArray.size(); i ++)
			{
				t = bottomButtonArray.get(i);
				
				//to do
				if (t.state)
				{
					if (t.val == 0)
					{
						if (isPaused)
						{
							isPaused = false;
						}
						else
						{
							isPaused = true;
						}
						
						t.state = false;
					}
					
					if (t.val == 1)
					{
						timer = 1;
						
						t.state = false;
					}
					
					if (t.val == 2)
					{
						clearGrid();
						
						t.state = false;
					}
				}
			}
	}
	
	public void updateGrid()
	{
		int i,cA = 0, cB = 0;
		
		gridSpot tC = null;
		gridSpot tAdd = null;
		
		for (i = 0; i < gridSpotArray.size(); i ++)
		{
			if (cA > timerMax - 1)
			{
				cA = 0;
				cB ++;
			}
			
			tC = gridSpotArray.get(i);
			
			tAdd = new gridSpot(tC.x,tC.y,gridArray.get(gridSelected).checkActive(cA,cB),true);
		
			tAdd.cA = cA;
			tAdd.cB = cB;
			
			gridSpotArray.remove(i);
			gridSpotArray.add(i,tAdd);
					
			cA ++;
		}
	}
	
	public void clearGrid()
	{
		int i,cA = 0, cB = 0;
		
		gridSpot tC = null;
		gridSpot tAdd = null;
		
		grid tGrid = null;
		
		tGrid = gridArray.get(gridSelected);
		tGrid.reset();
		gridArray.add(gridSelected,tGrid);
		
		for (i = 0; i < gridSpotArray.size(); i ++)
		{
			if (cA > timerMax - 1)
			{
				cA = 0;
				cB ++;
			}
			
			tC = gridSpotArray.get(i);
			
			tAdd = new gridSpot(tC.x,tC.y,false,true);
		
			tAdd.cA = cA;
			tAdd.cB = cB;
			
			gridSpotArray.remove(i);
			gridSpotArray.add(i,tAdd);
					
			cA ++;
		}
	}
	
	public AudioClip loadSound()
	{
		AudioClip audio = null;
		
		return audio;
	}
}

/* TO ADD
 * sound loading
 * track 1 and 2 should have 7 bays
 * the rest should modify pitch
 * get FMOD working (rarred in CPG)
 */