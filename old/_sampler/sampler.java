//Graham Leslie
//sampler.java
//Sampler

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

public class sampler extends JApplet implements KeyListener,MouseListener
{
	Graphics g;
	
	/* SETUP */
	
	int timer = 1;																//step counter
	int timerMax = 16;															//steps in a bar
	int numSounds = 6;															//number of samples to load
	
	/* END SETUP */
	
	double bpm = 140;															//beats per minute
	double bps = bpm/60;														//beats per second
	double sbb = 1 / bps / (timerMax / 4);										//seconds between beats
	double startTime = System.currentTimeMillis();								//time at which a bar starts
	char lastKey = '?';															//holder of last key pressed
	int[] blink = new int[numSounds];											//tells draw what samples to blink
	int toPlayC = -1;															//what sample to play
	AudioClip[] soundIndex = new AudioClip[numSounds];							//sample index
	String labels[] = new String[numSounds];									//names of the samples
	String preset = "";															//name of the preset
	boolean isPaused = false;													//if the generator is paused
	
	boolean[][] stepIndex = new boolean[numSounds][timerMax];					//pattern index
	Random generator = new Random();											//for the cool name effect
				
	boolean[][] presetStep1 = new boolean[numSounds][timerMax];					//pattern index	preset
	boolean[][] presetStep2 = new boolean[numSounds][timerMax];					//pattern index	preset
	boolean[][] presetStep3 = new boolean[numSounds][timerMax];					//pattern index preset										
	
	public void init()															//add listeners, load initial sounds
	{
		addKeyListener(this);
		addMouseListener(this);
		
		setupPresets();
		
		loadSounds();
	}
	
	public void paint(Graphics g)
	{
		if ((double)System.currentTimeMillis() >= startTime + (sbb*1000))		//executes functions by the correct
		{																		//timing according to bpm
			if (!isPaused)
			{
				if (timer < timerMax)													//there are 16 steps within
				{																		//a bar
					timer ++;
					playSoundsL();
					
				}
				else																//play pattern samples
				{
					timer = 1;
					playSoundsL();
				}
	
				reDraw(g,generator.nextInt(5));
				startTime = System.currentTimeMillis();							//16 steps done, back to step 1
			}
		}
	
		checkKeys();
		playSoundsC();															//play any keyboard triggered samples
		repaint();
	}
	
	//SOUND METHODS ************************************************************
	public void checkKeys()														//check and play sound if a key
	{																			//is triggered
		if (lastKey == 'z')
		{
			toPlayC = 0;
		}
		if (lastKey == 'x')
		{
			toPlayC = 1;
		}
		if (lastKey == 'c')
		{
			toPlayC = 2;
		}
		if (lastKey == 'v')
		{
			toPlayC = 3;
		}
		if (lastKey == 'b')
		{
			toPlayC = 4;
		}
		if (lastKey == 'n')
		{
			toPlayC = 5;
		}
		
		lastKey = '?';
	}
	
	public void loadSounds()													//main function to load sounds in
	{
		Queue<String> soundFiles = loadSoundsIn();								//used a queue
		
		for (int i = 0; i < numSounds + 1; i ++)
		{
			String f = soundFiles.poll();										//get files from loading queue
			
			if (f.charAt(0) == 's')
			{
				labels[i] = f;
				soundIndex[i] = getAudioClip(getDocumentBase(),f);
			}
			else
			{
				bpm = Double.parseDouble(f.substring(0,3));
				resetBPM();
			}
		}
		
		resetStepIndex();
		clearBlink();
	}
	
	public Queue loadSoundsIn()													//front end for loading sounds
	{
		Queue soundFiles = new LinkedList<String>();
		
		String filename = JOptionPane.showInputDialog("Enter the preset filename:");
		
		preset = parsePresetName(filename);
		
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
      			soundFiles.offer(strLine);										//add files to loading queue
    		}
    		    		
    		//Close the input stream
    		in.close();
    	}
    	catch (Exception e) //Catch exception if any
    	{
      		System.err.println("Error: " + e.getMessage());
    	}
    	
    	return soundFiles;
	}
	
	public void playSound(int n)												//play any sound
	{
		soundIndex[n].play();
		
		int i;
		boolean done = false;
		
		for (i = 0; i < blink.length; i ++)
		{
			if (blink[i] == -1 && !done)
			{
				blink[i] = n;
				done = true;
			}
		}
	}
	
	public void playSoundsC()													//play a sound triggered from the
	{																			//keyboard
		if (toPlayC != -1)
		{
			playSound(toPlayC);
			toPlayC = -1;
		}
	}
	
	public void playSoundsL()													//play a sound triggered from the
	{																		//pattern
		int i;
		
		for (i = 0; i < numSounds; i ++)
		{
			if (stepIndex[i][timer-1])
			{
				playSound(i);
			}
		}
	}
	
	public void setupPresets()
	{
		int x,y;
		
		for (y = 0; y < timerMax; y ++)
		{
			for (x = 0; x < numSounds; x ++)									//clear presets
			{
				presetStep1[x][y] = false;
				presetStep2[x][y] = false;
				presetStep3[x][y] = false;
			}
		}
		
		//preset 1 - k h s h k h s h
		presetStep1[0][0] = true;
		presetStep1[0][8] = true;
		
		presetStep1[1][2] = true;
		presetStep1[1][6] = true;
		presetStep1[1][10] = true;
		presetStep1[1][14] = true;
		
		presetStep1[2][4] = true;
		presetStep1[2][12] = true;
		
		//preset 2 k s k k s
		presetStep2[0][0] = true;
		presetStep2[0][8] = true;
		presetStep2[0][10] = true;
		
		presetStep2[2][4] = true;
		presetStep2[2][12] = true;
		
		//preset 3 kkkkskkkkkkkskkkk
		for (x = 0; x < 16; x ++)
		{
			presetStep3[0][x] = true;
		}
		
		presetStep3[2][4] = true;
		presetStep3[2][12] = true;
	}
	
	public void reDraw(Graphics g,int colorToUse)
	{
		clearScreen(g);
		
		Color cIndex[] = new Color[6];
		cIndex[0] = Color.red;
		cIndex[1] = Color.yellow;
		cIndex[2] = Color.orange;
		cIndex[3] = Color.green;
		cIndex[4] = Color.blue;
		cIndex[5] = Color.magenta;
		
		//g.setColor(cIndex[colorToUse]);
		//g.fillRect(0,0,1100,800);
		
		drawText(cIndex[colorToUse],2,12,"DRUMSAMPLER",g);
		
		drawText(Color.white,990,12,"BPM: " + Double.toString(bpm),g);
		drawText(Color.white,990,27,preset,g);
		
		//drawRect(Color.white,24,100,976,10,g);
		//drawRect(Color.white,24,190,976,10,g);
		
		int x,y,i,xx;
		Color c;
		
		Random generator = new Random();
		
		//red,yellow,orange,green,blue,purple
		
		//x = (timer*222)/timerMax;
		x = timer;
		
		drawRect(Color.white,24 + ((x - 1) * 2) + (x*64) - 64,102,64,10,g);
		drawRect(Color.white,24 + ((x - 1) * 2) + (x*64) - 64,508,64,10,g);
		
		//drawRect(Color.gray,24 + ((x - 1) * 2) + (x*64) - 64 - 2,102,64 + 4,416,g);
		
		xx = 24;
		
		if (checkBlink(0)) {c = Color.red;} else {c = Color.darkGray;}
		drawRect(c,24,32,64,64,g);
		drawText(Color.white,24,45,"Z",g);
		drawText(Color.white,24,90,parseFileName(labels[0]),g);
		
		xx += 66;
		
		if (checkBlink(1)) {c = Color.yellow;} else {c = Color.darkGray;}
		drawRect(c,xx,32,64,64,g);
		drawText(Color.white,xx,45,"X",g);
		drawText(Color.white,xx,90,parseFileName(labels[1]),g);
		
		xx += 66;
		
		if (checkBlink(2)) {c = Color.orange;} else {c = Color.darkGray;}
		drawRect(c,xx,32,64,64,g);
		drawText(Color.white,xx,45,"C",g);
		drawText(Color.white,xx,90,parseFileName(labels[2]),g);
		
		xx += 66;
		
		if (checkBlink(3)) {c = Color.green;} else {c = Color.darkGray;}
		drawRect(c,xx,32,64,64,g);
		drawText(Color.white,xx,45,"V",g);
		drawText(Color.white,xx,90,parseFileName(labels[3]),g);
		
		xx += 66;
		
		if (checkBlink(4)) {c = Color.blue;} else {c = Color.darkGray;}
		drawRect(c,xx,32,64,64,g);
		drawText(Color.white,xx,45,"B",g);
		drawText(Color.white,xx,90,parseFileName(labels[4]),g);
		
		xx += 66;
		
		if (checkBlink(5)) {c = Color.magenta;} else {c = Color.darkGray;}
		drawRect(c,xx,32,64,64,g);
		drawText(Color.white,xx,45,"N",g);
		drawText(Color.white,xx,90,parseFileName(labels[5]),g);
		
		clearBlink();
		
		for (y = 0; y < numSounds; y ++)
		{
			for (x = 0; x < timerMax; x ++)
			{				
				if (!stepIndex[y][x])
				{
					c = Color.darkGray;
					//c = cIndex[generator.nextInt(5)];
				}
				else
				{
					c = cIndex[y];
				}
				
				drawRect(c,24 + (x * 2) + (x*64),112 + (y * 2) + (y*64),64,64,g);
			}
		}
		
		drawText(Color.white,550,30,"1: Clear pattern",g);
		drawText(Color.white,550,45,"2: Move to start",g);
		drawText(Color.white,550,60,"3: Load new preset and clear pattern",g);
		drawText(Color.white,550,75,"4: Pause or Unpause and return to start",g);
		drawText(Color.white,550,90,"5 - 7: Load preset patterns",g);
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

	public void keyReleased(KeyEvent e)											//register key presses
	{
		lastKey = e.getKeyChar();
		
		if (lastKey == '+' && bpm < 200)
		{
			bpm += 2;
			resetBPM();
		}
		
		if (lastKey == '-' && bpm > 80)
		{
			bpm -= 2;
			resetBPM();
		}
		
		if (lastKey == '1')														//reset pattern
		{
			resetStepIndex();
		}
		
		if (lastKey == '2')														//move to start
		{
			timer = 0;
		}
		
		if (lastKey == '3')														//load new sounds
		{
			loadSounds();
		}
		
		if (lastKey == '4')														//pause / unpause
		{
			if (!isPaused)
			{
				timer = 0;
				isPaused = true;
			}
			else
			{
				isPaused = false;
			}
		}
		
		if (lastKey == '5')														//preset
		{
			setupPresets();
			stepIndex = presetStep1;
		}
		
		if (lastKey == '6')														//preset
		{
			setupPresets();
			stepIndex = presetStep2;
		}
		
		if (lastKey == '7')														//preset
		{
			setupPresets();
			stepIndex = presetStep3;
		}
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
	
	public void mouseReleased(MouseEvent e)										//find if mouse click is within the
	{																			//pattern area, add to pattern
		//drawRect(c,24 + (x * 2) + (x*64),280 + (y * 2) + (y*64),64,64,g);
		
		int x,y,fx,fy,iy,ix,ly,lx;
		
		x = e.getX();
		y = e.getY();
		
		if (x < 1080 && y < 508 && x > 24 && y > 112)
		{
			fx = 0;
			fy = 0;
			
			iy = 0;
			ix = 0;
			
			for (iy = 0; iy < numSounds; iy ++)
			{
				for (ix = 0; ix < timerMax; ix ++)
				{
					ly = 112 + numSounds + (iy * 2) + (iy * 64);
					lx = 24 + (ix * 2) + (ix*64);
					
					if (x > lx && x < lx + 64)
					{
						fx = ix;
					}
					
					if (y > ly && y < ly + 64)
					{
						fy = iy;
					}
				}
			}
			
			//System.out.println("(" + fx + "," + fy + ")");
			
			if (!stepIndex[fy][fx])												//add or remove from pattern
			{
				stepIndex[fy][fx] = true;
			}
			else
			{
				stepIndex[fy][fx] = false;
			}
		}

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
	public void doPause(double iTimeInSeconds)									//pauses execution
	{
		double t0, t1;
		t0 = System.currentTimeMillis( );
		t1 = System.currentTimeMillis( )+(iTimeInSeconds*1000);

		do
		{
			t0 = System.currentTimeMillis( );
		}
		while (t0 < t1);
	}
	
	public void resetBPM()														//caculates timer waits based on
	{																			//bpm
		bps = bpm/60;
		sbb = 1 / bps / (timerMax / 4);
	}
	
	public void resetStepIndex()												//empties the pattern
	{
		int x,y;
		
		for (y = 0; y < timerMax; y ++)
		{
			for (x = 0; x < numSounds; x ++)
			{
				stepIndex[x][y] = false;
			}
		}
	}
	
	public void clearBlink()													//clears the blink array (for lighting
	{																			//up playing samples)
		int i;
		
		for (i = 0; i < blink.length; i ++)
		{
			blink[i] = -1;
		}
	}
	
	public boolean checkBlink(int n)											//check if a sample should blink
	{
		int i;
		
		for (i = 0; i < blink.length; i ++)
		{
			if (blink[i] == n)
			{
				return true;
			}
		}
		
		return false;
	}
	
	public String parseFileName(String fn)										//parses a sample's path for
	{																			//displaying just the filename
		int i,l = fn.length();
		String ret = "";
		String ret2 = "";
		
		//path to filename
		i = l - 1;
		
		while (fn.charAt(i) != '/')
		{
			ret = fn.charAt(i) + ret;
			i --;
		}
		
		//cut off extension		
		l = ret.length();
		
		boolean pastD = false;
		
		for (i = l - 1; i >= 0; i --)
		{
			if (pastD)
			{
				ret2 = ret.charAt(i) + ret2;
			}
			
			if (ret.charAt(i) == '.')
			{
				pastD = true;
			}
		}
		
		return ret2;
	}
	
	public String parsePresetName(String fn)									//parses the preset's path for
	{																			//displaying just the filename	
		int i,l;
		
		l = fn.length();
		String ret = "";
		
		boolean pastD = false;
		
		for (i = l - 1; i >= 0; i --)
		{
			if (pastD)
			{
				ret = fn.charAt(i) + ret;
			}
			
			if (fn.charAt(i) == '.')
			{
				pastD = true;
			}
		}
		
		return ret;
	}
}