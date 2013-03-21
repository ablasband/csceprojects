/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright © 2007-2009 Jérôme JOUVIE (Jouvieje)
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

package org.jouvieje.bass.enumerations;

import org.jouvieje.bass.*;
import org.jouvieje.bass.exceptions.*;
import org.jouvieje.bass.callbacks.*;
import org.jouvieje.bass.*;
import org.jouvieje.bass.defines.*;
import org.jouvieje.bass.enumerations.*;
import org.jouvieje.bass.structures.*;
import java.nio.*;
import org.jouvieje.bass.*;
import org.jouvieje.bass.enumerations.*;
import org.jouvieje.bass.structures.*;
import org.jouvieje.bass.misc.*;

class EnumerationJNI
{
	static
	{
		if(!Init.isLibrariesLoaded())
		{
			throw new RuntimeException("Libraries not loaded ! Use Init.loadLibraries() before using NativeBass.");
		}
	}

				/* EAX_ENVIRONMENT */

	protected final static native int get_EAX_ENVIRONMENT_GENERIC();
	protected final static native int get_EAX_ENVIRONMENT_PADDEDCELL();
	protected final static native int get_EAX_ENVIRONMENT_ROOM();
	protected final static native int get_EAX_ENVIRONMENT_BATHROOM();
	protected final static native int get_EAX_ENVIRONMENT_LIVINGROOM();
	protected final static native int get_EAX_ENVIRONMENT_STONEROOM();
	protected final static native int get_EAX_ENVIRONMENT_AUDITORIUM();
	protected final static native int get_EAX_ENVIRONMENT_CONCERTHALL();
	protected final static native int get_EAX_ENVIRONMENT_CAVE();
	protected final static native int get_EAX_ENVIRONMENT_ARENA();
	protected final static native int get_EAX_ENVIRONMENT_HANGAR();
	protected final static native int get_EAX_ENVIRONMENT_CARPETEDHALLWAY();
	protected final static native int get_EAX_ENVIRONMENT_HALLWAY();
	protected final static native int get_EAX_ENVIRONMENT_STONECORRIDOR();
	protected final static native int get_EAX_ENVIRONMENT_ALLEY();
	protected final static native int get_EAX_ENVIRONMENT_FOREST();
	protected final static native int get_EAX_ENVIRONMENT_CITY();
	protected final static native int get_EAX_ENVIRONMENT_MOUNTAINS();
	protected final static native int get_EAX_ENVIRONMENT_QUARRY();
	protected final static native int get_EAX_ENVIRONMENT_PLAIN();
	protected final static native int get_EAX_ENVIRONMENT_PARKINGLOT();
	protected final static native int get_EAX_ENVIRONMENT_SEWERPIPE();
	protected final static native int get_EAX_ENVIRONMENT_UNDERWATER();
	protected final static native int get_EAX_ENVIRONMENT_DRUGGED();
	protected final static native int get_EAX_ENVIRONMENT_DIZZY();
	protected final static native int get_EAX_ENVIRONMENT_PSYCHOTIC();
	protected final static native int get_EAX_ENVIRONMENT_COUNT();

				/* STREAMPROC_SPECIAL */


				/* BASS_FX_DX8 */

	protected final static native int get_BASS_FX_DX8_CHORUS();
	protected final static native int get_BASS_FX_DX8_COMPRESSOR();
	protected final static native int get_BASS_FX_DX8_DISTORTION();
	protected final static native int get_BASS_FX_DX8_ECHO();
	protected final static native int get_BASS_FX_DX8_FLANGER();
	protected final static native int get_BASS_FX_DX8_GARGLE();
	protected final static native int get_BASS_FX_DX8_I3DL2REVERB();
	protected final static native int get_BASS_FX_DX8_PARAMEQ();
	protected final static native int get_BASS_FX_DX8_REVERB();

}