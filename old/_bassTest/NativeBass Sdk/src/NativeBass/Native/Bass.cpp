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
#include "Utils.h"
#include "Pointer.h"
#include "bass.h"
#include "org_jouvieje_bass_BassJNI.h"
#include "CallbackManager.h"

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SetConfig(JNIEnv *java_env, jclass jcls, jint joption, jint jvalue) {
	DWORD option = (DWORD)joption;
	DWORD value = (DWORD)jvalue;

	BOOL result_ = BASS_SetConfig(option, value);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetConfig(JNIEnv *java_env, jclass jcls, jint joption) {
	DWORD option = (DWORD)joption;

	DWORD result_ = BASS_GetConfig(option);

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SetConfigPtr(JNIEnv *java_env, jclass jcls, jint joption, jlong jvalue) {
	DWORD option = (DWORD)joption;
	POINTER_TYPE valueTmp = (POINTER_TYPE)jvalue;
	void *value = *(void **)&valueTmp;

	BOOL result_ = BASS_SetConfigPtr(option, value);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetConfigPtr(JNIEnv *java_env, jclass jcls, jint joption) {
	DWORD option = (DWORD)joption;

	void *result_ = BASS_GetConfigPtr(option);

	POINTER_TYPE jresult;
	if(result_) {
		*(void **)&jresult = result_;
	} else {
		jresult = 0;
	}

	return (jlong)jresult;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetVersion(JNIEnv *java_env, jclass jcls) {

	DWORD result_ = BASS_GetVersion();

	return (jint)result_;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ErrorGetCode(JNIEnv *java_env, jclass jcls) {

	int result_ = BASS_ErrorGetCode();

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetDeviceInfo(JNIEnv *java_env, jclass jcls, jint jdevice, jlong jinfo) {
	DWORD device = (DWORD)jdevice;
	BASS_DEVICEINFO *info = 0;
	if(jinfo) {
		POINTER_TYPE infoTmp = (POINTER_TYPE)jinfo;
		info = *(BASS_DEVICEINFO **)&infoTmp;
	}

	BOOL result_ = BASS_GetDeviceInfo(device, info);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Init(JNIEnv *java_env, jclass jcls, jint jdevice, jint jfreq, jint jflags, jlong jwin, jlong jdsguid) {
	int device = (int)jdevice;
	DWORD freq = (DWORD)jfreq;
	DWORD flags = (DWORD)jflags;
	POINTER_TYPE winTmp = (POINTER_TYPE)jwin;
	void *win = *(void **)&winTmp;
	POINTER_TYPE dsguidTmp = (POINTER_TYPE)jdsguid;
	void *dsguid = *(void **)&dsguidTmp;

	BOOL result_ = BASS_Init(device, freq, flags, (HWND)win, (GUID *)dsguid);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SetDevice(JNIEnv *java_env, jclass jcls, jint jdevice) {
	DWORD device = (DWORD)jdevice;

	BOOL result_ = BASS_SetDevice(device);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetDevice(JNIEnv *java_env, jclass jcls) {

	DWORD result_ = BASS_GetDevice();

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Free(JNIEnv *java_env, jclass jcls) {

	BOOL result_ = BASS_Free();

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetDSoundObject(JNIEnv *java_env, jclass jcls, jint jobject) {
	DWORD object = (DWORD)jobject;

	void *result_ = BASS_GetDSoundObject(object);

	POINTER_TYPE jresult;
	if(result_) {
		*(void **)&jresult = result_;
	} else {
		jresult = 0;
	}

	return (jlong)jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetInfo(JNIEnv *java_env, jclass jcls, jlong jinfo) {
	BASS_INFO *info = 0;
	if(jinfo) {
		POINTER_TYPE infoTmp = (POINTER_TYPE)jinfo;
		info = *(BASS_INFO **)&infoTmp;
	}

	BOOL result_ = BASS_GetInfo(info);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Update(JNIEnv *java_env, jclass jcls, jint jlength) {
	DWORD length = (DWORD)jlength;

	BOOL result_ = BASS_Update(length);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetCPU(JNIEnv *java_env, jclass jcls) {

	float result_ = BASS_GetCPU();

	return (jfloat)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Start(JNIEnv *java_env, jclass jcls) {

	BOOL result_ = BASS_Start();

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Stop(JNIEnv *java_env, jclass jcls) {

	BOOL result_ = BASS_Stop();

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Pause(JNIEnv *java_env, jclass jcls) {

	BOOL result_ = BASS_Pause();

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SetVolume(JNIEnv *java_env, jclass jcls, jfloat jvolume) {
	float volume = (float)jvolume;

	BOOL result_ = BASS_SetVolume(volume);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetVolume(JNIEnv *java_env, jclass jcls) {

	float result_ = BASS_GetVolume();

	return (jfloat)result_;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1PluginLoad(JNIEnv *java_env, jclass jcls, jbyteArray jfile, jint jflags) {
	char *file = getByteArrayElements(java_env, jfile);
	DWORD flags = (DWORD)jflags;

	HPLUGIN cresult = BASS_PluginLoad(file, flags);

	releaseByteArrayElements(java_env, jfile, (const char *)file);
	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1PluginFree(JNIEnv *java_env, jclass jcls, jlong jhandle) {
	HPLUGIN handle = (HPLUGIN)(ADDRESS_TYPE)jhandle;

	BOOL result_ = BASS_PluginFree(handle);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1PluginGetInfo(JNIEnv *java_env, jclass jcls, jlong jhandle) {
	HPLUGIN handle = (HPLUGIN)(ADDRESS_TYPE)jhandle;

	const BASS_PLUGININFO * result_ = BASS_PluginGetInfo(handle);

	POINTER_TYPE jresult;
	if(result_) {
		*(const BASS_PLUGININFO **)&jresult = result_;
	} else {
		jresult = 0;
	}

	return (jlong)jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Set3DFactors(JNIEnv *java_env, jclass jcls, jfloat jdistf, jfloat jrollf, jfloat jdoppf) {
	float distf = (float)jdistf;
	float rollf = (float)jrollf;
	float doppf = (float)jdoppf;

	BOOL result_ = BASS_Set3DFactors(distf, rollf, doppf);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Get3DFactors(JNIEnv *java_env, jclass jcls, jobject jdistf, jlong jdistf_, jobject jrollf, jlong jrollf_, jobject jdoppf, jlong jdoppf_) {
	float *distf = 0;
	if(jdistf) {
		distf = (float *)((char *)java_env->GetDirectBufferAddress(jdistf)+jdistf_);
	}
	float *rollf = 0;
	if(jrollf) {
		rollf = (float *)((char *)java_env->GetDirectBufferAddress(jrollf)+jrollf_);
	}
	float *doppf = 0;
	if(jdoppf) {
		doppf = (float *)((char *)java_env->GetDirectBufferAddress(jdoppf)+jdoppf_);
	}

	BOOL result_ = BASS_Get3DFactors(distf, rollf, doppf);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Set3DPosition(JNIEnv *java_env, jclass jcls, jlong jpos, jlong jvel, jlong jfront, jlong jtop) {
	BASS_3DVECTOR *pos = 0;
	if(jpos) {
		POINTER_TYPE posTmp = (POINTER_TYPE)jpos;
		pos = *(BASS_3DVECTOR **)&posTmp;
	}
	BASS_3DVECTOR *vel = 0;
	if(jvel) {
		POINTER_TYPE velTmp = (POINTER_TYPE)jvel;
		vel = *(BASS_3DVECTOR **)&velTmp;
	}
	BASS_3DVECTOR *front = 0;
	if(jfront) {
		POINTER_TYPE frontTmp = (POINTER_TYPE)jfront;
		front = *(BASS_3DVECTOR **)&frontTmp;
	}
	BASS_3DVECTOR *top = 0;
	if(jtop) {
		POINTER_TYPE topTmp = (POINTER_TYPE)jtop;
		top = *(BASS_3DVECTOR **)&topTmp;
	}

	BOOL result_ = BASS_Set3DPosition(pos, vel, front, top);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Get3DPosition(JNIEnv *java_env, jclass jcls, jlong jpos, jlong jvel, jlong jfront, jlong jtop) {
	BASS_3DVECTOR *pos = 0;
	if(jpos) {
		POINTER_TYPE posTmp = (POINTER_TYPE)jpos;
		pos = *(BASS_3DVECTOR **)&posTmp;
	}
	BASS_3DVECTOR *vel = 0;
	if(jvel) {
		POINTER_TYPE velTmp = (POINTER_TYPE)jvel;
		vel = *(BASS_3DVECTOR **)&velTmp;
	}
	BASS_3DVECTOR *front = 0;
	if(jfront) {
		POINTER_TYPE frontTmp = (POINTER_TYPE)jfront;
		front = *(BASS_3DVECTOR **)&frontTmp;
	}
	BASS_3DVECTOR *top = 0;
	if(jtop) {
		POINTER_TYPE topTmp = (POINTER_TYPE)jtop;
		top = *(BASS_3DVECTOR **)&topTmp;
	}

	BOOL result_ = BASS_Get3DPosition(pos, vel, front, top);

	return (jboolean)(result_ != 0);
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1Apply3D(JNIEnv *java_env, jclass jcls) {

	 BASS_Apply3D();

}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SetEAXParameters(JNIEnv *java_env, jclass jcls, jint jenv, jfloat jvol, jfloat jdecay, jfloat jdamp) {
	int env = (int)jenv;
	float vol = (float)jvol;
	float decay = (float)jdecay;
	float damp = (float)jdamp;

	BOOL result_ = BASS_SetEAXParameters(env, vol, decay, damp);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1GetEAXParameters(JNIEnv *java_env, jclass jcls, jobject jenv, jlong jenv_, jobject jvol, jlong jvol_, jobject jdecay, jlong jdecay_, jobject jdamp, jlong jdamp_) {
	DWORD *env = 0;
	if(jenv) {
		env = (DWORD *)((char *)java_env->GetDirectBufferAddress(jenv)+jenv_);
	}
	float *vol = 0;
	if(jvol) {
		vol = (float *)((char *)java_env->GetDirectBufferAddress(jvol)+jvol_);
	}
	float *decay = 0;
	if(jdecay) {
		decay = (float *)((char *)java_env->GetDirectBufferAddress(jdecay)+jdecay_);
	}
	float *damp = 0;
	if(jdamp) {
		damp = (float *)((char *)java_env->GetDirectBufferAddress(jdamp)+jdamp_);
	}

	BOOL result_ = BASS_GetEAXParameters(env, vol, decay, damp);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1MusicLoad__ZJJIII(JNIEnv *java_env, jclass jcls, jboolean jmem, jlong jfile, jlong joffset, jint jlength, jint jflags, jint jfreq) {
	bool mem = (bool)(jmem != 0);
	POINTER_TYPE fileTmp = (POINTER_TYPE)jfile;
	void *file = *(void **)&fileTmp;
	QWORD offset = (QWORD)joffset;
	DWORD length = (DWORD)jlength;
	DWORD flags = (DWORD)jflags;
	DWORD freq = (DWORD)jfreq;

	HMUSIC cresult = BASS_MusicLoad(mem, file, offset, length, flags, freq);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1MusicLoad__Z_3BJIII(JNIEnv *java_env, jclass jcls, jboolean jmem, jbyteArray jfile, jlong joffset, jint jlength, jint jflags, jint jfreq) {
	bool mem = (bool)(jmem != 0);
	char *file = getByteArrayElements(java_env, jfile);
	QWORD offset = (QWORD)joffset;
	DWORD length = (DWORD)jlength;
	DWORD flags = (DWORD)jflags;
	DWORD freq = (DWORD)jfreq;

	HMUSIC cresult = BASS_MusicLoad(mem, file, offset, length, flags, freq);

	releaseByteArrayElements(java_env, jfile, (const char *)file);
	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1MusicFree(JNIEnv *java_env, jclass jcls, jlong jhandle) {
	HMUSIC handle = (HMUSIC)(ADDRESS_TYPE)jhandle;

	BOOL result_ = BASS_MusicFree(handle);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleLoad__ZJJIII(JNIEnv *java_env, jclass jcls, jboolean jmem, jlong jfile, jlong joffset, jint jlength, jint jmax, jint jflags) {
	bool mem = (bool)(jmem != 0);
	POINTER_TYPE fileTmp = (POINTER_TYPE)jfile;
	void *file = *(void **)&fileTmp;
	QWORD offset = (QWORD)joffset;
	DWORD length = (DWORD)jlength;
	DWORD max = (DWORD)jmax;
	DWORD flags = (DWORD)jflags;

	HSAMPLE cresult = BASS_SampleLoad(mem, file, offset, length, max, flags);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleLoad__Z_3BJIII(JNIEnv *java_env, jclass jcls, jboolean jmem, jbyteArray jfile, jlong joffset, jint jlength, jint jmax, jint jflags) {
	bool mem = (bool)(jmem != 0);
	char *file = getByteArrayElements(java_env, jfile);
	QWORD offset = (QWORD)joffset;
	DWORD length = (DWORD)jlength;
	DWORD max = (DWORD)jmax;
	DWORD flags = (DWORD)jflags;

	HSAMPLE cresult = BASS_SampleLoad(mem, file, offset, length, max, flags);

	releaseByteArrayElements(java_env, jfile, (const char *)file);
	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleCreate(JNIEnv *java_env, jclass jcls, jint jlength, jint jfreq, jint jchans, jint jmax, jint jflags) {
	DWORD length = (DWORD)jlength;
	DWORD freq = (DWORD)jfreq;
	DWORD chans = (DWORD)jchans;
	DWORD max = (DWORD)jmax;
	DWORD flags = (DWORD)jflags;

	HSAMPLE cresult = BASS_SampleCreate(length, freq, chans, max, flags);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleFree(JNIEnv *java_env, jclass jcls, jlong jhandle) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;

	BOOL result_ = BASS_SampleFree(handle);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleSetData(JNIEnv *java_env, jclass jcls, jlong jhandle, jlong jbuffer) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;
	POINTER_TYPE bufferTmp = (POINTER_TYPE)jbuffer;
	void *buffer = *(void **)&bufferTmp;

	BOOL result_ = BASS_SampleSetData(handle, buffer);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleGetData(JNIEnv *java_env, jclass jcls, jlong jhandle, jlong jbuffer) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;
	POINTER_TYPE bufferTmp = (POINTER_TYPE)jbuffer;
	void *buffer = *(void **)&bufferTmp;

	BOOL result_ = BASS_SampleGetData(handle, buffer);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleGetInfo(JNIEnv *java_env, jclass jcls, jlong jhandle, jobject jinfo, jlong jinfo_) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;
	BASS_SAMPLE *info = 0;
	if(jinfo) {
		info = (BASS_SAMPLE *)(int *)((char *)java_env->GetDirectBufferAddress(jinfo)+jinfo_);
	}

	BOOL result_ = BASS_SampleGetInfo(handle, info);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleSetInfo(JNIEnv *java_env, jclass jcls, jlong jhandle, jobject jinfo, jlong jinfo_) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;
	BASS_SAMPLE *info = 0;
	if(jinfo) {
		info = (BASS_SAMPLE *)(int *)((char *)java_env->GetDirectBufferAddress(jinfo)+jinfo_);
	}

	BOOL result_ = BASS_SampleSetInfo(handle, info);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleGetChannel(JNIEnv *java_env, jclass jcls, jlong jhandle, jboolean jonlynew) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;
	bool onlynew = (bool)(jonlynew != 0);

	HCHANNEL cresult = BASS_SampleGetChannel(handle, onlynew);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleGetChannels(JNIEnv *java_env, jclass jcls, jlong jhandle, jlong jchannels) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;
	ADDRESS_TYPE channelsTmp = (ADDRESS_TYPE)jchannels;
	HCHANNEL *channels = *(HCHANNEL **)&channelsTmp;

	DWORD result_ = BASS_SampleGetChannels(handle, channels);

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1SampleStop(JNIEnv *java_env, jclass jcls, jlong jhandle) {
	HSAMPLE handle = (HSAMPLE)(ADDRESS_TYPE)jhandle;

	BOOL result_ = BASS_SampleStop(handle);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamCreate__IIIZJ(JNIEnv *java_env, jclass jcls, jint jfreq, jint jchans, jint jflags, jboolean jproc, jlong juser) {
	DWORD freq = (DWORD)jfreq;
	DWORD chans = (DWORD)jchans;
	DWORD flags = (DWORD)jflags;
	POINTER_TYPE userTmp = (POINTER_TYPE)juser;
	void *user = *(void **)&userTmp;

	HSTREAM cresult = BASS_StreamCreate(freq, chans, flags, jproc == 0 ? NULL : STREAMPROC_BRIDGE, user);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamCreate__IIIIJ(JNIEnv *java_env, jclass jcls, jint jfreq, jint jchans, jint jflags, jint jproc, jlong juser) {
	DWORD freq = (DWORD)jfreq;
	DWORD chans = (DWORD)jchans;
	DWORD flags = (DWORD)jflags;
	STREAMPROC * proc = (STREAMPROC *)jproc;
	POINTER_TYPE userTmp = (POINTER_TYPE)juser;
	void *user = *(void **)&userTmp;

	HSTREAM cresult = BASS_StreamCreate(freq, chans, flags, proc, user);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamCreateFile__ZLjava_nio_ByteBuffer_2JJJI(JNIEnv *java_env, jclass jcls, jboolean jmem, jobject jfile, jlong jfile_, jlong joffset, jlong jlength, jint jflags) {
	bool mem = (bool)(jmem != 0);
	void *file = 0;
	if(jfile) {
		file = (void *)((char *)java_env->GetDirectBufferAddress(jfile)+jfile_);
	}
	QWORD offset = (QWORD)joffset;
	QWORD length = (QWORD)jlength;
	DWORD flags = (DWORD)jflags;

	HSTREAM cresult = BASS_StreamCreateFile(mem, file, offset, length, flags);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamCreateFile__Z_3BJJI(JNIEnv *java_env, jclass jcls, jboolean jmem, jbyteArray jfile, jlong joffset, jlong jlength, jint jflags) {
	bool mem = (bool)(jmem != 0);
	char *file = getByteArrayElements(java_env, jfile);
	QWORD offset = (QWORD)joffset;
	QWORD length = (QWORD)jlength;
	DWORD flags = (DWORD)jflags;

	HSTREAM cresult = BASS_StreamCreateFile(mem, file, offset, length, flags);

	releaseByteArrayElements(java_env, jfile, (const char *)file);
	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamCreateURL(JNIEnv *java_env, jclass jcls, jbyteArray jurl, jint joffset, jint jflags, jboolean jproc, jlong juser) {
	char *url = getByteArrayElements(java_env, jurl);
	DWORD offset = (DWORD)joffset;
	DWORD flags = (DWORD)jflags;
	POINTER_TYPE userTmp = (POINTER_TYPE)juser;
	void *user = *(void **)&userTmp;

	HSTREAM cresult = BASS_StreamCreateURL(url, offset, flags, jproc == 0 ? NULL : DOWNLOADPROC_BRIDGE, user);

	releaseByteArrayElements(java_env, jurl, (const char *)url);
	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamCreateFileUser(JNIEnv *java_env, jclass jcls, jint jsystem, jint jflags, jlong jproc, jlong juser) {
	DWORD system = (DWORD)jsystem;
	DWORD flags = (DWORD)jflags;
	BASS_FILEPROCS *proc = 0;
	if(jproc) {
		POINTER_TYPE procTmp = (POINTER_TYPE)jproc;
		proc = *(BASS_FILEPROCS **)&procTmp;
	}
	POINTER_TYPE userTmp = (POINTER_TYPE)juser;
	void *user = *(void **)&userTmp;

	HSTREAM cresult = BASS_StreamCreateFileUser(system, flags, proc, user);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamFree(JNIEnv *java_env, jclass jcls, jlong jhandle) {
	HSTREAM handle = (HSTREAM)(ADDRESS_TYPE)jhandle;

	BOOL result_ = BASS_StreamFree(handle);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamGetFilePosition(JNIEnv *java_env, jclass jcls, jlong jhandle, jint jmode) {
	HSTREAM handle = (HSTREAM)(ADDRESS_TYPE)jhandle;
	DWORD mode = (DWORD)jmode;

	QWORD result_ = BASS_StreamGetFilePosition(handle, mode);

	return (jlong)result_;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamPutData(JNIEnv *java_env, jclass jcls, jlong jhandle, jobject jbuffer, jlong jbuffer_, jint jlength) {
	HSTREAM handle = (HSTREAM)(ADDRESS_TYPE)jhandle;
	void *buffer = 0;
	if(jbuffer) {
		buffer = (void *)((char *)java_env->GetDirectBufferAddress(jbuffer)+jbuffer_);
	}
	DWORD length = (DWORD)jlength;

	DWORD result_ = BASS_StreamPutData(handle, buffer, length);

	return (jint)result_;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1StreamPutFileData(JNIEnv *java_env, jclass jcls, jlong jhandle, jlong jbuffer, jint jlength) {
	HSTREAM handle = (HSTREAM)(ADDRESS_TYPE)jhandle;
	POINTER_TYPE bufferTmp = (POINTER_TYPE)jbuffer;
	void *buffer = *(void **)&bufferTmp;
	DWORD length = (DWORD)jlength;

	DWORD result_ = BASS_StreamPutFileData(handle, buffer, length);

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordGetDeviceInfo(JNIEnv *java_env, jclass jcls, jint jdevice, jlong jinfo) {
	DWORD device = (DWORD)jdevice;
	BASS_DEVICEINFO *info = 0;
	if(jinfo) {
		POINTER_TYPE infoTmp = (POINTER_TYPE)jinfo;
		info = *(BASS_DEVICEINFO **)&infoTmp;
	}

	BOOL result_ = BASS_RecordGetDeviceInfo(device, info);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordInit(JNIEnv *java_env, jclass jcls, jint jdevice) {
	int device = (int)jdevice;

	BOOL result_ = BASS_RecordInit(device);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordSetDevice(JNIEnv *java_env, jclass jcls, jint jdevice) {
	DWORD device = (DWORD)jdevice;

	BOOL result_ = BASS_RecordSetDevice(device);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordGetDevice(JNIEnv *java_env, jclass jcls) {

	DWORD result_ = BASS_RecordGetDevice();

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordFree(JNIEnv *java_env, jclass jcls) {

	BOOL result_ = BASS_RecordFree();

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordGetInfo(JNIEnv *java_env, jclass jcls, jlong jinfo) {
	BASS_RECORDINFO *info = 0;
	if(jinfo) {
		POINTER_TYPE infoTmp = (POINTER_TYPE)jinfo;
		info = *(BASS_RECORDINFO **)&infoTmp;
	}

	BOOL result_ = BASS_RecordGetInfo(info);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordGetInputName(JNIEnv *java_env, jclass jcls, jint jinput) {
	int input = (int)jinput;

	const char * result_ = BASS_RecordGetInputName(input);

	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF((const char *)result_);
	}
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordSetInput(JNIEnv *java_env, jclass jcls, jint jinput, jint jflags, jfloat jvolume) {
	int input = (int)jinput;
	DWORD flags = (DWORD)jflags;
	float volume = (float)jvolume;

	BOOL result_ = BASS_RecordSetInput(input, flags, volume);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordGetInput(JNIEnv *java_env, jclass jcls, jint jinput, jobject jvolume, jlong jvolume_) {
	int input = (int)jinput;
	float *volume = 0;
	if(jvolume) {
		volume = (float *)((char *)java_env->GetDirectBufferAddress(jvolume)+jvolume_);
	}

	DWORD result_ = BASS_RecordGetInput(input, volume);

	return (jint)result_;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1RecordStart(JNIEnv *java_env, jclass jcls, jint jfreq, jint jchans, jint jflags, jboolean jproc, jlong juser) {
	DWORD freq = (DWORD)jfreq;
	DWORD chans = (DWORD)jchans;
	DWORD flags = (DWORD)jflags;
	POINTER_TYPE userTmp = (POINTER_TYPE)juser;
	void *user = *(void **)&userTmp;

	HRECORD cresult = BASS_RecordStart(freq, chans, flags, jproc == 0 ? NULL : RECORDPROC_BRIDGE, user);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jdouble JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelBytes2Seconds(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jpos) {
	DWORD handle = (DWORD)jhandle;
	QWORD pos = (QWORD)jpos;

	double result_ = BASS_ChannelBytes2Seconds(handle, pos);

	return (jdouble)result_;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSeconds2Bytes(JNIEnv *java_env, jclass jcls, jint jhandle, jdouble jpos) {
	DWORD handle = (DWORD)jhandle;
	double pos = (double)jpos;

	QWORD result_ = BASS_ChannelSeconds2Bytes(handle, pos);

	return (jlong)result_;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetDevice(JNIEnv *java_env, jclass jcls, jint jhandle) {
	DWORD handle = (DWORD)jhandle;

	DWORD result_ = BASS_ChannelGetDevice(handle);

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSetDevice(JNIEnv *java_env, jclass jcls, jint jhandle, jint jdevice) {
	DWORD handle = (DWORD)jhandle;
	DWORD device = (DWORD)jdevice;

	BOOL result_ = BASS_ChannelSetDevice(handle, device);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelIsActive(JNIEnv *java_env, jclass jcls, jint jhandle) {
	DWORD handle = (DWORD)jhandle;

	DWORD result_ = BASS_ChannelIsActive(handle);

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetInfo(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jinfo) {
	DWORD handle = (DWORD)jhandle;
	BASS_CHANNELINFO *info = 0;
	if(jinfo) {
		POINTER_TYPE infoTmp = (POINTER_TYPE)jinfo;
		info = *(BASS_CHANNELINFO **)&infoTmp;
	}

	BOOL result_ = BASS_ChannelGetInfo(handle, info);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetTags(JNIEnv *java_env, jclass jcls, jint jhandle, jint jtags) {
	DWORD handle = (DWORD)jhandle;
	DWORD tags = (DWORD)jtags;

	const char *result_ = BASS_ChannelGetTags(handle, tags);

	POINTER_TYPE jresult;
	if(result_) {
		*(const char **)&jresult = result_;
	} else {
		jresult = 0;
	}

	return (jlong)jresult;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelFlags(JNIEnv *java_env, jclass jcls, jint jhandle, jint jflags, jint jmask) {
	DWORD handle = (DWORD)jhandle;
	DWORD flags = (DWORD)jflags;
	DWORD mask = (DWORD)jmask;

	DWORD result_ = BASS_ChannelFlags(handle, flags, mask);

	return (jint)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelUpdate(JNIEnv *java_env, jclass jcls, jint jhandle, jint jlength) {
	DWORD handle = (DWORD)jhandle;
	DWORD length = (DWORD)jlength;

	BOOL result_ = BASS_ChannelUpdate(handle, length);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelLock(JNIEnv *java_env, jclass jcls, jint jhandle, jboolean jlock) {
	DWORD handle = (DWORD)jhandle;
	bool lock = (bool)(jlock != 0);

	BOOL result_ = BASS_ChannelLock(handle, lock);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelPlay(JNIEnv *java_env, jclass jcls, jint jhandle, jboolean jrestart) {
	DWORD handle = (DWORD)jhandle;
	bool restart = (bool)(jrestart != 0);

	BOOL result_ = BASS_ChannelPlay(handle, restart);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelStop(JNIEnv *java_env, jclass jcls, jint jhandle) {
	DWORD handle = (DWORD)jhandle;

	BOOL result_ = BASS_ChannelStop(handle);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelPause(JNIEnv *java_env, jclass jcls, jint jhandle) {
	DWORD handle = (DWORD)jhandle;

	BOOL result_ = BASS_ChannelPause(handle);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSetAttribute(JNIEnv *java_env, jclass jcls, jint jhandle, jint jattrib, jfloat jvalue) {
	DWORD handle = (DWORD)jhandle;
	DWORD attrib = (DWORD)jattrib;
	float value = (float)jvalue;

	BOOL result_ = BASS_ChannelSetAttribute(handle, attrib, value);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetAttribute(JNIEnv *java_env, jclass jcls, jint jhandle, jint jattrib, jobject jvalue, jlong jvalue_) {
	DWORD handle = (DWORD)jhandle;
	DWORD attrib = (DWORD)jattrib;
	float *value = 0;
	if(jvalue) {
		value = (float *)((char *)java_env->GetDirectBufferAddress(jvalue)+jvalue_);
	}

	BOOL result_ = BASS_ChannelGetAttribute(handle, attrib, value);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSlideAttribute(JNIEnv *java_env, jclass jcls, jint jhandle, jint jattrib, jfloat jvalue, jint jtime) {
	DWORD handle = (DWORD)jhandle;
	DWORD attrib = (DWORD)jattrib;
	float value = (float)jvalue;
	DWORD time = (DWORD)jtime;

	BOOL result_ = BASS_ChannelSlideAttribute(handle, attrib, value, time);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelIsSliding(JNIEnv *java_env, jclass jcls, jint jhandle, jint jattrib) {
	DWORD handle = (DWORD)jhandle;
	DWORD attrib = (DWORD)jattrib;

	BOOL result_ = BASS_ChannelIsSliding(handle, attrib);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSet3DAttributes(JNIEnv *java_env, jclass jcls, jint jhandle, jint jmode, jfloat jmin, jfloat jmax, jint jiangle, jint joangle, jfloat joutvol) {
	DWORD handle = (DWORD)jhandle;
	int mode = (int)jmode;
	float min = (float)jmin;
	float max = (float)jmax;
	int iangle = (int)jiangle;
	int oangle = (int)joangle;
	float outvol = (float)joutvol;

	BOOL result_ = BASS_ChannelSet3DAttributes(handle, mode, min, max, iangle, oangle, outvol);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGet3DAttributes(JNIEnv *java_env, jclass jcls, jint jhandle, jobject jmode, jlong jmode_, jobject jmin, jlong jmin_, jobject jmax, jlong jmax_, jobject jiangle, jlong jiangle_, jobject joangle, jlong joangle_, jobject joutvol, jlong joutvol_) {
	DWORD handle = (DWORD)jhandle;
	DWORD *mode = 0;
	if(jmode) {
		mode = (DWORD *)((char *)java_env->GetDirectBufferAddress(jmode)+jmode_);
	}
	float *min = 0;
	if(jmin) {
		min = (float *)((char *)java_env->GetDirectBufferAddress(jmin)+jmin_);
	}
	float *max = 0;
	if(jmax) {
		max = (float *)((char *)java_env->GetDirectBufferAddress(jmax)+jmax_);
	}
	DWORD *iangle = 0;
	if(jiangle) {
		iangle = (DWORD *)((char *)java_env->GetDirectBufferAddress(jiangle)+jiangle_);
	}
	DWORD *oangle = 0;
	if(joangle) {
		oangle = (DWORD *)((char *)java_env->GetDirectBufferAddress(joangle)+joangle_);
	}
	float *outvol = 0;
	if(joutvol) {
		outvol = (float *)((char *)java_env->GetDirectBufferAddress(joutvol)+joutvol_);
	}

	BOOL result_ = BASS_ChannelGet3DAttributes(handle, mode, min, max, iangle, oangle, outvol);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSet3DPosition(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jpos, jlong jorient, jlong jvel) {
	DWORD handle = (DWORD)jhandle;
	BASS_3DVECTOR *pos = 0;
	if(jpos) {
		POINTER_TYPE posTmp = (POINTER_TYPE)jpos;
		pos = *(BASS_3DVECTOR **)&posTmp;
	}
	BASS_3DVECTOR *orient = 0;
	if(jorient) {
		POINTER_TYPE orientTmp = (POINTER_TYPE)jorient;
		orient = *(BASS_3DVECTOR **)&orientTmp;
	}
	BASS_3DVECTOR *vel = 0;
	if(jvel) {
		POINTER_TYPE velTmp = (POINTER_TYPE)jvel;
		vel = *(BASS_3DVECTOR **)&velTmp;
	}

	BOOL result_ = BASS_ChannelSet3DPosition(handle, pos, orient, vel);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGet3DPosition(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jpos, jlong jorient, jlong jvel) {
	DWORD handle = (DWORD)jhandle;
	BASS_3DVECTOR *pos = 0;
	if(jpos) {
		POINTER_TYPE posTmp = (POINTER_TYPE)jpos;
		pos = *(BASS_3DVECTOR **)&posTmp;
	}
	BASS_3DVECTOR *orient = 0;
	if(jorient) {
		POINTER_TYPE orientTmp = (POINTER_TYPE)jorient;
		orient = *(BASS_3DVECTOR **)&orientTmp;
	}
	BASS_3DVECTOR *vel = 0;
	if(jvel) {
		POINTER_TYPE velTmp = (POINTER_TYPE)jvel;
		vel = *(BASS_3DVECTOR **)&velTmp;
	}

	BOOL result_ = BASS_ChannelGet3DPosition(handle, pos, orient, vel);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetLength(JNIEnv *java_env, jclass jcls, jint jhandle, jint jmode) {
	DWORD handle = (DWORD)jhandle;
	DWORD mode = (DWORD)jmode;

	QWORD result_ = BASS_ChannelGetLength(handle, mode);

	return (jlong)result_;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSetPosition(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jpos, jint jmode) {
	DWORD handle = (DWORD)jhandle;
	QWORD pos = (QWORD)jpos;
	DWORD mode = (DWORD)jmode;

	BOOL result_ = BASS_ChannelSetPosition(handle, pos, mode);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetPosition(JNIEnv *java_env, jclass jcls, jint jhandle, jint jmode) {
	DWORD handle = (DWORD)jhandle;
	DWORD mode = (DWORD)jmode;

	QWORD result_ = BASS_ChannelGetPosition(handle, mode);

	return (jlong)result_;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetLevel(JNIEnv *java_env, jclass jcls, jint jhandle) {
	DWORD handle = (DWORD)jhandle;

	DWORD result_ = BASS_ChannelGetLevel(handle);

	return (jint)result_;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelGetData(JNIEnv *java_env, jclass jcls, jint jhandle, jobject jbuffer, jlong jbuffer_, jint jlength) {
	DWORD handle = (DWORD)jhandle;
	void *buffer = 0;
	if(jbuffer) {
		buffer = (void *)((char *)java_env->GetDirectBufferAddress(jbuffer)+jbuffer_);
	}
	DWORD length = (DWORD)jlength;

	DWORD result_ = BASS_ChannelGetData(handle, buffer, length);

	return (jint)result_;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSetSync(JNIEnv *java_env, jclass jcls, jint jhandle, jint jtype, jlong jparam, jboolean jproc, jlong juser) {
	DWORD handle = (DWORD)jhandle;
	DWORD type = (DWORD)jtype;
	QWORD param = (QWORD)jparam;
	POINTER_TYPE userTmp = (POINTER_TYPE)juser;
	void *user = *(void **)&userTmp;

	HSYNC cresult = BASS_ChannelSetSync(handle, type, param, jproc == 0 ? NULL : SYNCPROC_BRIDGE, user);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelRemoveSync(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jsync) {
	DWORD handle = (DWORD)jhandle;
	HSYNC sync = (HSYNC)(ADDRESS_TYPE)jsync;

	BOOL result_ = BASS_ChannelRemoveSync(handle, sync);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSetDSP(JNIEnv *java_env, jclass jcls, jint jhandle, jboolean jproc, jlong juser, jint jpriority) {
	DWORD handle = (DWORD)jhandle;
	POINTER_TYPE userTmp = (POINTER_TYPE)juser;
	void *user = *(void **)&userTmp;
	int priority = (int)jpriority;

	HDSP cresult = BASS_ChannelSetDSP(handle, jproc == 0 ? NULL : DSPPROC_BRIDGE, user, priority);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelRemoveDSP(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jdsp) {
	DWORD handle = (DWORD)jhandle;
	HDSP dsp = (HDSP)(ADDRESS_TYPE)jdsp;

	BOOL result_ = BASS_ChannelRemoveDSP(handle, dsp);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSetLink(JNIEnv *java_env, jclass jcls, jint jhandle, jint jchan) {
	DWORD handle = (DWORD)jhandle;
	DWORD chan = (DWORD)jchan;

	BOOL result_ = BASS_ChannelSetLink(handle, chan);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelRemoveLink(JNIEnv *java_env, jclass jcls, jint jhandle, jint jchan) {
	DWORD handle = (DWORD)jhandle;
	DWORD chan = (DWORD)jchan;

	BOOL result_ = BASS_ChannelRemoveLink(handle, chan);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelSetFX(JNIEnv *java_env, jclass jcls, jint jhandle, jint jtype, jint jpriority) {
	DWORD handle = (DWORD)jhandle;
	DWORD type = (DWORD)jtype;
	int priority = (int)jpriority;

	HFX cresult = BASS_ChannelSetFX(handle, type, priority);

	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1ChannelRemoveFX(JNIEnv *java_env, jclass jcls, jint jhandle, jlong jfx) {
	DWORD handle = (DWORD)jhandle;
	HFX fx = (HFX)(ADDRESS_TYPE)jfx;

	BOOL result_ = BASS_ChannelRemoveFX(handle, fx);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1FXSetParameters(JNIEnv *java_env, jclass jcls, jlong jhandle, jlong jparams) {
	HFX handle = (HFX)(ADDRESS_TYPE)jhandle;
	POINTER_TYPE paramsTmp = (POINTER_TYPE)jparams;
	void *params = *(void **)&paramsTmp;

	BOOL result_ = BASS_FXSetParameters(handle, params);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1FXGetParameters(JNIEnv *java_env, jclass jcls, jlong jhandle, jlong jparams) {
	HFX handle = (HFX)(ADDRESS_TYPE)jhandle;
	POINTER_TYPE paramsTmp = (POINTER_TYPE)jparams;
	void *params = *(void **)&paramsTmp;

	BOOL result_ = BASS_FXGetParameters(handle, params);

	return (jboolean)(result_ != 0);
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_BassJNI_Bass_1BASS_1FXReset(JNIEnv *java_env, jclass jcls, jlong jhandle) {
	HFX handle = (HFX)(ADDRESS_TYPE)jhandle;

	BOOL result_ = BASS_FXReset(handle);

	return (jboolean)(result_ != 0);
}


