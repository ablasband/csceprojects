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
import java.util.HashMap;

/**
 * DX8 effect types, use with BASS_ChannelSetFX [NAME] BASS_FX_DX8
 */
public class BASS_FX_DX8 implements Enumeration, Comparable
{
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_CHORUS = new BASS_FX_DX8("BASS_FX_DX8_CHORUS", EnumerationJNI.get_BASS_FX_DX8_CHORUS());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_COMPRESSOR = new BASS_FX_DX8("BASS_FX_DX8_COMPRESSOR", EnumerationJNI.get_BASS_FX_DX8_COMPRESSOR());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_DISTORTION = new BASS_FX_DX8("BASS_FX_DX8_DISTORTION", EnumerationJNI.get_BASS_FX_DX8_DISTORTION());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_ECHO = new BASS_FX_DX8("BASS_FX_DX8_ECHO", EnumerationJNI.get_BASS_FX_DX8_ECHO());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_FLANGER = new BASS_FX_DX8("BASS_FX_DX8_FLANGER", EnumerationJNI.get_BASS_FX_DX8_FLANGER());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_GARGLE = new BASS_FX_DX8("BASS_FX_DX8_GARGLE", EnumerationJNI.get_BASS_FX_DX8_GARGLE());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_I3DL2REVERB = new BASS_FX_DX8("BASS_FX_DX8_I3DL2REVERB", EnumerationJNI.get_BASS_FX_DX8_I3DL2REVERB());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_PARAMEQ = new BASS_FX_DX8("BASS_FX_DX8_PARAMEQ", EnumerationJNI.get_BASS_FX_DX8_PARAMEQ());
	/**  */
	public final static BASS_FX_DX8 BASS_FX_DX8_REVERB = new BASS_FX_DX8("BASS_FX_DX8_REVERB", EnumerationJNI.get_BASS_FX_DX8_REVERB());

	private final static HashMap VALUES = new HashMap(2*9);
	static
	{
		VALUES.put(new Integer(BASS_FX_DX8_CHORUS.asInt()), BASS_FX_DX8_CHORUS);
		VALUES.put(new Integer(BASS_FX_DX8_COMPRESSOR.asInt()), BASS_FX_DX8_COMPRESSOR);
		VALUES.put(new Integer(BASS_FX_DX8_DISTORTION.asInt()), BASS_FX_DX8_DISTORTION);
		VALUES.put(new Integer(BASS_FX_DX8_ECHO.asInt()), BASS_FX_DX8_ECHO);
		VALUES.put(new Integer(BASS_FX_DX8_FLANGER.asInt()), BASS_FX_DX8_FLANGER);
		VALUES.put(new Integer(BASS_FX_DX8_GARGLE.asInt()), BASS_FX_DX8_GARGLE);
		VALUES.put(new Integer(BASS_FX_DX8_I3DL2REVERB.asInt()), BASS_FX_DX8_I3DL2REVERB);
		VALUES.put(new Integer(BASS_FX_DX8_PARAMEQ.asInt()), BASS_FX_DX8_PARAMEQ);
		VALUES.put(new Integer(BASS_FX_DX8_REVERB.asInt()), BASS_FX_DX8_REVERB);
	}

	private final String name;
	private final int nativeValue;
	private BASS_FX_DX8(String name, int nativeValue)
	{
		this.name = name;
		this.nativeValue = nativeValue;
	}

	public int asInt()
	{
		return nativeValue;
	}
	public String toString()
	{
		return name;
	}
	public boolean equals(Object object)
	{
		if(object instanceof BASS_FX_DX8)
			return asInt() == ((BASS_FX_DX8)object).asInt();
		return false;
	}
	public int compareTo(Object object)
	{
		return asInt() - ((BASS_FX_DX8)object).asInt();
	}


	/**
	 * Retrieve a BASS_FX_DX8 enum field with his integer value
	 * @param nativeValue the integer value of the field to retrieve
	 * @return the BASS_FX_DX8 enum field that correspond to the integer value
	 */
	public static BASS_FX_DX8 get(int nativeValue)
	{
		return (BASS_FX_DX8)VALUES.get(new Integer(nativeValue));
	}

	/**
	 * Retrieve a BASS_FX_DX8 enum field from a Pointer
	 * @param pointer a pointer holding an BASS_FX_DX8 enum field
	 * @return the BASS_FX_DX8 enum field that correspond to the enum field in the pointer
	 */
	public static BASS_FX_DX8 get(Pointer pointer)
	{
		return get(pointer.asInt());
	}

	/**
	 * @return an <code>Iterator</code> over the elements in this enumeration.<BR>
	 * Can be cast to <code>Iterator<BASS_FX_DX8></code> in Java 1.5.
	 */
	public static java.util.Iterator iterator()
	{
		return new java.util.Iterator(){
			private java.util.Iterator i = VALUES.values().iterator();	//Wrapper of the HashMap iterator
			public boolean hasNext() { return i.hasNext(); }
			public Object next() { return i.next(); }
			public void remove() { throw new UnsupportedOperationException(); }
		};
	}
}