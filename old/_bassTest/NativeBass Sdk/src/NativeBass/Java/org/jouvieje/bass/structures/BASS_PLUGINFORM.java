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

public class BASS_PLUGINFORM extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>BASS_PLUGINFORM</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a BASS_PLUGINFORM object.
	 */
	public static BASS_PLUGINFORM createView(Pointer pointer)
	{
		return new BASS_PLUGINFORM(Pointer.getPointer(pointer));
	}
	private static long SIZEOF_BASS_PLUGINFORM = -1;
	/**
	 * Create and initialize a new <code>BASS_PLUGINFORM[]</code>.<br>
	 * @param length length of the array returned.
	 */
	public static BASS_PLUGINFORM[] create(int length)
	{
		if(length <= 0)
			 return null;
		
		long first = StructureJNI.BASS_PLUGINFORM_newArray(length);
		
		if(SIZEOF_BASS_PLUGINFORM == -1)
			SIZEOF_BASS_PLUGINFORM = StructureJNI.BASS_PLUGINFORM_SIZEOF();
		
		BASS_PLUGINFORM[] array = new BASS_PLUGINFORM[length];
		for(int i = 0; i < length; i++)
			array[i] = new BASS_PLUGINFORM(first + i * SIZEOF_BASS_PLUGINFORM);
		
		return array;
	}

	/**
	 * Create a new <code>BASS_PLUGINFORM</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  BASS_PLUGINFORM obj = BASS_PLUGINFORM.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static BASS_PLUGINFORM create()
	{
		return new BASS_PLUGINFORM(StructureJNI.BASS_PLUGINFORM_new());
	}

	protected BASS_PLUGINFORM(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>BASS_PLUGINFORM</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  BASS_PLUGINFORM obj = new BASS_PLUGINFORM();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>BASS_PLUGINFORM</code>, use the static "constructor" :
	 * <pre><code>  BASS_PLUGINFORM obj = BASS_PLUGINFORM.create();</code></pre>
	 * @see BASS_PLUGINFORM#create()
	 */
	public BASS_PLUGINFORM()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.BASS_PLUGINFORM_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public int getChannelType()
	{
		if(pointer == 0) throw new NullPointerException();
		int javaResult = StructureJNI.BASS_PLUGINFORM_get_ctype(pointer);
		return javaResult;
	}
	public void setChannelType(int channelType)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_PLUGINFORM_set_ctype(pointer, channelType);
	}

	/**
	 * 
	 */
	public String getName()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.BASS_PLUGINFORM_get_name(pointer);
		return javaResult;
	}
	public void setName(String name)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_PLUGINFORM_set_name(pointer, name == null ? null : name.getBytes());
	}

	/**
	 * 
	 */
	public String getExts()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.BASS_PLUGINFORM_get_exts(pointer);
		return javaResult;
	}
	public void setExts(String exts)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.BASS_PLUGINFORM_set_exts(pointer, exts == null ? null : exts.getBytes());
	}

}