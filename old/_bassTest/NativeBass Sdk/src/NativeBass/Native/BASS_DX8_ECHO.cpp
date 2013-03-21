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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1new(JNIEnv *java_env, jclass jcls) {
	BASS_DX8_ECHO *result_ = new BASS_DX8_ECHO();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_DX8_ECHO **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_DX8_ECHO **)&pointer;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1get_1fWetDryMix(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_ECHO **)&pointer)->fWetDryMix;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1set_1fWetDryMix(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfWetDryMix) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fWetDryMix = (float)jfWetDryMix;
	(*(BASS_DX8_ECHO **)&pointer)->fWetDryMix = fWetDryMix;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1get_1fFeedback(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_ECHO **)&pointer)->fFeedback;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1set_1fFeedback(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfFeedback) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fFeedback = (float)jfFeedback;
	(*(BASS_DX8_ECHO **)&pointer)->fFeedback = fFeedback;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1get_1fLeftDelay(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_ECHO **)&pointer)->fLeftDelay;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1set_1fLeftDelay(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfLeftDelay) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fLeftDelay = (float)jfLeftDelay;
	(*(BASS_DX8_ECHO **)&pointer)->fLeftDelay = fLeftDelay;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1get_1fRightDelay(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_ECHO **)&pointer)->fRightDelay;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1set_1fRightDelay(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfRightDelay) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fRightDelay = (float)jfRightDelay;
	(*(BASS_DX8_ECHO **)&pointer)->fRightDelay = fRightDelay;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1get_1lPanDelay(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	BOOL result_ = (*(BASS_DX8_ECHO **)&pointer)->lPanDelay;
	return (jboolean)(result_ != 0);
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1ECHO_1set_1lPanDelay(JNIEnv *java_env, jclass jcls, jlong jpointer, jboolean jlPanDelay) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_ECHO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	BOOL lPanDelay = (BOOL)(jlPanDelay != 0);
	(*(BASS_DX8_ECHO **)&pointer)->lPanDelay = lPanDelay;
}



