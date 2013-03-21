/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright © 2007 Jérôme JOUVIE (Jouvieje)
 *
 * Created on 02 jul. 2007
 * @version file v1.0.6
 * @author Jérôme JOUVIE (Jouvieje)
 *
 *
 * WANT TO CONTACT ME ?
 * E-mail :
 * 		jerome.jouvie@gmail.com
 * My web sites :
 * 		http://jerome.jouvie.free.fr/
 *
 *
 * INTRODUCTION
 * BASS is an audio library for use in Windows and Mac OSX software.
 * Its purpose is to provide developers with the most powerful and
 * efficient (yet easy to use), sample, stream (MP3, MP2, MP1, OGG, WAV, AIFF,
 * custom generated, and more via add-ons), MOD music (XM, IT, S3M, MOD, MTM, UMX),
 * MO3 music (MP3/OGG compressed MODs),
 * and recording functions. All in a tiny DLL, under 100KB* in size.
 *
 * BASS official web site :
 * 		http://www.un4seen.com/
 *
 *
 * GNU LESSER GENERAL PUBLIC LICENSE
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 */

package org.jouvieje.bass;

import org.jouvieje.bass.defines.INIT_MODES;
import org.jouvieje.bass.exceptions.InitException;
import org.jouvieje.libloader.LibLoader;

/**
 * Initialization of <code>NativeBass</code> / <code>BASS</code>.<BR>
 * You should call <code><a href="#loadLibraries()">Init.loadLibraries</a></code> before using <code>NativeBass</code> & <code>BASS</code>.
 */
public class Init
{
	private Init(){}

	/** Display errors when loading libraries */
	public static boolean DEBUG = false;
	private static boolean ENABLE_LIBLOADER = true;

	private static final String NATIVEBASS_SUPPORT = "jerome.jouvie@gmail.com";
	protected static boolean librariesLoaded = false;
	protected static int initMode = -1;

	/**
	 * This is the first thing to do before trying to use BASS.<BR>
	 * <BR>
	 * This method loads all requiered libraries.<BR>
	 * If all libraries are not loaded an exception occures. Then, you can decide what should
	 * be done.<BR>
	 * <BR>
	 * This is equivalent to the call <code>loadLibraries(INIT_MODES.INIT_DEFAULT)</code>.<BR>
	 * @throws InitException exception that occures when all libraries are not properly loaded.
	 * @see #loadLibraries(int)
	 * @see INIT_MODES
	 */
	public static void loadLibraries() throws InitException
	{
		loadLibraries(INIT_MODES.INIT_DEFAULT);
	}

	/**
	 * This is the first thing to do before trying to use BASS.<BR>
	 * <BR>
	 * This method loads all requiered libraries.<BR>
	 * If all libraries are not loaded an exception occures. Then, you can decide what should
	 * be done.<BR>
	 * @throws InitException exception that occures when all libraries are not properly loaded.
	 * @see INIT_MODES
	 */
	public static void loadLibraries(int mode) throws InitException
	{
		switch(mode)
		{
			case INIT_MODES.INIT_DEFAULT:
			case INIT_MODES.INIT_BASS:
				loadBass(true);
				librariesLoaded = true;
				initMode = INIT_MODES.INIT_BASS;
				break;
			case INIT_MODES.INIT_BASS_MINIMUM:
				loadBass(false);
				librariesLoaded = true;
				initMode = INIT_MODES.INIT_BASS_MINIMUM;
				break;
			default: throw new InitException("mode should be INIT_DEFAULT, INIT_BASS or INIT_BASS_MINIMUM !");
		}
	}

	private static boolean loadBass(boolean loadsCallbacks) throws InitException
	{
		boolean loaded = false;
		if(ENABLE_LIBLOADER)
		{
			try
			{
				LibLoader.DEBUG = DEBUG;
				LibLoader.loadLibraries();
				LibLoader.loadLibraryFromFullName("bass", "libbass.so");
				loaded = true;
				printlnDebug("BASS successfully loaded");
			}
			catch(UnsatisfiedLinkError e)
			{
				if(DEBUG)
					e.printStackTrace();
			}
		}
		if(!loaded)
		{
			//Load BASS library
			try
			{
				LibLoader.loadLibrary("bass");
				printlnDebug("BASS successfully loaded");
			}
			catch(UnsatisfiedLinkError e)
			{
				if(!LibLoader.loadMacLibrary("libbass.dylib"))	//Only if libbass.jnilib not found
				{
					if(DEBUG)
					{
						e.printStackTrace();
					}
					throw new InitException("Fail to load BASS library\n"+
							e.getClass().getName()+" : "+e.getMessage());
				}
				printlnDebug("BASS successfully loaded");
			}
		}

		//Load my library
		try
		{
			LibLoader.loadLibrary("NativeBass");
			printlnDebug("NativeBass successfully loaded");
		}
		catch(UnsatisfiedLinkError e)
		{
			if(DEBUG)
				e.printStackTrace();
			throw new InitException(e.getClass().getName()+" : "+e.getMessage());
		}

		if(loadsCallbacks)
			attachJavaVM();

		return true;
	}
	protected final static native void attachJavaVM() throws InitException;
	protected final static native int get_PLATFORM();

	/**
	 * You can use this method to know if all libraries needed for the <code>INIT_MODES</code> choosen.
	 * @return true if all libraries requiered are loaded.
	 */
	public static boolean isLibrariesLoaded()
	{
		return librariesLoaded && (initMode != -1);
	}

	/**
	 * Mode used for the initialization.
	 * @return <code>INIT_MODES</code> value specified to <code>loadLibraries</code>.<BR>
	 * -1 if the loading is not done.
	 * @see #loadLibraries(int)
	 * @see INIT_MODES
	 */
	public static int getInitMode()
	{
		return initMode;
	}

	private static void printlnDebug(String s)
	{
		if(DEBUG)
			java.lang.System.out.println(s);
	}
}
