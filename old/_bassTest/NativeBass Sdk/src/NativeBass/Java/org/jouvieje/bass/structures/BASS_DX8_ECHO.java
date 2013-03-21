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

public class BASS_DX8_ECHO extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_DX8_ECHO</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_DX8_ECHO object.
	 */
	public static BASS_DX8_ECHO createView(Pointer pointer)
	{
		return new BASS_DX8_ECHO(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>BASS_DX8_ECHO</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_DX8_ECHO obj = BASS_DX8_ECHO.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_DX8_ECHO create()
	{
		return new BASS_DX8_ECHO(StructureJNI.BASS_DX8_ECHO_new());
	}

	protected BASS_DX8_ECHO(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_DX8_ECHO</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_DX8_ECHO obj = new BASS_DX8_ECHO();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_DX8_ECHO</code>, use the static "constructor" :
	 * <pre><code>  BASS_DX8_ECHO obj = BASS_DX8_ECHO.create();</code></pre>
	 * @see BASS_DX8_ECHO#create()
	 */
	public BASS_DX8_ECHO()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.BASS_DX8_ECHO_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public float getWetDryMix()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_ECHO_get_fWetDryMix(pointer);
		return javaResult;
	}
	public void setWetDryMix(float wetDryMix)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_ECHO_set_fWetDryMix(pointer, wetDryMix);
	}

	/**
	 * 
	 */
	public float getFeedback()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_ECHO_get_fFeedback(pointer);
		return javaResult;
	}
	public void setFeedback(float feedback)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_ECHO_set_fFeedback(pointer, feedback);
	}

	/**
	 * 
	 */
	public float getLeftDelay()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_ECHO_get_fLeftDelay(pointer);
		return javaResult;
	}
	public void setLeftDelay(float leftDelay)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_ECHO_set_fLeftDelay(pointer, leftDelay);
	}

	/**
	 * 
	 */
	public float getRightDelay()
	{
		if(pointer == 0) throw new NullPointerException();
		float javaResult = StructureJNI.BASS_DX8_ECHO_get_fRightDelay(pointer);
		return javaResult;
	}
	public void setRightDelay(float rightDelay)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_ECHO_set_fRightDelay(pointer, rightDelay);
	}

	/**
	 * 
	 */
	public boolean getPanDelay()
	{
		if(pointer == 0) throw new NullPointerException();
		boolean javaResult = StructureJNI.BASS_DX8_ECHO_get_lPanDelay(pointer);
		return javaResult;
	}
	public void setPanDelay(boolean panDelay)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_DX8_ECHO_set_lPanDelay(pointer, panDelay);
	}

}