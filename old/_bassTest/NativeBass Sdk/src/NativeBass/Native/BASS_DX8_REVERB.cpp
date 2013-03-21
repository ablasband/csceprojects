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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1new(JNIEnv *java_env, jclass jcls) {
	BASS_DX8_REVERB *result_ = new BASS_DX8_REVERB();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_DX8_REVERB **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_DX8_REVERB **)&pointer;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1get_1fInGain(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_REVERB **)&pointer)->fInGain;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1set_1fInGain(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfInGain) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fInGain = (float)jfInGain;
	(*(BASS_DX8_REVERB **)&pointer)->fInGain = fInGain;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1get_1fReverbMix(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_REVERB **)&pointer)->fReverbMix;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1set_1fReverbMix(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfReverbMix) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fReverbMix = (float)jfReverbMix;
	(*(BASS_DX8_REVERB **)&pointer)->fReverbMix = fReverbMix;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1get_1fReverbTime(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_REVERB **)&pointer)->fReverbTime;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1set_1fReverbTime(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfReverbTime) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fReverbTime = (float)jfReverbTime;
	(*(BASS_DX8_REVERB **)&pointer)->fReverbTime = fReverbTime;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1get_1fHighFreqRTRatio(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_REVERB **)&pointer)->fHighFreqRTRatio;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1REVERB_1set_1fHighFreqRTRatio(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfHighFreqRTRatio) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fHighFreqRTRatio = (float)jfHighFreqRTRatio;
	(*(BASS_DX8_REVERB **)&pointer)->fHighFreqRTRatio = fHighFreqRTRatio;
}



