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

package org.jouvieje.bass.structures;

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

public class BASS_DX8_DISTORTION extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_DX8_DISTORTION</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_DX8_DISTORTION object.
	 */
	public static BASS_DX8_DISTORTION createView(Pointer pointer)
	{
		return new BASS_DX8_DISTORTION(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>BASS_DX8_DISTORTION</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_DX8_DISTORTION obj = BASS_DX8_DISTORTION.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_DX8_DISTORTION create()
	{
		return new BASS_DX8_DISTORTION(StructureJNI.BASS_DX8_DISTORTION_new());
	}

	protected BASS_DX8_DISTORTION(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_DX8_DISTORTION</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_DX8_DISTORTION obj = new BASS_DX8_DISTORTION();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_DX8_DISTORTION</code>, use the static "constructor" :
	 * <pre><code>  BASS_DX8_DISTORTION obj = BASS_DX8_DISTORTION.create();</code></pre>
	 * @see BASS_DX8_DISTORTION#create()
	 */
	public BASS_DX8_DISTORTION()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.BASS_DX8_DISTORTION_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public float getGain()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_DISTORTION_get_fGain(pointer);
		return javaResult;
	}
	public void setGain(float gain)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_DISTORTION_set_fGain(pointer, gain);
	}

	/**
	 * 
	 */
	public float getEdge()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_DISTORTION_get_fEdge(pointer);
		return javaResult;
	}
	public void setEdge(float edge)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_DISTORTION_set_fEdge(pointer, edge);
	}

	/**
	 * 
	 */
	public float getPostEQCenterFrequency()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_DISTORTION_get_fPostEQCenterFrequency(pointer);
		return javaResult;
	}
	public void setPostEQCenterFrequency(float postEQCenterFrequency)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_DISTORTION_set_fPostEQCenterFrequency(pointer, postEQCenterFrequency);
	}

	/**
	 * 
	 */
	public float getPostEQBandwidth()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_DISTORTION_get_fPostEQBandwidth(pointer);
		return javaResult;
	}
	public void setPostEQBandwidth(float postEQBandwidth)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_DISTORTION_set_fPostEQBandwidth(pointer, postEQBandwidth);
	}

	/**
	 * 
	 */
	public float getPreLowpassCutoff()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_DISTORTION_get_fPreLowpassCutoff(pointer);
		return javaResult;
	}
	public void setPreLowpassCutoff(float preLowpassCutoff)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_DISTORTION_set_fPreLowpassCutoff(pointer, preLowpassCutoff);
	}

}