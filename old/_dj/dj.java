//Graham Leslie
//dj.java
//DJ PROGRAM

import org.jouvieje.Fmod.*;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;

import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class dj extends JFrame implements KeyListener,MouseListener
{
	JFrame frame = null;
	Graphics g;
	
	class deck
	{
		
	}

	public static class mainPanel extends JPanel
	{
		public mainPanel()
	    {
	        setBorder(BorderFactory.createLineBorder(Color.black));
	    }

	    public Dimension getPreferredSize()
	    {
	        return new Dimension(1280,800);
	    }

	    public void paintComponent(Graphics g)
	    {
	        super.paintComponent(g);       
	
	        //clear screen
	        g.setColor(Color.BLACK);
			g.fillRect(0,0,1280,800);
			
			//
	    }  
	}
		
	private static void createAndShowGUI()
	{
        //Create and set up the window.
        JFrame frame = new JFrame("DJ");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		/*
        JLabel emptyLabel = new JLabel("");
        emptyLabel.setPreferredSize(new Dimension(175, 100));
        frame.getContentPane().add(emptyLabel, BorderLayout.CENTER);
		*/
		
		frame.add(new mainPanel());

        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args)
    {      
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
    
    //FMOD *********************************************************************
    public void initFmod()
	{
		/*
		 * NativeFmod Init
		 */
		try
		{
			Init.loadLibraries();
		}
		catch(InitException e)
		{
			printExit("NativeFmod error! "+e.getMessage());
			return;
		}
		
		/*
		 * Checking NativeFmodEx version
		 */
		if(NATIVEFMOD_LIBRARY_VERSION != NATIVEFMOD_JAR_VERSION)
		{
			printExit("Error!  NativeFmod library version ("+NATIVEFMOD_LIBRARY_VERSION+") is different to jar version ("+NATIVEFMOD_JAR_VERSION+")");
			return;
		}
		
		/*==================================================*/
		
		/*
		 * Checking Fmod version
		 */
	    if(Fmod.FSOUND_GetVersion() < FMOD_VERSION)
	    {
	        printExit("Error : You are using the wrong DLL version!  You should be using FMOD "+FMOD_VERSION);
	        return;
	    }
	    
		init = true;
	}
	
	public void stop()
	{
		if(!init || deinit) return;
		deinit = true;
		
		print("\n");

		/*
		 CLEANUP AND SHUTDOWN
		 */
		if(mod != null && !mod.isNull()) Fmod.FMUSIC_StopSong(mod); modBuff = null;
		if(samp1 != null && !samp1.isNull()) Fmod.FSOUND_Sample_Free(samp1); samp1Buff = null;
		if(samp2 != null && !samp2.isNull()) Fmod.FSOUND_Sample_Free(samp2); samp2Buff = null;
		if(samp3 != null && !samp3.isNull()) Fmod.FSOUND_Sample_Free(samp3); samp3Buff = null;
		if(mod != null && !mod.isNull()) Fmod.FMUSIC_FreeSong(mod);

		print("Shutdown FMOD\n");
		Fmod.FSOUND_Close();
	}
	
	//KEY LISTENER *************************************************************
	public void keyPressed(KeyEvent e)
	{
		//
	}

	public void keyReleased(KeyEvent e)
	{
		if (e == KeyEvent.VK_ESCAPE)
		{
			stop();
			System.exit(0);
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
	
	public void mouseReleased(MouseEvent e)
	{	
		int x,y;
		
		x = e.getX();
		y = e.getY();
	}
	
	public void mousePressed(MouseEvent e)
	{
		//
	}
	
	public void mouseClicked(MouseEvent e)
	{
		//
	}
}
