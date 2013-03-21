// BASS Simple Console WAVE Writer, copyright (c) 2002-2006 Ian Luck.

package org.jouvieje.bass.examples;

import static org.jouvieje.bass.Bass.*;
import static org.jouvieje.bass.defines.BASS_ACTIVE.BASS_ACTIVE_PLAYING;
import static org.jouvieje.bass.defines.BASS_ATTRIB.BASS_ATTRIB_MUSIC_VOL_CHAN;
import static org.jouvieje.bass.defines.BASS_CONFIG.BASS_CONFIG_UPDATEPERIOD;
import static org.jouvieje.bass.defines.BASS_MUSIC.BASS_MUSIC_DECODE;
import static org.jouvieje.bass.defines.BASS_MUSIC.BASS_MUSIC_PRESCAN;
import static org.jouvieje.bass.defines.BASS_MUSIC.BASS_MUSIC_RAMP;
import static org.jouvieje.bass.defines.BASS_POS.BASS_POS_BYTE;
import static org.jouvieje.bass.defines.BASS_POS.BASS_POS_MUSIC_ORDER;
import static org.jouvieje.bass.defines.BASS_SAMPLE.BASS_SAMPLE_8BITS;
import static org.jouvieje.bass.defines.BASS_STREAM.BASS_STREAM_BLOCK;
import static org.jouvieje.bass.defines.BASS_STREAM.BASS_STREAM_DECODE;
import static org.jouvieje.bass.defines.BASS_TAG.BASS_TAG_MUSIC_NAME;
import static org.jouvieje.bass.defines.INIT_MODES.INIT_BASS;
import static org.jouvieje.bass.defines.VERSIONS.BASSVERSION;
import static org.jouvieje.bass.defines.VERSIONS.NATIVEBASS_JAR_VERSION;
import static org.jouvieje.bass.defines.VERSIONS.NATIVEBASS_LIBRARY_VERSION;
import static org.jouvieje.bass.examples.util.Device.forceFrequency;
import static org.jouvieje.bass.misc.BufferUtils.newByteBuffer;
import static org.jouvieje.bass.misc.BufferUtils.SIZEOF_SHORT;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

import javax.swing.JPanel;

import org.jouvieje.bass.Init;
import org.jouvieje.bass.examples.util.BassExampleFrame;
import org.jouvieje.bass.examples.util.ConsoleGUI;
import org.jouvieje.bass.exceptions.InitException;
import org.jouvieje.bass.misc.FileWriterUtils;
import org.jouvieje.bass.structures.BASS_CHANNELINFO;
import org.jouvieje.bass.structures.HMUSIC;
import org.jouvieje.bass.structures.HSTREAM;
import org.jouvieje.fileformat.wav.DataChunk;
import org.jouvieje.fileformat.wav.FmtChunk;
import org.jouvieje.fileformat.wav.RiffChunk;
import org.jouvieje.fileformat.wav.WavHeader;

import Tool.es;

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
public class WriteWav extends ConsoleGUI
{
	public static void main(String[] args)
	{
		new BassExampleFrame(new WriteWav());
	}
	
	private boolean init   = false;
	private boolean deinit = false;
	
	public WriteWav()
	{
		super();
		initBass();
		initialize();
	}
	
	public JPanel getPanel() { return this; }
	public String getTitle() { return "BASS console WAV writer"; }
	
	public void initBass()
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
		
		HSTREAM stream = null;
		HMUSIC  music = null;
		int chan;
		long pos;
		int p = 0;
		
		printf("BASS WAVE writer example : MOD/MPx/OGG -> BASS.WAV\n"+
			"--------------------------------------------------\n");

		// check the correct BASS was loaded
		if(((BASS_GetVersion() & 0xFFFF0000) >> 16) != BASSVERSION)
		{
			printfExit("An incorrect version of BASS.DLL was loaded");
			return;
		}
		
		printf( "BASS WAVE writer example : MOD/MPx/OGG -> BASS.WAV\n"+
				"--------------------------------------------------\n"+
				"Usage:    WriteWav <file>\n"+
				"Examples: WriteWav music.mp3");
		
		resetInput();
		setInput("music.mp3");
		while(!keyHit()) {
			Thread.yield();
		}
		String url = getInput();
		
		/* not playing anything, so don't need an update thread */
		BASS_SetConfig(BASS_CONFIG_UPDATEPERIOD, 0);

		/* setup output - "no sound" device, 44100hz, stereo, 16 bits */
		if(!BASS_Init(0, forceFrequency(44100), 0, null, null)) {
			printExit("Can't initialize device");
			return;
		}

		/* try streaming the file/url */
		if (   (stream = BASS_StreamCreateFile(false, url, 0, 0, BASS_STREAM_DECODE)) != null
			|| (stream = BASS_StreamCreateURL(url, 0, BASS_STREAM_DECODE | BASS_STREAM_BLOCK, null, null)) != null)
		{
			chan = stream.asInt();
			pos = (int)BASS_ChannelGetLength(chan, BASS_POS_BYTE);
			printf("streaming file [%d bytes]",pos);
		}
		else
		{
			/* try loading the MOD (with sensitive ramping, and calculate the duration) */
			if((music = BASS_MusicLoad(false, url, 0, 0, BASS_MUSIC_DECODE | BASS_MUSIC_RAMP | BASS_MUSIC_PRESCAN, 0)) == null) {
				/* not a MOD either */
				printExit("Can't play the file");
				return;
			}
			
			chan = music.asInt();
			
			for(p = 0; BASS_ChannelGetAttribute(chan, BASS_ATTRIB_MUSIC_VOL_CHAN+p, null); p++);	//count channels
			
			printf("MOD music \"%s\" [%u chans, %u orders]",
				BASS_ChannelGetTags(chan, BASS_TAG_MUSIC_NAME), p, BASS_ChannelGetLength(chan, BASS_POS_MUSIC_ORDER));
			pos = (int)BASS_ChannelGetLength(chan, BASS_POS_BYTE);
		}

		/* display the time length */
		if(pos != 0)
		{
			p = (int)BASS_ChannelBytes2Seconds(chan, pos);
			printf(" %d:%02d\n", p/60, p%60);
		}
		else /* no time length available */
			printf("\n");

		RandomAccessFile os = null;
		try
		{
			os = new RandomAccessFile("BASS.WAV", "rw");
		}
		catch(FileNotFoundException e)
		{
			printExit("Can't create file ("+e.getMessage()+")");
			return;
		}
		
		printf("writing to BASS.WAV file... press a key to stop\n");
		
		/* write WAV header */
		BASS_CHANNELINFO info = BASS_CHANNELINFO.create();
		BASS_ChannelGetInfo(chan, info);
		
		//Fill the WAVE header
		int lenbytes = 0;	//Length unknown
		int channels = info.getChannels();
		int rate = info.getFreq();
		int bits = ((info.getFlags() & BASS_SAMPLE_8BITS) != 0) ? 8 : 16;
		WavHeader wavHeader = new WavHeader(
				new RiffChunk(new byte[]{'R','I','F','F'},
						FmtChunk.SIZEOF_FMT_CHUNK + RiffChunk.SIZEOF_RIFF_CHUNK+lenbytes),
						new byte[]{'W','A','V','E'});
		FmtChunk fmtChunk = new FmtChunk(
				new RiffChunk(new byte[]{'f','m','t',' '},
						FmtChunk.SIZEOF_FMT_CHUNK - RiffChunk.SIZEOF_RIFF_CHUNK),
						(short)1, (short)channels,
						rate, rate*channels*bits/8,
						(short)(1*channels*bits/8), (short)bits);
		DataChunk dataChunk = new DataChunk(new RiffChunk(new byte[]{'d','a','t','a'}, lenbytes));
		
		info.release();

		Thread keyHit = new Thread(){
			public void run()
			{
				es.readChar();
			}
		};
		keyHit.start();
		
		//Write in the wav file
		try
		{
			WavHeader.writeWavHeader(os, wavHeader);
			FmtChunk.writeFmtChunk(os, fmtChunk);
			DataChunk.writeDataChunk(os, dataChunk);
			
			FileChannel fileChannel = os.getChannel();
			ByteBuffer buf = newByteBuffer(20000 * SIZEOF_SHORT);
			while(keyHit.isAlive() && BASS_ChannelIsActive(chan) == BASS_ACTIVE_PLAYING)
			{
				int c = BASS_ChannelGetData(chan, buf, buf.capacity());
//	#ifdef _BIG_ENDIAN
//			if (!(info.flags&BASS_SAMPLE_8BITS)) // swap 16-bit byte order
//				for (p=0;p<c/2;p++) buf[p]=le_16(buf[p]);
//	#endif
				
				fileChannel.write((ByteBuffer)(buf.duplicate().limit(c)));
				buf.rewind();
				
				pos = (int)BASS_ChannelGetPosition(chan, BASS_POS_BYTE);

				printfr("pos %d (%d)", pos, c);
			}
			
			/* complete WAV header */
			int size = (int)os.length();
			os.seek(4);
			FileWriterUtils.writeInt(os, size-8);
			os.seek(40);
			FileWriterUtils.writeInt(os, size-44);
			
			fileChannel.close();
			os.close();
		}
		catch(IOException e)
		{
			printExit("Error while writing ("+e.getMessage()+")");
			return;
		}

		stop();
	}
	
	public void stop()
	{
		if(!init || deinit) return;
		deinit = true;
		
		print("\n");
		
		BASS_Free();
		
		printExit("Shutdown\n");
	}
}