/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright © 2007 Jérôme JOUVIE (Jouvieje)
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

package org.jouvieje.bass.misc;

import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * Utility routines for dealing with Pointer.
 */
public class PointerUtils
{
	/**
	 * Create a view of the <code>Pointer</code> object as a <code>ByteBuffer</code> object.<br>
	 * @param pointer Pointer to view as a ByteBuffer.
	 * @param capacityInBytes capacity in BYTES of the buffer.
	 * @return the ByteBuffer view.
	 */
	public static ByteBuffer createView(Pointer pointer, long capacityInBytes)
	{
		ByteBuffer result = BufferUtilsJNI.newDirectByteBuffer(Pointer.getPointer(pointer), capacityInBytes);
		if(result != null) {
			result.order(ByteOrder.nativeOrder());
		}
		return result;
	}
	
	public static Pointer createSubView(Pointer pointer, int offset)
	{
		long address = Pointer.getPointer(pointer);
		return (address == 0) ? null : new Pointer(address+offset);
	}
	

	/**
	 * Retrieve the <code>String</code> value stored in a <code>Pointer</code> (null terminated string).<BR>
	 * @param pointer a <code>Pointer</code> that holds a String.
	 * @return the String stored in the Pointer.<BR>
	 * null if no String is stored in the buffer.
	 * @see #toString(Pointer, int, int)
	 */
	public static String toString(Pointer pointer)
	{
		long address = Pointer.getPointer(pointer);
		return (address == 0) ? null : PointerUtilsJNI.Pointer_toString(address);
	}
	/**
	 * Retrieve the <code>String</code> value stored in the <code>Pointer</code>.
	 * @param pointer a <code>Pointer</code> that holds a String.
	 * @param offset offset (in characters) from the current position in the <code>Pointer</code>.
	 * @param length length of the String to retrieve.
	 * @return the string stored in the <code>Pointer</code>.
	 * @see #toString(Pointer)
	 * @see BufferUtils#toString(ByteBuffer, int, int)
	 */
	public static String toString(Pointer pointer, int offset, int length)
	{
		long tempAddress = Pointer.getPointer(pointer);
		if(tempAddress == 0)
			return null;
		long address = tempAddress+offset;

		String s = PointerUtilsJNI.Pointer_toString(address);
		if(s != null && s.length() > length)
			s = s.substring(0, length);
		return s;
	}
	
	/**
	 * 
	 */
	public static int stringLength(Pointer pointer)
	{
		long address = Pointer.getPointer(pointer);
		return (address == 0) ? 0 : PointerUtilsJNI.Pointer_strlen(address);
	}
}