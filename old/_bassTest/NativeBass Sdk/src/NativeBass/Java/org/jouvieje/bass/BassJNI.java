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

package org.jouvieje.bass;

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

class BassJNI
{
	static
	{
		if(!Init.isLibrariesLoaded())
		{
			throw new RuntimeException("Libraries not loaded ! Use Init.loadLibraries() before using NativeBass.");
		}
	}

	protected final static native boolean Bass_BASS_SetConfig(int option, int value);
	protected final static native int Bass_BASS_GetConfig(int option);
	protected final static native boolean Bass_BASS_SetConfigPtr(int option, long value);
	protected final static native long Bass_BASS_GetConfigPtr(int option);
	protected final static native int Bass_BASS_GetVersion();
	protected final static native int Bass_BASS_ErrorGetCode();
	protected final static native boolean Bass_BASS_GetDeviceInfo(int device, long info);
	protected final static native boolean Bass_BASS_Init(int device, int freq, int flags, long win, long dsguid);
	protected final static native boolean Bass_BASS_SetDevice(int device);
	protected final static native int Bass_BASS_GetDevice();
	protected final static native boolean Bass_BASS_Free();
	protected final static native long Bass_BASS_GetDSoundObject(int object);
	protected final static native boolean Bass_BASS_GetInfo(long info);
	protected final static native boolean Bass_BASS_Update(int length);
	protected final static native float Bass_BASS_GetCPU();
	protected final static native boolean Bass_BASS_Start();
	protected final static native boolean Bass_BASS_Stop();
	protected final static native boolean Bass_BASS_Pause();
	protected final static native boolean Bass_BASS_SetVolume(float volume);
	protected final static native float Bass_BASS_GetVolume();
	protected final static native long Bass_BASS_PluginLoad(byte[] file, int flags);
	protected final static native boolean Bass_BASS_PluginFree(long handle);
	protected final static native long Bass_BASS_PluginGetInfo(long handle);
	protected final static native boolean Bass_BASS_Set3DFactors(float distf, float rollf, float doppf);
	protected final static native boolean Bass_BASS_Get3DFactors(FloatBuffer distf, long distf_, FloatBuffer rollf, long rollf_, FloatBuffer doppf, long doppf_);
	protected final static native boolean Bass_BASS_Set3DPosition(long pos, long vel, long front, long top);
	protected final static native boolean Bass_BASS_Get3DPosition(long pos, long vel, long front, long top);
	protected final static native void Bass_BASS_Apply3D();
	protected final static native boolean Bass_BASS_SetEAXParameters(int env, float vol, float decay, float damp);
	protected final static native boolean Bass_BASS_GetEAXParameters(IntBuffer env, long env_, FloatBuffer vol, long vol_, FloatBuffer decay, long decay_, FloatBuffer damp, long damp_);
	protected final static native long Bass_BASS_MusicLoad(boolean mem, long file, long offset, int length, int flags, int freq);
	protected final static native long Bass_BASS_MusicLoad(boolean mem, byte[] file, long offset, int length, int flags, int freq);
	protected final static native boolean Bass_BASS_MusicFree(long handle);
	protected final static native long Bass_BASS_SampleLoad(boolean mem, long file, long offset, int length, int max, int flags);
	protected final static native long Bass_BASS_SampleLoad(boolean mem, byte[] file, long offset, int length, int max, int flags);
	protected final static native long Bass_BASS_SampleCreate(int length, int freq, int chans, int max, int flags);
	protected final static native boolean Bass_BASS_SampleFree(long handle);
	protected final static native boolean Bass_BASS_SampleSetData(long handle, long buffer);
	protected final static native boolean Bass_BASS_SampleGetData(long handle, long buffer);
	protected final static native boolean Bass_BASS_SampleGetInfo(long handle, IntBuffer info, long info_);
	protected final static native boolean Bass_BASS_SampleSetInfo(long handle, IntBuffer info, long info_);
	protected final static native long Bass_BASS_SampleGetChannel(long handle, boolean onlynew);
	protected final static native int Bass_BASS_SampleGetChannels(long handle, long channels);
	protected final static native boolean Bass_BASS_SampleStop(long handle);
	protected final static native long Bass_BASS_StreamCreate(int freq, int chans, int flags, boolean proc, long user);
	protected final static native long Bass_BASS_StreamCreate(int freq, int chans, int flags, int proc, long user);
	protected final static native long Bass_BASS_StreamCreateFile(boolean mem, ByteBuffer file, long file_, long offset, long length, int flags);
	protected final static native long Bass_BASS_StreamCreateFile(boolean mem, byte[] file, long offset, long length, int flags);
	protected final static native long Bass_BASS_StreamCreateURL(byte[] url, int offset, int flags, boolean proc, long user);
	protected final static native long Bass_BASS_StreamCreateFileUser(int system, int flags, long proc, long user);
	protected final static native boolean Bass_BASS_StreamFree(long handle);
	protected final static native long Bass_BASS_StreamGetFilePosition(long handle, int mode);
	protected final static native int Bass_BASS_StreamPutData(long handle, ByteBuffer buffer, long buffer_, int length);
	protected final static native int Bass_BASS_StreamPutFileData(long handle, long buffer, int length);
	protected final static native boolean Bass_BASS_RecordGetDeviceInfo(int device, long info);
	protected final static native boolean Bass_BASS_RecordInit(int device);
	protected final static native boolean Bass_BASS_RecordSetDevice(int device);
	protected final static native int Bass_BASS_RecordGetDevice();
	protected final static native boolean Bass_BASS_RecordFree();
	protected final static native boolean Bass_BASS_RecordGetInfo(long info);
	protected final static native String Bass_BASS_RecordGetInputName(int input);
	protected final static native boolean Bass_BASS_RecordSetInput(int input, int flags, float volume);
	protected final static native int Bass_BASS_RecordGetInput(int input, FloatBuffer volume, long volume_);
	protected final static native long Bass_BASS_RecordStart(int freq, int chans, int flags, boolean proc, long user);
	protected final static native double Bass_BASS_ChannelBytes2Seconds(int handle, long pos);
	protected final static native long Bass_BASS_ChannelSeconds2Bytes(int handle, double pos);
	protected final static native int Bass_BASS_ChannelGetDevice(int handle);
	protected final static native boolean Bass_BASS_ChannelSetDevice(int handle, int device);
	protected final static native int Bass_BASS_ChannelIsActive(int handle);
	protected final static native boolean Bass_BASS_ChannelGetInfo(int handle, long info);
	protected final static native long Bass_BASS_ChannelGetTags(int handle, int tags);
	protected final static native int Bass_BASS_ChannelFlags(int handle, int flags, int mask);
	protected final static native boolean Bass_BASS_ChannelUpdate(int handle, int length);
	protected final static native boolean Bass_BASS_ChannelLock(int handle, boolean lock);
	protected final static native boolean Bass_BASS_ChannelPlay(int handle, boolean restart);
	protected final static native boolean Bass_BASS_ChannelStop(int handle);
	protected final static native boolean Bass_BASS_ChannelPause(int handle);
	protected final static native boolean Bass_BASS_ChannelSetAttribute(int handle, int attrib, float value);
	protected final static native boolean Bass_BASS_ChannelGetAttribute(int handle, int attrib, FloatBuffer value, long value_);
	protected final static native boolean Bass_BASS_ChannelSlideAttribute(int handle, int attrib, float value, int time);
	protected final static native boolean Bass_BASS_ChannelIsSliding(int handle, int attrib);
	protected final static native boolean Bass_BASS_ChannelSet3DAttributes(int handle, int mode, float min, float max, int iangle, int oangle, float outvol);
	protected final static native boolean Bass_BASS_ChannelGet3DAttributes(int handle, IntBuffer mode, long mode_, FloatBuffer min, long min_, FloatBuffer max, long max_, IntBuffer iangle, long iangle_, IntBuffer oangle, long oangle_, FloatBuffer outvol, long outvol_);
	protected final static native boolean Bass_BASS_ChannelSet3DPosition(int handle, long pos, long orient, long vel);
	protected final static native boolean Bass_BASS_ChannelGet3DPosition(int handle, long pos, long orient, long vel);
	protected final static native long Bass_BASS_ChannelGetLength(int handle, int mode);
	protected final static native boolean Bass_BASS_ChannelSetPosition(int handle, long pos, int mode);
	protected final static native long Bass_BASS_ChannelGetPosition(int handle, int mode);
	protected final static native int Bass_BASS_ChannelGetLevel(int handle);
	protected final static native int Bass_BASS_ChannelGetData(int handle, ByteBuffer buffer, long buffer_, int length);
	protected final static native long Bass_BASS_ChannelSetSync(int handle, int type, long param, boolean proc, long user);
	protected final static native boolean Bass_BASS_ChannelRemoveSync(int handle, long sync);
	protected final static native long Bass_BASS_ChannelSetDSP(int handle, boolean proc, long user, int priority);
	protected final static native boolean Bass_BASS_ChannelRemoveDSP(int handle, long dsp);
	protected final static native boolean Bass_BASS_ChannelSetLink(int handle, int chan);
	protected final static native boolean Bass_BASS_ChannelRemoveLink(int handle, int chan);
	protected final static native long Bass_BASS_ChannelSetFX(int handle, int type, int priority);
	protected final static native boolean Bass_BASS_ChannelRemoveFX(int handle, long fx);
	protected final static native boolean Bass_BASS_FXSetParameters(long handle, long params);
	protected final static native boolean Bass_BASS_FXGetParameters(long handle, long params);
	protected final static native boolean Bass_BASS_FXReset(long handle);
}