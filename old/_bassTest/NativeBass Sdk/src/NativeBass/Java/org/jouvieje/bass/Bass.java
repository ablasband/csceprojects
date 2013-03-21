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

public class Bass extends Pointer
{
	private Bass(){}

	/**
	 * 
	 */
	public static boolean BASS_SetConfig(int option, int value)
	{
		boolean javaResult = BassJNI.Bass_BASS_SetConfig(option, value);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_GetConfig(int option)
	{
		int javaResult = BassJNI.Bass_BASS_GetConfig(option);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SetConfigPtr(int option, Pointer value)
	{
		boolean javaResult = BassJNI.Bass_BASS_SetConfigPtr(option, Pointer.getPointer(value));
		return javaResult;
	}

	/**
	 * 
	 */
	public static Pointer BASS_GetConfigPtr(int option)
	{
		long javaResult = BassJNI.Bass_BASS_GetConfigPtr(option);
		return javaResult == 0 ? null : Pointer.newPointer(javaResult);
	}

	/**
	 * 
	 */
	public static int BASS_GetVersion()
	{
		int javaResult = BassJNI.Bass_BASS_GetVersion();
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_ErrorGetCode()
	{
		int javaResult = BassJNI.Bass_BASS_ErrorGetCode();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_GetDeviceInfo(int device, BASS_DEVICEINFO info)
	{
		boolean javaResult = BassJNI.Bass_BASS_GetDeviceInfo(device, Pointer.getPointer(info));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Init(int device, int freq, int flags, Pointer win, Pointer dsguid)
	{
		boolean javaResult = BassJNI.Bass_BASS_Init(device, freq, flags, Pointer.getPointer(win), Pointer.getPointer(dsguid));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SetDevice(int device)
	{
		boolean javaResult = BassJNI.Bass_BASS_SetDevice(device);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_GetDevice()
	{
		int javaResult = BassJNI.Bass_BASS_GetDevice();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Free()
	{
		boolean javaResult = BassJNI.Bass_BASS_Free();
		return javaResult;
	}

	/**
	 * 
	 */
	public static Pointer BASS_GetDSoundObject(int object)
	{
		long javaResult = BassJNI.Bass_BASS_GetDSoundObject(object);
		return javaResult == 0 ? null : Pointer.newPointer(javaResult);
	}

	/**
	 * 
	 */
	public static boolean BASS_GetInfo(BASS_INFO info)
	{
		boolean javaResult = BassJNI.Bass_BASS_GetInfo(Pointer.getPointer(info));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Update(int length)
	{
		boolean javaResult = BassJNI.Bass_BASS_Update(length);
		return javaResult;
	}

	/**
	 * 
	 */
	public static float BASS_GetCPU()
	{
		float javaResult = BassJNI.Bass_BASS_GetCPU();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Start()
	{
		boolean javaResult = BassJNI.Bass_BASS_Start();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Stop()
	{
		boolean javaResult = BassJNI.Bass_BASS_Stop();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Pause()
	{
		boolean javaResult = BassJNI.Bass_BASS_Pause();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SetVolume(float volume)
	{
		boolean javaResult = BassJNI.Bass_BASS_SetVolume(volume);
		return javaResult;
	}

	/**
	 * 
	 */
	public static float BASS_GetVolume()
	{
		float javaResult = BassJNI.Bass_BASS_GetVolume();
		return javaResult;
	}

	/**
	 * 
	 */
	public static HPLUGIN BASS_PluginLoad(String file, int flags)
	{
		long javaResult = BassJNI.Bass_BASS_PluginLoad(file == null ? null : file.getBytes(), flags);
		return javaResult == 0 ? null : HPLUGIN.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_PluginFree(HPLUGIN handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_PluginFree(Pointer.getPointer(handle));
		return javaResult;
	}

	/**
	 * 
	 */
	public static BASS_PLUGININFO BASS_PluginGetInfo(HPLUGIN handle)
	{
		long javaResult = BassJNI.Bass_BASS_PluginGetInfo(Pointer.getPointer(handle));
		return javaResult == 0 ? null : BASS_PLUGININFO.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_Set3DFactors(float distf, float rollf, float doppf)
	{
		boolean javaResult = BassJNI.Bass_BASS_Set3DFactors(distf, rollf, doppf);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Get3DFactors(FloatBuffer distf, FloatBuffer rollf, FloatBuffer doppf)
	{
		if(distf != null && !distf.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(rollf != null && !rollf.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(doppf != null && !doppf.isDirect())
		{
			throw new NonDirectBufferException();
		}
		boolean javaResult = BassJNI.Bass_BASS_Get3DFactors(distf, BufferUtils.getPositionInBytes(distf), rollf, BufferUtils.getPositionInBytes(rollf), doppf, BufferUtils.getPositionInBytes(doppf));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Set3DPosition(BASS_3DVECTOR pos, BASS_3DVECTOR vel, BASS_3DVECTOR front, BASS_3DVECTOR top)
	{
		boolean javaResult = BassJNI.Bass_BASS_Set3DPosition(Pointer.getPointer(pos), Pointer.getPointer(vel), Pointer.getPointer(front), Pointer.getPointer(top));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_Get3DPosition(BASS_3DVECTOR pos, BASS_3DVECTOR vel, BASS_3DVECTOR front, BASS_3DVECTOR top)
	{
		boolean javaResult = BassJNI.Bass_BASS_Get3DPosition(Pointer.getPointer(pos), Pointer.getPointer(vel), Pointer.getPointer(front), Pointer.getPointer(top));
		return javaResult;
	}

	/**
	 * 
	 */
	public static void BASS_Apply3D()
	{
		BassJNI.Bass_BASS_Apply3D();

	}

	/**
	 * 
	 */
	public static boolean BASS_SetEAXParameters(int env, float vol, float decay, float damp)
	{
		boolean javaResult = BassJNI.Bass_BASS_SetEAXParameters(env, vol, decay, damp);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_GetEAXParameters(IntBuffer env, FloatBuffer vol, FloatBuffer decay, FloatBuffer damp)
	{
		if(env != null && !env.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(vol != null && !vol.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(decay != null && !decay.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(damp != null && !damp.isDirect())
		{
			throw new NonDirectBufferException();
		}
		boolean javaResult = BassJNI.Bass_BASS_GetEAXParameters(env, BufferUtils.getPositionInBytes(env), vol, BufferUtils.getPositionInBytes(vol), decay, BufferUtils.getPositionInBytes(decay), damp, BufferUtils.getPositionInBytes(damp));
		return javaResult;
	}

	/**
	 * 
	 */
	public static HMUSIC BASS_MusicLoad(boolean mem, Pointer file, long offset, int length, int flags, int freq)
	{
		long javaResult = BassJNI.Bass_BASS_MusicLoad(mem, Pointer.getPointer(file), offset, length, flags, freq);
		return javaResult == 0 ? null : HMUSIC.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HMUSIC BASS_MusicLoad(boolean mem, String file, long offset, int length, int flags, int freq)
	{
		long javaResult = BassJNI.Bass_BASS_MusicLoad(mem, file == null ? null : file.getBytes(), offset, length, flags, freq);
		return javaResult == 0 ? null : HMUSIC.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_MusicFree(HMUSIC handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_MusicFree(Pointer.getPointer(handle));
		return javaResult;
	}

	/**
	 * 
	 */
	public static HSAMPLE BASS_SampleLoad(boolean mem, Pointer file, long offset, int length, int max, int flags)
	{
		long javaResult = BassJNI.Bass_BASS_SampleLoad(mem, Pointer.getPointer(file), offset, length, max, flags);
		return javaResult == 0 ? null : HSAMPLE.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HSAMPLE BASS_SampleLoad(boolean mem, String file, long offset, int length, int max, int flags)
	{
		long javaResult = BassJNI.Bass_BASS_SampleLoad(mem, file == null ? null : file.getBytes(), offset, length, max, flags);
		return javaResult == 0 ? null : HSAMPLE.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HSAMPLE BASS_SampleCreate(int length, int freq, int chans, int max, int flags)
	{
		long javaResult = BassJNI.Bass_BASS_SampleCreate(length, freq, chans, max, flags);
		return javaResult == 0 ? null : HSAMPLE.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_SampleFree(HSAMPLE handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_SampleFree(Pointer.getPointer(handle));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SampleSetData(HSAMPLE handle, Pointer buffer)
	{
		boolean javaResult = BassJNI.Bass_BASS_SampleSetData(Pointer.getPointer(handle), Pointer.getPointer(buffer));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SampleGetData(HSAMPLE handle, Pointer buffer)
	{
		boolean javaResult = BassJNI.Bass_BASS_SampleGetData(Pointer.getPointer(handle), Pointer.getPointer(buffer));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SampleGetInfo(HSAMPLE handle, IntBuffer info)
	{
		if(info != null && !info.isDirect())
		{
			throw new NonDirectBufferException();
		}
		boolean javaResult = BassJNI.Bass_BASS_SampleGetInfo(Pointer.getPointer(handle), info, BufferUtils.getPositionInBytes(info));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SampleSetInfo(HSAMPLE handle, IntBuffer info)
	{
		if(info != null && !info.isDirect())
		{
			throw new NonDirectBufferException();
		}
		boolean javaResult = BassJNI.Bass_BASS_SampleSetInfo(Pointer.getPointer(handle), info, BufferUtils.getPositionInBytes(info));
		return javaResult;
	}

	/**
	 * 
	 */
	public static HCHANNEL BASS_SampleGetChannel(HSAMPLE handle, boolean onlynew)
	{
		long javaResult = BassJNI.Bass_BASS_SampleGetChannel(Pointer.getPointer(handle), onlynew);
		return javaResult == 0 ? null : HCHANNEL.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static int BASS_SampleGetChannels(HSAMPLE handle, HCHANNEL[] channels)
	{
		int javaResult = BassJNI.Bass_BASS_SampleGetChannels(Pointer.getPointer(handle), Pointer.getPointer(channels[0]));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_SampleStop(HSAMPLE handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_SampleStop(Pointer.getPointer(handle));
		return javaResult;
	}

	/**
	 * 
	 */
	public static HSTREAM BASS_StreamCreate(int freq, int chans, int flags, STREAMPROC proc, Pointer user)
	{
		CallbackManager.addTmpCallback(0, proc);
		long javaResult = BassJNI.Bass_BASS_StreamCreate(freq, chans, flags, proc == null ? false : true, Pointer.getPointer(user));
		CallbackManager.addCallback(0, proc, javaResult);
		CallbackManager.addOwner(proc == null ? 0 : javaResult, javaResult);
		return javaResult == 0 ? null : HSTREAM.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HSTREAM BASS_StreamCreate(int freq, int chans, int flags, STREAMPROC_SPECIAL proc, Pointer user)
	{
		long javaResult = BassJNI.Bass_BASS_StreamCreate(freq, chans, flags, proc.asInt(), Pointer.getPointer(user));
		return javaResult == 0 ? null : HSTREAM.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HSTREAM BASS_StreamCreateFile(boolean mem, ByteBuffer file, long offset, long length, int flags)
	{
		if(file != null && !file.isDirect())
		{
			throw new NonDirectBufferException();
		}
		long javaResult = BassJNI.Bass_BASS_StreamCreateFile(mem, file, BufferUtils.getPositionInBytes(file), offset, length, flags);
		return javaResult == 0 ? null : HSTREAM.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HSTREAM BASS_StreamCreateFile(boolean mem, String file, long offset, long length, int flags)
	{
		long javaResult = BassJNI.Bass_BASS_StreamCreateFile(mem, file == null ? null : file.getBytes(), offset, length, flags);
		return javaResult == 0 ? null : HSTREAM.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HSTREAM BASS_StreamCreateURL(String url, int offset, int flags, DOWNLOADPROC proc, Pointer user)
	{
		CallbackManager.addCallback(5, proc, 0);
		long javaResult = BassJNI.Bass_BASS_StreamCreateURL(url == null ? null : url.getBytes(), offset, flags, proc == null ? false : true, Pointer.getPointer(user));
		return javaResult == 0 ? null : HSTREAM.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static HSTREAM BASS_StreamCreateFileUser(int system, int flags, BASS_FILEPROCS proc, Pointer user)
	{
		long javaResult = BassJNI.Bass_BASS_StreamCreateFileUser(system, flags, Pointer.getPointer(proc), Pointer.getPointer(user));
		return javaResult == 0 ? null : HSTREAM.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_StreamFree(HSTREAM handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_StreamFree(Pointer.getPointer(handle));
		return javaResult;
	}

	/**
	 * 
	 */
	public static long BASS_StreamGetFilePosition(HSTREAM handle, int mode)
	{
		long javaResult = BassJNI.Bass_BASS_StreamGetFilePosition(Pointer.getPointer(handle), mode);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_StreamPutData(HSTREAM handle, ByteBuffer buffer, int length)
	{
		if(buffer != null && !buffer.isDirect())
		{
			throw new NonDirectBufferException();
		}
		int javaResult = BassJNI.Bass_BASS_StreamPutData(Pointer.getPointer(handle), buffer, BufferUtils.getPositionInBytes(buffer), length);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_StreamPutFileData(HSTREAM handle, Pointer buffer, int length)
	{
		int javaResult = BassJNI.Bass_BASS_StreamPutFileData(Pointer.getPointer(handle), Pointer.getPointer(buffer), length);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_RecordGetDeviceInfo(int device, BASS_DEVICEINFO info)
	{
		boolean javaResult = BassJNI.Bass_BASS_RecordGetDeviceInfo(device, Pointer.getPointer(info));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_RecordInit(int device)
	{
		boolean javaResult = BassJNI.Bass_BASS_RecordInit(device);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_RecordSetDevice(int device)
	{
		boolean javaResult = BassJNI.Bass_BASS_RecordSetDevice(device);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_RecordGetDevice()
	{
		int javaResult = BassJNI.Bass_BASS_RecordGetDevice();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_RecordFree()
	{
		boolean javaResult = BassJNI.Bass_BASS_RecordFree();
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_RecordGetInfo(BASS_RECORDINFO info)
	{
		boolean javaResult = BassJNI.Bass_BASS_RecordGetInfo(Pointer.getPointer(info));
		return javaResult;
	}

	/**
	 * 
	 */
	public static String BASS_RecordGetInputName(int input)
	{
		String javaResult = BassJNI.Bass_BASS_RecordGetInputName(input);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_RecordSetInput(int input, int flags, float volume)
	{
		boolean javaResult = BassJNI.Bass_BASS_RecordSetInput(input, flags, volume);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_RecordGetInput(int input, FloatBuffer volume)
	{
		if(volume != null && !volume.isDirect())
		{
			throw new NonDirectBufferException();
		}
		int javaResult = BassJNI.Bass_BASS_RecordGetInput(input, volume, BufferUtils.getPositionInBytes(volume));
		return javaResult;
	}

	/**
	 * 
	 */
	public static HRECORD BASS_RecordStart(int freq, int chans, int flags, RECORDPROC proc, Pointer user)
	{
		CallbackManager.addTmpCallback(8, proc);
		long javaResult = BassJNI.Bass_BASS_RecordStart(freq, chans, flags, proc == null ? false : true, Pointer.getPointer(user));
		CallbackManager.addCallback(8, proc, javaResult);
		CallbackManager.addOwner(proc == null ? 0 : javaResult, javaResult);
		return javaResult == 0 ? null : HRECORD.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static double BASS_ChannelBytes2Seconds(int handle, long pos)
	{
		double javaResult = BassJNI.Bass_BASS_ChannelBytes2Seconds(handle, pos);
		return javaResult;
	}

	/**
	 * 
	 */
	public static long BASS_ChannelSeconds2Bytes(int handle, double pos)
	{
		long javaResult = BassJNI.Bass_BASS_ChannelSeconds2Bytes(handle, pos);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_ChannelGetDevice(int handle)
	{
		int javaResult = BassJNI.Bass_BASS_ChannelGetDevice(handle);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelSetDevice(int handle, int device)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelSetDevice(handle, device);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_ChannelIsActive(int handle)
	{
		int javaResult = BassJNI.Bass_BASS_ChannelIsActive(handle);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelGetInfo(int handle, BASS_CHANNELINFO info)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelGetInfo(handle, Pointer.getPointer(info));
		return javaResult;
	}

	/**
	 * 
	 */
	public static Pointer BASS_ChannelGetTags(int handle, int tags)
	{
		long javaResult = BassJNI.Bass_BASS_ChannelGetTags(handle, tags);
		return javaResult == 0 ? null : Pointer.newPointer(javaResult);
	}

	/**
	 * 
	 */
	public static int BASS_ChannelFlags(int handle, int flags, int mask)
	{
		int javaResult = BassJNI.Bass_BASS_ChannelFlags(handle, flags, mask);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelUpdate(int handle, int length)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelUpdate(handle, length);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelLock(int handle, boolean lock)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelLock(handle, lock);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelPlay(int handle, boolean restart)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelPlay(handle, restart);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelStop(int handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelStop(handle);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelPause(int handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelPause(handle);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelSetAttribute(int handle, int attrib, float value)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelSetAttribute(handle, attrib, value);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelGetAttribute(int handle, int attrib, FloatBuffer value)
	{
		if(value != null && !value.isDirect())
		{
			throw new NonDirectBufferException();
		}
		boolean javaResult = BassJNI.Bass_BASS_ChannelGetAttribute(handle, attrib, value, BufferUtils.getPositionInBytes(value));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelSlideAttribute(int handle, int attrib, float value, int time)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelSlideAttribute(handle, attrib, value, time);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelIsSliding(int handle, int attrib)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelIsSliding(handle, attrib);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelSet3DAttributes(int handle, int mode, float min, float max, int iangle, int oangle, float outvol)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelSet3DAttributes(handle, mode, min, max, iangle, oangle, outvol);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelGet3DAttributes(int handle, IntBuffer mode, FloatBuffer min, FloatBuffer max, IntBuffer iangle, IntBuffer oangle, FloatBuffer outvol)
	{
		if(mode != null && !mode.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(min != null && !min.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(max != null && !max.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(iangle != null && !iangle.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(oangle != null && !oangle.isDirect())
		{
			throw new NonDirectBufferException();
		}
		if(outvol != null && !outvol.isDirect())
		{
			throw new NonDirectBufferException();
		}
		boolean javaResult = BassJNI.Bass_BASS_ChannelGet3DAttributes(handle, mode, BufferUtils.getPositionInBytes(mode), min, BufferUtils.getPositionInBytes(min), max, BufferUtils.getPositionInBytes(max), iangle, BufferUtils.getPositionInBytes(iangle), oangle, BufferUtils.getPositionInBytes(oangle), outvol, BufferUtils.getPositionInBytes(outvol));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelSet3DPosition(int handle, BASS_3DVECTOR pos, BASS_3DVECTOR orient, BASS_3DVECTOR vel)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelSet3DPosition(handle, Pointer.getPointer(pos), Pointer.getPointer(orient), Pointer.getPointer(vel));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelGet3DPosition(int handle, BASS_3DVECTOR pos, BASS_3DVECTOR orient, BASS_3DVECTOR vel)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelGet3DPosition(handle, Pointer.getPointer(pos), Pointer.getPointer(orient), Pointer.getPointer(vel));
		return javaResult;
	}

	/**
	 * 
	 */
	public static long BASS_ChannelGetLength(int handle, int mode)
	{
		long javaResult = BassJNI.Bass_BASS_ChannelGetLength(handle, mode);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelSetPosition(int handle, long pos, int mode)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelSetPosition(handle, pos, mode);
		return javaResult;
	}

	/**
	 * 
	 */
	public static long BASS_ChannelGetPosition(int handle, int mode)
	{
		long javaResult = BassJNI.Bass_BASS_ChannelGetPosition(handle, mode);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_ChannelGetLevel(int handle)
	{
		int javaResult = BassJNI.Bass_BASS_ChannelGetLevel(handle);
		return javaResult;
	}

	/**
	 * 
	 */
	public static int BASS_ChannelGetData(int handle, ByteBuffer buffer, int length)
	{
		if(buffer != null && !buffer.isDirect())
		{
			throw new NonDirectBufferException();
		}
		int javaResult = BassJNI.Bass_BASS_ChannelGetData(handle, buffer, BufferUtils.getPositionInBytes(buffer), length);
		return javaResult;
	}

	/**
	 * 
	 */
	public static HSYNC BASS_ChannelSetSync(int handle, int type, long param, SYNCPROC proc, Pointer user)
	{
		CallbackManager.addTmpCallback(6, proc);
		long javaResult = BassJNI.Bass_BASS_ChannelSetSync(handle, type, param, proc == null ? false : true, Pointer.getPointer(user));
		CallbackManager.addCallback(6, proc, javaResult);
		CallbackManager.addOwner(proc == null ? 0 : javaResult, javaResult);
		return javaResult == 0 ? null : HSYNC.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelRemoveSync(int handle, HSYNC sync)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelRemoveSync(handle, Pointer.getPointer(sync));
		return javaResult;
	}

	/**
	 * 
	 */
	public static HDSP BASS_ChannelSetDSP(int handle, DSPPROC proc, Pointer user, int priority)
	{
		CallbackManager.addTmpCallback(7, proc);
		long javaResult = BassJNI.Bass_BASS_ChannelSetDSP(handle, proc == null ? false : true, Pointer.getPointer(user), priority);
		CallbackManager.addCallback(7, proc, javaResult);
		CallbackManager.addOwner(proc == null ? 0 : javaResult, javaResult);
		return javaResult == 0 ? null : HDSP.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelRemoveDSP(int handle, HDSP dsp)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelRemoveDSP(handle, Pointer.getPointer(dsp));
		if(dsp != null) {
			final long dspPointer = dsp.asLong();
			if(dspPointer != 0) {
				CallbackManager.addOwner(0, dspPointer);
			}
		}
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelSetLink(int handle, int chan)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelSetLink(handle, chan);
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelRemoveLink(int handle, int chan)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelRemoveLink(handle, chan);
		return javaResult;
	}

	/**
	 * 
	 */
	public static HFX BASS_ChannelSetFX(int handle, int type, int priority)
	{
		long javaResult = BassJNI.Bass_BASS_ChannelSetFX(handle, type, priority);
		return javaResult == 0 ? null : HFX.createView(Pointer.newPointer(javaResult));
	}

	/**
	 * 
	 */
	public static boolean BASS_ChannelRemoveFX(int handle, HFX fx)
	{
		boolean javaResult = BassJNI.Bass_BASS_ChannelRemoveFX(handle, Pointer.getPointer(fx));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_FXSetParameters(HFX handle, Pointer params)
	{
		boolean javaResult = BassJNI.Bass_BASS_FXSetParameters(Pointer.getPointer(handle), Pointer.getPointer(params));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_FXGetParameters(HFX handle, Pointer params)
	{
		boolean javaResult = BassJNI.Bass_BASS_FXGetParameters(Pointer.getPointer(handle), Pointer.getPointer(params));
		return javaResult;
	}

	/**
	 * 
	 */
	public static boolean BASS_FXReset(HFX handle)
	{
		boolean javaResult = BassJNI.Bass_BASS_FXReset(Pointer.getPointer(handle));
		return javaResult;
	}

	/*
	 *
	 */
	public static boolean BASS_SetEAXParameters(EAX_PRESET preset)
	{
		return BASS_SetEAXParameters(preset.getEnv().asInt(), preset.getVolume(), preset.getDecay(), preset.getDamping());
	}
}