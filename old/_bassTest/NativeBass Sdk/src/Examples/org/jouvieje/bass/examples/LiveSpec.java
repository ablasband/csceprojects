// BASS "Live" spectrum analyser example, copyright (c) 2002-2006 Ian Luck.

package org.jouvieje.bass.examples;

import static org.jouvieje.bass.Bass.*;
import static org.jouvieje.bass.defines.INIT_MODES.INIT_BASS;
import static org.jouvieje.bass.defines.VERSIONS.BASSVERSION;
import static org.jouvieje.bass.defines.VERSIONS.NATIVEBASS_JAR_VERSION;
import static org.jouvieje.bass.defines.VERSIONS.NATIVEBASS_LIBRARY_VERSION;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.Timer;

import org.jouvieje.bass.Init;
import org.jouvieje.bass.callbacks.RECORDPROC;
import org.jouvieje.bass.examples.util.BassExample;
import org.jouvieje.bass.examples.util.BassExampleFrame;
import org.jouvieje.bass.exceptions.InitException;
import org.jouvieje.bass.misc.Pointer;
import org.jouvieje.bass.structures.HRECORD;
import java.awt.Color;
import java.awt.Graphics;
import java.nio.ByteBuffer;

/**
 * I've ported the C BASS example to NativeBass.
 * 
 * @author Jérôme JOUVIE (Jouvieje)
 * 
 * WANT TO CONTACT ME ?
 * E-mail :
 * 		jerome.jouvie@gmail.com
 * My web sites :
 * 		http://topresult.tomato.co.uk/~jerome/
 * 		http://jerome.jouvie.free.fr/
 */
public class LiveSpec extends SpectrumPanel implements BassExample
{
	/* display error messages */
	private final void error(String text) 
	{
		JOptionPane.showMessageDialog(LiveSpec.this,
				"<html><body>"+text+"<BR>(error code: "+BASS_ErrorGetCode()+")</body></html>");
	}
	private final void printfExit(String format, Object ...args)
	{
		String s = String.format(format, args);
		JOptionPane.showMessageDialog(this, s);
		stop();
		try {
			System.exit(0);
		} catch(SecurityException e) {};
	}

	private boolean init   = false;
	private boolean deinit = false;
	
	protected static final int SPECTRUM_WIDTH = 368;	//Display width
	protected static final int SPECTRUM_HEIGHT = 127;	//Height (changing requires palette adjustments too)

	private HRECORD chan;

	private RECORDPROC duffRecording = new RECORDPROC(){
		public boolean RECORDPROC(HRECORD handle, ByteBuffer buffer, int length, Pointer user)
		{
			return true;
		}
	};

	public static void main(String[] args)
	{
		new BassExampleFrame(new LiveSpec());
	}

	private void initBass()
	{
		/*
		 * NativeBass Init
		 */
		try
		{
			Init.loadLibraries(INIT_BASS);
		}
		catch(InitException e)
		{
			printfExit("NativeBass error! %s\n", e.getMessage());
			return;
		}
		
		/*
		 * Checking NativeBass version
		 */
		if(NATIVEBASS_LIBRARY_VERSION != NATIVEBASS_JAR_VERSION)
		{
			printfExit("Error!  NativeBass library version (%08x) is different to jar version (%08x)\n",
					NATIVEBASS_LIBRARY_VERSION, NATIVEBASS_JAR_VERSION);
			return;
		}
		
		/*==================================================*/
	    
		init = true;
	}

	public void run()
	{
		if(!init) return;
		
		// check the correct BASS was loaded
		if(((BASS_GetVersion() & 0xFFFF0000) >> 16) != BASSVERSION)
		{
			printfExit("An incorrect version of BASS.DLL was loaded");
			return;
		}
		
		// initialize BASS recording (default device)
		if(!BASS_RecordInit(-1))
		{
			error("Can't initialize device");
			stop();
		}
		// start recording (44100hz mono 16-bit)
		chan = BASS_RecordStart(44100, 1, 0, duffRecording, null);
		if(chan == null)
		{
			error("Can't start recording");
			stop();
		}

		//setup update timer (40hz)
		timer.start();
	}
	public void stop()
	{
		if(!init || deinit) return;
		deinit = true;
		
		timer.stop();
		BASS_RecordFree();
		BASS_Free();
	}

	public JPanel getPanel() { return this; }
	public String getTitle() { return "BASS \"live\" spectrum (click to toggle mode)"; }

				/* Graphical stuff */

	private Timer timer = new Timer(25, new ActionListener(){
		private int quietcount = 0;
		public void actionPerformed(ActionEvent e)
		{
			/* update the spectrum display */
			int handle = chan == null ? 0 : chan.asInt();
			update(handle);
			
			if((BASS_ChannelGetLevel(handle) & 0x0000FFFF) < 500)
			{
				// check if it's quiet
				quietcount++;
				if(quietcount > 40 && (quietcount & 16) != 0)
				{
					Graphics graphic = getGraphics(); if(graphic == null) return;
					graphic.setColor(new Color(0xffffff));
					graphic.drawString("make some noise!", 10, getHeight()/2);
				}
			}
			else
			{
				quietcount = 0;
			}
		}
	});
	public LiveSpec()
	{
		super(SPECTRUM_WIDTH, SPECTRUM_HEIGHT);
		initBass();
	}
}
