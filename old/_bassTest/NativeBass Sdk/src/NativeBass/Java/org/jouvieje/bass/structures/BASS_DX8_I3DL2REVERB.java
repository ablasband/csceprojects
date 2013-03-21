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

public class BASS_DX8_I3DL2REVERB extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_DX8_I3DL2REVERB</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_DX8_I3DL2REVERB object.
	 */
	public static BASS_DX8_I3DL2REVERB createView(Pointer pointer)
	{
		return new BASS_DX8_I3DL2REVERB(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>BASS_DX8_I3DL2REVERB</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_DX8_I3DL2REVERB obj = BASS_DX8_I3DL2REVERB.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_DX8_I3DL2REVERB create()
	{
		return new BASS_DX8_I3DL2REVERB(StructureJNI.BASS_DX8_I3DL2REVERB_new());
	}

	protected BASS_DX8_I3DL2REVERB(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_DX8_I3DL2REVERB</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_DX8_I3DL2REVERB obj = new BASS_DX8_I3DL2REVERB();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_DX8_I3DL2REVERB</code>, use the static "constructor" :
	 * <pre><code>  BASS_DX8_I3DL2REVERB obj = BASS_DX8_I3DL2REVERB.create();</code></pre>
	 * @see BASS_DX8_I3DL2REVERB#create()
	 */
	public BASS_DX8_I3DL2REVERB()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.BASS_DX8_I3DL2REVERB_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public int getRoom()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_lRoom(pointer);
		return javaResult;
	}
	public void setRoom(int room)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_lRoom(pointer, room);
	}

	/**
	 * 
	 */
	public int getRoomHF()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_lRoomHF(pointer);
		return javaResult;
	}
	public void setRoomHF(int roomHF)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_lRoomHF(pointer, roomHF);
	}

	/**
	 * 
	 */
	public float getRoomRolloffFactor()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flRoomRolloffFactor(pointer);
		return javaResult;
	}
	public void setRoomRolloffFactor(float roomRolloffFactor)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flRoomRolloffFactor(pointer, roomRolloffFactor);
	}

	/**
	 * 
	 */
	public float getDecayTime()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flDecayTime(pointer);
		return javaResult;
	}
	public void setDecayTime(float decayTime)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flDecayTime(pointer, decayTime);
	}

	/**
	 * 
	 */
	public float getDecayHFRatio()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flDecayHFRatio(pointer);
		return javaResult;
	}
	public void setDecayHFRatio(float decayHFRatio)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flDecayHFRatio(pointer, decayHFRatio);
	}

	/**
	 * 
	 */
	public int getReflections()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_lReflections(pointer);
		return javaResult;
	}
	public void setReflections(int reflections)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_lReflections(pointer, reflections);
	}

	/**
	 * 
	 */
	public float getReflectionsDelay()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flReflectionsDelay(pointer);
		return javaResult;
	}
	public void setReflectionsDelay(float reflectionsDelay)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flReflectionsDelay(pointer, reflectionsDelay);
	}

	/**
	 * 
	 */
	public int getReverb()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_lReverb(pointer);
		return javaResult;
	}
	public void setReverb(int reverb)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_lReverb(pointer, reverb);
	}

	/**
	 * 
	 */
	public float getReverbDelay()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flReverbDelay(pointer);
		return javaResult;
	}
	public void setReverbDelay(float reverbDelay)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flReverbDelay(pointer, reverbDelay);
	}

	/**
	 * 
	 */
	public float getDiffusion()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flDiffusion(pointer);
		return javaResult;
	}
	public void setDiffusion(float diffusion)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flDiffusion(pointer, diffusion);
	}

	/**
	 * 
	 */
	public float getDensity()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flDensity(pointer);
		return javaResult;
	}
	public void setDensity(float density)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flDensity(pointer, density);
	}

	/**
	 * 
	 */
	public float getHFReference()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_I3DL2REVERB_get_flHFReference(pointer);
		return javaResult;
	}
	public void setHFReference(float HFReference)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_I3DL2REVERB_set_flHFReference(pointer, HFReference);
	}

}