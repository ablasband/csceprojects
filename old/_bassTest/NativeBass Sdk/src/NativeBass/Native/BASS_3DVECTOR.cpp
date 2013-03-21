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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1create(JNIEnv *java_env, jclass jcls, jfloat x, jfloat y, jfloat z) {
	BASS_3DVECTOR *result_ = new BASS_3DVECTOR((float)x, (float)y, (float)z);
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_3DVECTOR **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1new(JNIEnv *java_env, jclass jcls) {
	BASS_3DVECTOR *result_ = new BASS_3DVECTOR();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_3DVECTOR **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_3DVECTOR **)&pointer;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1get_1x(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_3DVECTOR **)&pointer)->x;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1set_1x(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jx) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float x = (float)jx;
	(*(BASS_3DVECTOR **)&pointer)->x = x;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1get_1y(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_3DVECTOR **)&pointer)->y;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1set_1y(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jy) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float y = (float)jy;
	(*(BASS_3DVECTOR **)&pointer)->y = y;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1get_1z(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_3DVECTOR **)&pointer)->z;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1set_1z(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jz) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float z = (float)jz;
	(*(BASS_3DVECTOR **)&pointer)->z = z;
}


JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1set_1xyz__JJ(JNIEnv *java_env, jclass jcls, jlong jpointer, jlong jvector) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	if(jvector) {
		POINTER_TYPE vector = (POINTER_TYPE)jvector;
		BASS_3DVECTOR *pointer_ = *(BASS_3DVECTOR **)&pointer;
		BASS_3DVECTOR *vector_ = *(BASS_3DVECTOR **)&vector;
		
		pointer_->x = vector_->x;
		pointer_->y = vector_->y;
		pointer_->z = vector_->z;
	}
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_13DVECTOR_1set_1xyz__JFFF(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat x, jfloat y, jfloat z) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_3DVECTOR);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	BASS_3DVECTOR *pointer_ = *(BASS_3DVECTOR **)&pointer;
	pointer_->x = (float)x;
	pointer_->y = (float)y;
	pointer_->z = (float)z;
}


