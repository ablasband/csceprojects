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
#include "org_jouvieje_bass_structures_StructureJNI.h"
#include "CallbackManager.h"

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1new(JNIEnv *java_env, jclass jcls) {
	BASS_CHANNELINFO *result_ = new BASS_CHANNELINFO();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_CHANNELINFO **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_CHANNELINFO **)&pointer;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1freq(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_CHANNELINFO **)&pointer)->freq;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1freq(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jfreq) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD freq = (DWORD)jfreq;
	(*(BASS_CHANNELINFO **)&pointer)->freq = freq;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1chans(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_CHANNELINFO **)&pointer)->chans;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1chans(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jchans) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD chans = (DWORD)jchans;
	(*(BASS_CHANNELINFO **)&pointer)->chans = chans;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_CHANNELINFO **)&pointer)->flags;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jflags) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD flags = (DWORD)jflags;
	(*(BASS_CHANNELINFO **)&pointer)->flags = flags;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1ctype(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_CHANNELINFO **)&pointer)->ctype;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1ctype(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jctype) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD ctype = (DWORD)jctype;
	(*(BASS_CHANNELINFO **)&pointer)->ctype = ctype;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1origres(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_CHANNELINFO **)&pointer)->origres;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1origres(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jorigres) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD origres = (DWORD)jorigres;
	(*(BASS_CHANNELINFO **)&pointer)->origres = origres;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1plugin(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	HPLUGIN cresult = (*(BASS_CHANNELINFO **)&pointer)->plugin;
	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1plugin(JNIEnv *java_env, jclass jcls, jlong jpointer, jlong jplugin) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	HPLUGIN cresult = (HPLUGIN)(ADDRESS_TYPE)jplugin;
	(*(BASS_CHANNELINFO **)&pointer)->plugin = cresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1sample(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	HSAMPLE cresult = (*(BASS_CHANNELINFO **)&pointer)->sample;
	jlong jresult = (jlong)(ADDRESS_TYPE)cresult;
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1sample(JNIEnv *java_env, jclass jcls, jlong jpointer, jlong jsample) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	HSAMPLE cresult = (HSAMPLE)(ADDRESS_TYPE)jsample;
	(*(BASS_CHANNELINFO **)&pointer)->sample = cresult;
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1get_1filename(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	const char *result_ = (const char *)((*(BASS_CHANNELINFO **)&pointer)->filename);
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1CHANNELINFO_1set_1filename(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jfilename) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_CHANNELINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *filename = 0;
	if(jfilename) {
		filename = getByteArrayElements(java_env, jfilename);
		(*(BASS_CHANNELINFO **)&pointer)->filename = filename;
	}
	else {
		(*(BASS_CHANNELINFO **)&pointer)->filename = (char *)0;
	}
}



