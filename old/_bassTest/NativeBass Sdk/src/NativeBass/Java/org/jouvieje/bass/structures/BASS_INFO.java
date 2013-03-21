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

public class BASS_INFO extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_INFO</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_INFO object.
	 */
	public static BASS_INFO createView(Pointer pointer)
	{
		return new BASS_INFO(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>BASS_INFO</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_INFO obj = BASS_INFO.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_INFO create()
	{
		return new BASS_INFO(StructureJNI.BASS_INFO_new());
	}

	protected BASS_INFO(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_INFO</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_INFO obj = new BASS_INFO();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_INFO</code>, use the static "constructor" :
	 * <pre><code>  BASS_INFO obj = BASS_INFO.create();</code></pre>
	 * @see BASS_INFO#create()
	 */
	public BASS_INFO()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.BASS_INFO_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public int getFlags()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_flags(pointer);
		return javaResult;
	}
	public void setFlags(int flags)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_flags(pointer, flags);
	}

	/**
	 * 
	 */
	public int getHwSize()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_hwsize(pointer);
		return javaResult;
	}
	public void setHwSize(int hwSize)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_hwsize(pointer, hwSize);
	}

	/**
	 * 
	 */
	public int getHwFree()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_hwfree(pointer);
		return javaResult;
	}
	public void setHwFree(int hwFree)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_hwfree(pointer, hwFree);
	}

	/**
	 * 
	 */
	public int getFreeSample()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_freesam(pointer);
		return javaResult;
	}
	public void setFreeSample(int freeSample)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_freesam(pointer, freeSample);
	}

	/**
	 * 
	 */
	public int getFree3dSample()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_free3d(pointer);
		return javaResult;
	}
	public void setFree3dSample(int free3dSample)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_free3d(pointer, free3dSample);
	}

	/**
	 * 
	 */
	public int getMinRate()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_minrate(pointer);
		return javaResult;
	}
	public void setMinRate(int minRate)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_minrate(pointer, minRate);
	}

	/**
	 * 
	 */
	public int getMaxRate()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_maxrate(pointer);
		return javaResult;
	}
	public void setMaxRate(int maxRate)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_maxrate(pointer, maxRate);
	}

	/**
	 * 
	 */
	public boolean getEax()
	{
		if(pointer == 0) throw new NullPointerException();
		boolean javaResult = StructureJNI.BASS_INFO_get_eax(pointer);
		return javaResult;
	}
	public void setEax(boolean eax)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_eax(pointer, eax);
	}

	/**
	 * 
	 */
	public int getMinBuffer()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_minbuf(pointer);
		return javaResult;
	}
	public void setMinBuffer(int minBuffer)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_minbuf(pointer, minBuffer);
	}

	/**
	 * 
	 */
	public int getDxVersion()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_dsver(pointer);
		return javaResult;
	}
	public void setDxVersion(int dxVersion)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_dsver(pointer, dxVersion);
	}

	/**
	 * 
	 */
	public int getLatency()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_latency(pointer);
		return javaResult;
	}
	public void setLatency(int latency)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_latency(pointer, latency);
	}

	/**
	 * 
	 */
	public int getInitFlags()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_initflags(pointer);
		return javaResult;
	}
	public void setInitFlags(int initFlags)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_initflags(pointer, initFlags);
	}

	/**
	 * 
	 */
	public int getSpeakers()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_speakers(pointer);
		return javaResult;
	}
	public void setSpeakers(int speakers)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_speakers(pointer, speakers);
	}

	/**
	 * 
	 */
	public int getFreq()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_INFO_get_freq(pointer);
		return javaResult;
	}
	public void setFreq(int freq)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_INFO_set_freq(pointer, freq);
	}

}