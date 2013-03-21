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

public class HCHANNEL extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>HCHANNEL</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a HCHANNEL object.
	 */
	public static HCHANNEL createView(Pointer pointer)
	{
		return new HCHANNEL(Pointer.getPointer(pointer));
	}
	private static long SIZEOF_HCHANNEL = -1;
	/**
	 * Create and initialize a new <code>HCHANNEL[]</code>.<br>
	 * @param length length of the array returned.
	 */
	public static HCHANNEL[] create(int length)
	{
		if(length <= 0)
			 return null;
		
		long first = StructureJNI.HCHANNEL_newArray(length);
		
		if(SIZEOF_HCHANNEL == -1)
			SIZEOF_HCHANNEL = StructureJNI.HCHANNEL_SIZEOF();
		
		HCHANNEL[] array = new HCHANNEL[length];
		for(int i = 0; i < length; i++)
			array[i] = new HCHANNEL(first + i * SIZEOF_HCHANNEL);
		
		return array;
	}

	protected HCHANNEL(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>HCHANNEL</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  HCHANNEL obj = new HCHANNEL();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>HCHANNEL</code>, use the static "constructor" :
	 * <pre><code>  HCHANNEL obj = HCHANNEL.create();</code></pre>
	 */
	public HCHANNEL()
	{
		super();
	}

	public void release()
	{
		pointer = 0;
	}

}