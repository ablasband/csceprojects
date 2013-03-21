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
 * BASS_ChannelGetTags types : what's returned [NAME] BASS_TAG
 */
public interface BASS_TAG
{
	/** ID3v1 tags : TAG_ID3 structure */
	public static final int BASS_TAG_ID3 = 0;
	/** ID3v2 tags : variable length block */
	public static final int BASS_TAG_ID3V2 = 1;
	/** OGG comments : series of null-terminated UTF-8 strings */
	public static final int BASS_TAG_OGG = 2;
	/** HTTP headers : series of null-terminated ANSI strings */
	public static final int BASS_TAG_HTTP = 3;
	/** ICY headers : series of null-terminated ANSI strings */
	public static final int BASS_TAG_ICY = 4;
	/** ICY metadata : ANSI string */
	public static final int BASS_TAG_META = 5;
	/** OGG encoder : UTF-8 string */
	public static final int BASS_TAG_VENDOR = 9;
	/** Lyric3v2 tag : ASCII string */
	public static final int BASS_TAG_LYRICS3 = 10;
	/** RIFF "INFO" tags : series of null-terminated ANSI strings */
	public static final int BASS_TAG_RIFF_INFO = 0x100;
	/** RIFF/BWF Broadcast Audio Extension tags : TAG_BEXT structure */
	public static final int BASS_TAG_RIFF_BEXT = 0x101;
	/** MOD music name : ANSI string */
	public static final int BASS_TAG_MUSIC_NAME = 0x10000;
	/** MOD message : ANSI string */
	public static final int BASS_TAG_MUSIC_MESSAGE = 0x10001;
	/** + instrument #, MOD instrument name : ANSI string */
	public static final int BASS_TAG_MUSIC_INST = 0x10100;
	/** + sample #, MOD sample name : ANSI string */
	public static final int BASS_TAG_MUSIC_SAMPLE = 0x10300;
}