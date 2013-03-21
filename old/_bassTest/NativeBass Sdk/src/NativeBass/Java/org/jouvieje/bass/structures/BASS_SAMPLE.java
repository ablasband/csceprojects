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

/**
 * Sample info structure
 */
public class BASS_SAMPLE extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_SAMPLE</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_SAMPLE object.
	 */
	public static BASS_SAMPLE createView(Pointer pointer)
	{
		return new BASS_SAMPLE(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>BASS_SAMPLE</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_SAMPLE obj = BASS_SAMPLE.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_SAMPLE create()
	{
		return new BASS_SAMPLE(StructureJNI.BASS_SAMPLE_new());
	}

	protected BASS_SAMPLE(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_SAMPLE</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_SAMPLE obj = new BASS_SAMPLE();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_SAMPLE</code>, use the static "constructor" :
	 * <pre><code>  BASS_SAMPLE obj = BASS_SAMPLE.create();</code></pre>
	 * @see BASS_SAMPLE#create()
	 */
	public BASS_SAMPLE()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.BASS_SAMPLE_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public int getFreq()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_freq(pointer);
		return javaResult;
	}
	public void setFreq(int freq)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_freq(pointer, freq);
	}

	/**
	 * 
	 */
	public float getVolume()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_SAMPLE_get_volume(pointer);
		return javaResult;
	}
	public void setVolume(float volume)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_volume(pointer, volume);
	}

	/**
	 * 
	 */
	public float getPan()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_SAMPLE_get_pan(pointer);
		return javaResult;
	}
	public void setPan(float pan)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_pan(pointer, pan);
	}

	/**
	 * 
	 */
	public int getFlags()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_flags(pointer);
		return javaResult;
	}
	public void setFlags(int flags)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_flags(pointer, flags);
	}

	/**
	 * 
	 */
	public int getLength()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_length(pointer);
		return javaResult;
	}
	public void setLength(int length)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_length(pointer, length);
	}

	/**
	 * 
	 */
	public int getMax()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_max(pointer);
		return javaResult;
	}
	public void setMax(int max)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_max(pointer, max);
	}

	/**
	 * 
	 */
	public int getOrigRes()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_origres(pointer);
		return javaResult;
	}
	public void setOrigRes(int origRes)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_origres(pointer, origRes);
	}

	/**
	 * 
	 */
	public int getChannels()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_chans(pointer);
		return javaResult;
	}
	public void setChannels(int channels)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_chans(pointer, channels);
	}

	/**
	 * 
	 */
	public int getMinGap()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_mingap(pointer);
		return javaResult;
	}
	public void setMinGap(int minGap)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_mingap(pointer, minGap);
	}

	/**
	 * 
	 */
	public int getMode3d()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_mode3d(pointer);
		return javaResult;
	}
	public void setMode3d(int mode3d)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_mode3d(pointer, mode3d);
	}

	/**
	 * 
	 */
	public float getMinDist()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_SAMPLE_get_mindist(pointer);
		return javaResult;
	}
	public void setMinDist(float minDist)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_mindist(pointer, minDist);
	}

	/**
	 * 
	 */
	public float getMaxDist()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_SAMPLE_get_maxdist(pointer);
		return javaResult;
	}
	public void setMaxDist(float maxDist)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_maxdist(pointer, maxDist);
	}

	/**
	 * 
	 */
	public int getInAngle()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_iangle(pointer);
		return javaResult;
	}
	public void setInAngle(int inAngle)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_iangle(pointer, inAngle);
	}

	/**
	 * 
	 */
	public int getOutAngle()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_oangle(pointer);
		return javaResult;
	}
	public void setOutAngle(int outAngle)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_oangle(pointer, outAngle);
	}

	/**
	 * 
	 */
	public float getOutVol()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_SAMPLE_get_outvol(pointer);
		return javaResult;
	}
	public void setOutVol(float outVol)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_outvol(pointer, outVol);
	}

	/**
	 * 
	 */
	public int getVAM()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_vam(pointer);
		return javaResult;
	}
	public void setVAM(int VAM)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_vam(pointer, VAM);
	}

	/**
	 * 
	 */
	public int getPriority()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_SAMPLE_get_priority(pointer);
		return javaResult;
	}
	public void setPriority(int priority)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_SAMPLE_set_priority(pointer, priority);
	}

}