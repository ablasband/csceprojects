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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1new(JNIEnv *java_env, jclass jcls) {
	BASS_DX8_COMPRESSOR *result_ = new BASS_DX8_COMPRESSOR();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_DX8_COMPRESSOR **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_DX8_COMPRESSOR **)&pointer;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1get_1fGain(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_COMPRESSOR **)&pointer)->fGain;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1set_1fGain(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfGain) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fGain = (float)jfGain;
	(*(BASS_DX8_COMPRESSOR **)&pointer)->fGain = fGain;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1get_1fAttack(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_COMPRESSOR **)&pointer)->fAttack;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1set_1fAttack(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfAttack) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fAttack = (float)jfAttack;
	(*(BASS_DX8_COMPRESSOR **)&pointer)->fAttack = fAttack;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1get_1fRelease(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_COMPRESSOR **)&pointer)->fRelease;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1set_1fRelease(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfRelease) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fRelease = (float)jfRelease;
	(*(BASS_DX8_COMPRESSOR **)&pointer)->fRelease = fRelease;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1get_1fThreshold(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_COMPRESSOR **)&pointer)->fThreshold;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1set_1fThreshold(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfThreshold) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fThreshold = (float)jfThreshold;
	(*(BASS_DX8_COMPRESSOR **)&pointer)->fThreshold = fThreshold;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1get_1fRatio(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_COMPRESSOR **)&pointer)->fRatio;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1set_1fRatio(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfRatio) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fRatio = (float)jfRatio;
	(*(BASS_DX8_COMPRESSOR **)&pointer)->fRatio = fRatio;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1get_1fPredelay(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_COMPRESSOR **)&pointer)->fPredelay;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1COMPRESSOR_1set_1fPredelay(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jfPredelay) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_COMPRESSOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float fPredelay = (float)jfPredelay;
	(*(BASS_DX8_COMPRESSOR **)&pointer)->fPredelay = fPredelay;
}



