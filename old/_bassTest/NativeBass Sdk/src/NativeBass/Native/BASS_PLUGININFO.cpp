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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1new(JNIEnv *java_env, jclass jcls) {
	BASS_PLUGININFO *result_ = new BASS_PLUGININFO();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_PLUGININFO **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_PLUGININFO **)&pointer;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1get_1version(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGININFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_PLUGININFO **)&pointer)->version;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1set_1version(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jversion) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGININFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD version = (DWORD)jversion;
	(*(BASS_PLUGININFO **)&pointer)->version = version;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1get_1formatc(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGININFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_PLUGININFO **)&pointer)->formatc;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1set_1formatc(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jformatc) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGININFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD formatc = (DWORD)jformatc;
	(*(BASS_PLUGININFO **)&pointer)->formatc = formatc;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1get_1formats(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGININFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	POINTER_TYPE jresult/* = 0*/;
	*(const BASS_PLUGINFORM **)&jresult = (*(BASS_PLUGININFO **)&pointer)->formats;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGININFO_1set_1formats(JNIEnv *java_env, jclass jcls, jlong jpointer, jlong jformats) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGININFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	POINTER_TYPE formatsTmp = (POINTER_TYPE)jformats;
	(*(BASS_PLUGININFO **)&pointer)->formats = *(BASS_PLUGINFORM **)&formatsTmp;
}



