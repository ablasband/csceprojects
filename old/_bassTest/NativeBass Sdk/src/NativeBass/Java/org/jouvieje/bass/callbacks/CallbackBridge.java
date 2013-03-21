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

package org.jouvieje.bass.callbacks;

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

class CallbackBridge extends Pointer
{
	protected final static int NB_CALLBACKS = 9;

	public static int STREAMPROC_BRIDGE(long handle, ByteBuffer buffer, int length, long user)
	{
		STREAMPROC callback = (STREAMPROC)CallbackManager.getCallback(0, handle, false);
		if(buffer != null) {
			buffer.order(ByteOrder.nativeOrder());
		}
		int javaResult = callback.STREAMPROC(handle == 0 ? null : HSTREAM.createView(Pointer.newPointer(handle)), buffer, length, user == 0 ? null : Pointer.newPointer(user));
		return javaResult;
	}
	public static void FILECLOSEPROC_BRIDGE(long user)
	{
		FILECLOSEPROC callback = (FILECLOSEPROC)CallbackManager.getCallback(1, user, false);
		callback.FILECLOSEPROC(user == 0 ? null : Pointer.newPointer(user));
	}
	public static long FILELENPROC_BRIDGE(long user)
	{
		FILELENPROC callback = (FILELENPROC)CallbackManager.getCallback(2, user, false);
		long javaResult = callback.FILELENPROC(user == 0 ? null : Pointer.newPointer(user));
		return javaResult;
	}
	public static int FILEREADPROC_BRIDGE(long buffer, int length, long user)
	{
		FILEREADPROC callback = (FILEREADPROC)CallbackManager.getCallback(3, buffer, false);
		int javaResult = callback.FILEREADPROC(buffer == 0 ? null : Pointer.newPointer(buffer), length, user == 0 ? null : Pointer.newPointer(user));
		return javaResult;
	}
	public static boolean FILESEEKPROC_BRIDGE(long offset, long user)
	{
		FILESEEKPROC callback = (FILESEEKPROC)CallbackManager.getCallback(4, offset, false);
		boolean javaResult = callback.FILESEEKPROC(offset, user == 0 ? null : Pointer.newPointer(user));
		return javaResult;
	}
	public static void DOWNLOADPROC_BRIDGE(ByteBuffer buffer, int length, long user)
	{
		DOWNLOADPROC callback = (DOWNLOADPROC)CallbackManager.getCallback(5);
		if(buffer != null) {
			buffer.order(ByteOrder.nativeOrder());
		}
		callback.DOWNLOADPROC(buffer, length, user == 0 ? null : Pointer.newPointer(user));
	}
	public static void SYNCPROC_BRIDGE(long handle, int channel, int data, long user)
	{
		SYNCPROC callback = (SYNCPROC)CallbackManager.getCallback(6, handle, false);
		callback.SYNCPROC(handle == 0 ? null : HSYNC.createView(Pointer.newPointer(handle)), channel, data, user == 0 ? null : Pointer.newPointer(user));
	}
	public static void DSPPROC_BRIDGE(long handle, int channel, ByteBuffer buffer, int length, long user)
	{
		DSPPROC callback = (DSPPROC)CallbackManager.getCallback(7, handle, false);
		if(buffer != null) {
			buffer.order(ByteOrder.nativeOrder());
		}
		callback.DSPPROC(handle == 0 ? null : HDSP.createView(Pointer.newPointer(handle)), channel, buffer, length, user == 0 ? null : Pointer.newPointer(user));
	}
	public static boolean RECORDPROC_BRIDGE(long handle, ByteBuffer buffer, int length, long user)
	{
		RECORDPROC callback = (RECORDPROC)CallbackManager.getCallback(8, handle, false);
		if(buffer != null) {
			buffer.order(ByteOrder.nativeOrder());
		}
		boolean javaResult = callback.RECORDPROC(handle == 0 ? null : HRECORD.createView(Pointer.newPointer(handle)), buffer, length, user == 0 ? null : Pointer.newPointer(user));
		return javaResult;
	}

	protected static String getCallbackName(int type)
	{
		switch(type)
		{
			case 0: return "STREAMPROC";
			case 1: return "FILECLOSEPROC";
			case 2: return "FILELENPROC";
			case 3: return "FILEREADPROC";
			case 4: return "FILESEEKPROC";
			case 5: return "DOWNLOADPROC";
			case 6: return "SYNCPROC";
			case 7: return "DSPPROC";
			case 8: return "RECORDPROC";
			default: return "UNKNOW_"+type;
		}
	}
}