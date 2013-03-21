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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1new(JNIEnv *java_env, jclass jcls) {
	BASS_DX8_I3DL2REVERB *result_ = new BASS_DX8_I3DL2REVERB();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_DX8_I3DL2REVERB **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_DX8_I3DL2REVERB **)&pointer;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1lRoom(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->lRoom;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1lRoom(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jlRoom) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int lRoom = (int)jlRoom;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->lRoom = lRoom;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1lRoomHF(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->lRoomHF;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1lRoomHF(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jlRoomHF) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int lRoomHF = (int)jlRoomHF;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->lRoomHF = lRoomHF;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flRoomRolloffFactor(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flRoomRolloffFactor;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flRoomRolloffFactor(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflRoomRolloffFactor) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flRoomRolloffFactor = (float)jflRoomRolloffFactor;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flRoomRolloffFactor = flRoomRolloffFactor;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flDecayTime(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flDecayTime;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flDecayTime(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflDecayTime) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flDecayTime = (float)jflDecayTime;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flDecayTime = flDecayTime;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flDecayHFRatio(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flDecayHFRatio;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flDecayHFRatio(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflDecayHFRatio) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flDecayHFRatio = (float)jflDecayHFRatio;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flDecayHFRatio = flDecayHFRatio;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1lReflections(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->lReflections;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1lReflections(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jlReflections) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int lReflections = (int)jlReflections;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->lReflections = lReflections;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flReflectionsDelay(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flReflectionsDelay;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flReflectionsDelay(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflReflectionsDelay) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flReflectionsDelay = (float)jflReflectionsDelay;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flReflectionsDelay = flReflectionsDelay;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1lReverb(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->lReverb;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1lReverb(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jlReverb) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	int lReverb = (int)jlReverb;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->lReverb = lReverb;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flReverbDelay(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flReverbDelay;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flReverbDelay(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflReverbDelay) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flReverbDelay = (float)jflReverbDelay;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flReverbDelay = flReverbDelay;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flDiffusion(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flDiffusion;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flDiffusion(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflDiffusion) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flDiffusion = (float)jflDiffusion;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flDiffusion = flDiffusion;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flDensity(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flDensity;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flDensity(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflDensity) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flDensity = (float)jflDensity;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flDensity = flDensity;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1get_1flHFReference(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_DX8_I3DL2REVERB **)&pointer)->flHFReference;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1DX8_1I3DL2REVERB_1set_1flHFReference(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jflHFReference) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_DX8_I3DL2REVERB);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float flHFReference = (float)jflHFReference;
	(*(BASS_DX8_I3DL2REVERB **)&pointer)->flHFReference = flHFReference;
}



