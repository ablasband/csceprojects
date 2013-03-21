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

package org.jouvieje.bass.defines;

/**
 * [NAME] BASS_MUSIC
 */
public interface BASS_MUSIC
{
	/**  */
	public static final int BASS_MUSIC_FLOAT = BASS_SAMPLE.BASS_SAMPLE_FLOAT;
	/**  */
	public static final int BASS_MUSIC_MONO = BASS_SAMPLE.BASS_SAMPLE_MONO;
	/**  */
	public static final int BASS_MUSIC_LOOP = BASS_SAMPLE.BASS_SAMPLE_LOOP;
	/**  */
	public static final int BASS_MUSIC_3D = BASS_SAMPLE.BASS_SAMPLE_3D;
	/**  */
	public static final int BASS_MUSIC_FX = BASS_SAMPLE.BASS_SAMPLE_FX;
	/**  */
	public static final int BASS_MUSIC_AUTOFREE = BASS_STREAM.BASS_STREAM_AUTOFREE;
	/**  */
	public static final int BASS_MUSIC_DECODE = BASS_STREAM.BASS_STREAM_DECODE;
	/** calculate playback length */
	public static final int BASS_MUSIC_PRESCAN = BASS_STREAM.BASS_STREAM_PRESCAN;
	/** normal ramping */
	public static final int BASS_MUSIC_RAMP = 0x200;
	/** sensitive ramping */
	public static final int BASS_MUSIC_RAMPS = 0x400;
	/** surround sound */
	public static final int BASS_MUSIC_SURROUND = 0x800;
	/** surround sound (mode 2) */
	public static final int BASS_MUSIC_SURROUND2 = 0x1000;
	/** play .MOD as FastTracker 2 does */
	public static final int BASS_MUSIC_FT2MOD = 0x2000;
	/** play .MOD as ProTracker 1 does */
	public static final int BASS_MUSIC_PT1MOD = 0x4000;
	/** non-interpolated sample mixing */
	public static final int BASS_MUSIC_NONINTER = 0x10000;
	/** sinc interpolated sample mixing */
	public static final int BASS_MUSIC_SINCINTER = 0x800000;
	/** stop all notes when moving position */
	public static final int BASS_MUSIC_POSRESET = 0x8000;
	/** stop all notes and reset bmp/etc when moving position */
	public static final int BASS_MUSIC_POSRESETEX = 0x400000;
	/** stop the music on a backwards jump effect */
	public static final int BASS_MUSIC_STOPBACK = 0x80000;
	/** don't load the samples */
	public static final int BASS_MUSIC_NOSAMPLE = 0x100000;
}