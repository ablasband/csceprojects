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

public class BASS_DX8_REVERB extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_DX8_REVERB</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_DX8_REVERB object.
	 */
	public static BASS_DX8_REVERB createView(Pointer pointer)
	{
		return new BASS_DX8_REVERB(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>BASS_DX8_REVERB</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_DX8_REVERB obj = BASS_DX8_REVERB.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_DX8_REVERB create()
	{
		return new BASS_DX8_REVERB(StructureJNI.BASS_DX8_REVERB_new());
	}

	protected BASS_DX8_REVERB(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_DX8_REVERB</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_DX8_REVERB obj = new BASS_DX8_REVERB();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_DX8_REVERB</code>, use the static "constructor" :
	 * <pre><code>  BASS_DX8_REVERB obj = BASS_DX8_REVERB.create();</code></pre>
	 * @see BASS_DX8_REVERB#create()
	 */
	public BASS_DX8_REVERB()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.BASS_DX8_REVERB_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public float getInGain()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_REVERB_get_fInGain(pointer);
		return javaResult;
	}
	public void setInGain(float inGain)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_REVERB_set_fInGain(pointer, inGain);
	}

	/**
	 * 
	 */
	public float getReverbMix()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_REVERB_get_fReverbMix(pointer);
		return javaResult;
	}
	public void setReverbMix(float reverbMix)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_REVERB_set_fReverbMix(pointer, reverbMix);
	}

	/**
	 * 
	 */
	public float getReverbTime()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_REVERB_get_fReverbTime(pointer);
		return javaResult;
	}
	public void setReverbTime(float reverbTime)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_REVERB_set_fReverbTime(pointer, reverbTime);
	}

	/**
	 * 
	 */
	public float getHighFreqRTRatio()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_REVERB_get_fHighFreqRTRatio(pointer);
		return javaResult;
	}
	public void setHighFreqRTRatio(float highFreqRTRatio)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_REVERB_set_fHighFreqRTRatio(pointer, highFreqRTRatio);
	}

}