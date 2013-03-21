/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright � 2007-2009 J�r�me JOUVIE (Jouvieje)
 *
 * Created on 02 jul. 2007
 * @version file v1.0.6
 * @author J�r�me JOUVIE (Jouvieje)
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

package org.jouvieje.bass.defines;

/**
 * BASS_ChannelGetData flags [NAME] BASS_DATA
 */
public interface BASS_DATA
{
	/** query how much data is buffered */
	public static final int BASS_DATA_AVAILABLE = 0;
	/** flag: return floating-point sample data */
	public static final int BASS_DATA_FLOAT = 0x40000000;
	/** 256 sample FFT */
	public static final int BASS_DATA_FFT256 = 0x80000000;
	/** 512 FFT */
	public static final int BASS_DATA_FFT512 = 0x80000001;
	/** 1024 FFT */
	public static final int BASS_DATA_FFT1024 = 0x80000002;
	/** 2048 FFT */
	public static final int BASS_DATA_FFT2048 = 0x80000003;
	/** 4096 FFT */
	public static final int BASS_DATA_FFT4096 = 0x80000004;
	/** 8192 FFT */
	public static final int BASS_DATA_FFT8192 = 0x80000005;
	/** FFT flag: FFT for each channel, else all combined */
	public static final int BASS_DATA_FFT_INDIVIDUAL = 0x10;
	/** FFT flag: no Hanning window */
	public static final int BASS_DATA_FFT_NOWINDOW = 0x20;
}