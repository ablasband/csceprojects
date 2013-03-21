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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1GARGLE_1new(JNIEnv *java_env, jclass jcls) {
	BASS_DX8_GARGLE *result_ = new BASS_DX8_GARGLE();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_DX8_GARGLE **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1GARGLE_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_DX8_GARGLE **)&pointer;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1GARGLE_1get_1dwRateHz(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_GARGLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_DX8_GARGLE **)&pointer)->dwRateHz;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1GARGLE_1set_1dwRateHz(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jdwRateHz) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_GARGLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD dwRateHz = (DWORD)jdwRateHz;
	(*(BASS_DX8_GARGLE **)&pointer)->dwRateHz = dwRateHz;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1GARGLE_1get_1dwWaveShape(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_GARGLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_DX8_GARGLE **)&pointer)->dwWaveShape;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1GARGLE_1set_1dwWaveShape(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jdwWaveShape) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_GARGLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD dwWaveShape = (DWORD)jdwWaveShape;
	(*(BASS_DX8_GARGLE **)&pointer)->dwWaveShape = dwWaveShape;
}



