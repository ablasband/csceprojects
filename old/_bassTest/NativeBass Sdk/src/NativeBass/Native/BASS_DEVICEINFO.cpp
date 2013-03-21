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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1new(JNIEnv *java_env, jclass jcls) {
	BASS_DEVICEINFO *result_ = new BASS_DEVICEINFO();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_DEVICEINFO **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_DEVICEINFO **)&pointer;
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1get_1name(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DEVICEINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	const char *result_ = (const char *)((*(BASS_DEVICEINFO **)&pointer)->name);
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1set_1name(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jname) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DEVICEINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *name = 0;
	if(jname) {
		name = getByteArrayElements(java_env, jname);
		(*(BASS_DEVICEINFO **)&pointer)->name = name;
	}
	else {
		(*(BASS_DEVICEINFO **)&pointer)->name = (char *)0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1get_1driver(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DEVICEINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	const char *result_ = (const char *)((*(BASS_DEVICEINFO **)&pointer)->driver);
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1set_1driver(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jdriver) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DEVICEINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *driver = 0;
	if(jdriver) {
		driver = getByteArrayElements(java_env, jdriver);
		(*(BASS_DEVICEINFO **)&pointer)->driver = driver;
	}
	else {
		(*(BASS_DEVICEINFO **)&pointer)->driver = (char *)0;
	}
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1get_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DEVICEINFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_DEVICEINFO **)&pointer)->flags;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DEVICEINFO_1set_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jflags) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DEVICEINFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD flags = (DWORD)jflags;
	(*(BASS_DEVICEINFO **)&pointer)->flags = flags;
}



