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
 * BWF Broadcast Audio Extension tag structure
 */
public class TAG_BEXT extends Pointer
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>TAG_BEXT</code> object.<br>
	 * This view is valid only if the memory holded by the <code>Pointer</code> holds a TAG_BEXT object.
	 */
	public static TAG_BEXT createView(Pointer pointer)
	{
		return new TAG_BEXT(Pointer.getPointer(pointer));
	}
	/**
	 * Create a new <code>TAG_BEXT</code>.<br>
	 * The call <code>isNull()</code> on the object created will return false.<br>
	 * <pre><code>  TAG_BEXT obj = TAG_BEXT.create();
	 *  (obj == null) <=> obj.isNull() <=> false
	 * </code></pre>
	 */
	public static TAG_BEXT create()
	{
		return new TAG_BEXT(StructureJNI.TAG_BEXT_new());
	}

	protected TAG_BEXT(long pointer)
	{
		super(pointer);
	}

	/**
	 * Create an object that holds a null <code>TAG_BEXT</code>.<br>
	 * The call <code>isNull()</code> on the object created will returns true.<br>
	 * <pre><code>  TAG_BEXT obj = new TAG_BEXT();
	 *  (obj == null) <=> false
	 *  obj.isNull() <=> true
	 * </code></pre>
	 * To creates a new <code>TAG_BEXT</code>, use the static "constructor" :
	 * <pre><code>  TAG_BEXT obj = TAG_BEXT.create();</code></pre>
	 * @see TAG_BEXT#create()
	 */
	public TAG_BEXT()
	{
		super();
	}

	public void release()
	{
		if(pointer != 0)
		{

			StructureJNI.TAG_BEXT_delete(pointer);
		}
		pointer = 0;
	}

	/**
	 * 
	 */
	public String getDescription()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_BEXT_get_Description(pointer);
		return javaResult;
	}
	public void setDescription(String description)
	{
		if(pointer == 0) throw new NullPointerException();
		if((description != null) && (description.length() > 256)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_BEXT_set_Description(pointer, description == null ? null : description.getBytes());
	}

	/**
	 * 
	 */
	public String getOriginator()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_BEXT_get_Originator(pointer);
		return javaResult;
	}
	public void setOriginator(String originator)
	{
		if(pointer == 0) throw new NullPointerException();
		if((originator != null) && (originator.length() > 32)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_BEXT_set_Originator(pointer, originator == null ? null : originator.getBytes());
	}

	/**
	 * 
	 */
	public String getOriginatorReference()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_BEXT_get_OriginatorReference(pointer);
		return javaResult;
	}
	public void setOriginatorReference(String originatorReference)
	{
		if(pointer == 0) throw new NullPointerException();
		if((originatorReference != null) && (originatorReference.length() > 32)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_BEXT_set_OriginatorReference(pointer, originatorReference == null ? null : originatorReference.getBytes());
	}

	/**
	 * 
	 */
	public String getOriginationDate()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_BEXT_get_OriginationDate(pointer);
		return javaResult;
	}
	public void setOriginationDate(String originationDate)
	{
		if(pointer == 0) throw new NullPointerException();
		if((originationDate != null) && (originationDate.length() > 10)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_BEXT_set_OriginationDate(pointer, originationDate == null ? null : originationDate.getBytes());
	}

	/**
	 * 
	 */
	public String getOriginationTime()
	{
		if(pointer == 0) throw new NullPointerException();
		String javaResult = StructureJNI.TAG_BEXT_get_OriginationTime(pointer);
		return javaResult;
	}
	public void setOriginationTime(String originationTime)
	{
		if(pointer == 0) throw new NullPointerException();
		if((originationTime != null) && (originationTime.length() > 8)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_BEXT_set_OriginationTime(pointer, originationTime == null ? null : originationTime.getBytes());
	}

	/**
	 * 
	 */
	public long getTimeReference()
	{
		if(pointer == 0) throw new NullPointerException();
		long javaResult = StructureJNI.TAG_BEXT_get_TimeReference(pointer);
		return javaResult;
	}
	public void setTimeReference(long timeReference)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.TAG_BEXT_set_TimeReference(pointer, timeReference);
	}

	/**
	 * 
	 */
	public short getVersion()
	{
		if(pointer == 0) throw new NullPointerException();
		short javaResult = StructureJNI.TAG_BEXT_get_Version(pointer);
		return javaResult;
	}
	public void setVersion(short version)
	{
		if(pointer == 0) throw new NullPointerException();
		StructureJNI.TAG_BEXT_set_Version(pointer, version);
	}

	/**
	 * 
	 */
	public ByteBuffer getUMID()
	{
		if(pointer == 0) throw new NullPointerException();
		ByteBuffer javaResult = StructureJNI.TAG_BEXT_get_UMID(pointer);
		if(javaResult != null) {
			javaResult.order(ByteOrder.nativeOrder());
		}
		return javaResult;
	}
	public void setUMID(String UMID)
	{
		if(pointer == 0) throw new NullPointerException();
		if((UMID != null) && (UMID.length() > 64)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_BEXT_set_UMID(pointer, UMID == null ? null : UMID.getBytes());
	}

	/**
	 * 
	 */
	public ByteBuffer getReserved()
	{
		if(pointer == 0) throw new NullPointerException();
		ByteBuffer javaResult = StructureJNI.TAG_BEXT_get_Reserved(pointer);
		if(javaResult != null) {
			javaResult.order(ByteOrder.nativeOrder());
		}
		return javaResult;
	}
	public void setReserved(String reserved)
	{
		if(pointer == 0) throw new NullPointerException();
		if((reserved != null) && (reserved.length() > 190)) {
			throw new IndexOutOfBoundsException();
		}
		StructureJNI.TAG_BEXT_set_Reserved(pointer, reserved == null ? null : reserved.getBytes());
	}

}