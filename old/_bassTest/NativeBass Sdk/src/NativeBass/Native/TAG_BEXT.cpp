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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1new(JNIEnv *java_env, jclass jcls) {
	TAG_BEXT *result_ = new TAG_BEXT();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(TAG_BEXT **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(TAG_BEXT **)&pointer;
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1Description(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_BEXT **)&pointer)->Description;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1Description(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jDescription) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *Description = 0;
	if(jDescription) {
		Description = (char *)getByteArrayElements(java_env, jDescription);
		if(Description) {
			strncpy((char *)((*(TAG_BEXT **)&pointer)->Description), Description, 256);
		}
		releaseByteArrayElements(java_env, jDescription, Description);
	}
	else {
		(*(TAG_BEXT **)&pointer)->Description[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1Originator(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_BEXT **)&pointer)->Originator;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1Originator(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jOriginator) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *Originator = 0;
	if(jOriginator) {
		Originator = (char *)getByteArrayElements(java_env, jOriginator);
		if(Originator) {
			strncpy((char *)((*(TAG_BEXT **)&pointer)->Originator), Originator, 32);
		}
		releaseByteArrayElements(java_env, jOriginator, Originator);
	}
	else {
		(*(TAG_BEXT **)&pointer)->Originator[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1OriginatorReference(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_BEXT **)&pointer)->OriginatorReference;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1OriginatorReference(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jOriginatorReference) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *OriginatorReference = 0;
	if(jOriginatorReference) {
		OriginatorReference = (char *)getByteArrayElements(java_env, jOriginatorReference);
		if(OriginatorReference) {
			strncpy((char *)((*(TAG_BEXT **)&pointer)->OriginatorReference), OriginatorReference, 32);
		}
		releaseByteArrayElements(java_env, jOriginatorReference, OriginatorReference);
	}
	else {
		(*(TAG_BEXT **)&pointer)->OriginatorReference[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1OriginationDate(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_BEXT **)&pointer)->OriginationDate;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1OriginationDate(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jOriginationDate) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *OriginationDate = 0;
	if(jOriginationDate) {
		OriginationDate = (char *)getByteArrayElements(java_env, jOriginationDate);
		if(OriginationDate) {
			strncpy((char *)((*(TAG_BEXT **)&pointer)->OriginationDate), OriginationDate, 10);
		}
		releaseByteArrayElements(java_env, jOriginationDate, OriginationDate);
	}
	else {
		(*(TAG_BEXT **)&pointer)->OriginationDate[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1OriginationTime(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_BEXT **)&pointer)->OriginationTime;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1OriginationTime(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jOriginationTime) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *OriginationTime = 0;
	if(jOriginationTime) {
		OriginationTime = (char *)getByteArrayElements(java_env, jOriginationTime);
		if(OriginationTime) {
			strncpy((char *)((*(TAG_BEXT **)&pointer)->OriginationTime), OriginationTime, 8);
		}
		releaseByteArrayElements(java_env, jOriginationTime, OriginationTime);
	}
	else {
		(*(TAG_BEXT **)&pointer)->OriginationTime[0] = 0;
	}
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1TimeReference(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	QWORD result_ = (*(TAG_BEXT **)&pointer)->TimeReference;
	return (jlong)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1TimeReference(JNIEnv *java_env, jclass jcls, jlong jpointer, jlong jTimeReference) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	QWORD TimeReference = (QWORD)jTimeReference;
	(*(TAG_BEXT **)&pointer)->TimeReference = TimeReference;
}

JNIEXPORT jshort JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1Version(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	WORD result_ = (*(TAG_BEXT **)&pointer)->Version;
	return (jshort)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1Version(JNIEnv *java_env, jclass jcls, jlong jpointer, jshort jVersion) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	WORD Version = (WORD)jVersion;
	(*(TAG_BEXT **)&pointer)->Version = Version;
}

JNIEXPORT jobject JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1UMID(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_BEXT **)&pointer)->UMID;
	jobject jresult = 0;
	if(result_) {
		jresult = java_env->NewDirectByteBuffer((BYTE *)result_, 64);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1UMID(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jUMID) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *UMID = 0;
	if(jUMID) {
		UMID = (char *)getByteArrayElements(java_env, jUMID);
		if(UMID) {
			strncpy((char *)((*(TAG_BEXT **)&pointer)->UMID), UMID, 64);
		}
		releaseByteArrayElements(java_env, jUMID, UMID);
	}
	else {
		(*(TAG_BEXT **)&pointer)->UMID[0] = 0;
	}
}

JNIEXPORT jobject JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1get_1Reserved(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_BEXT **)&pointer)->Reserved;
	jobject jresult = 0;
	if(result_) {
		jresult = java_env->NewDirectByteBuffer((BYTE *)result_, 190);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1BEXT_1set_1Reserved(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jReserved) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_BEXT);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *Reserved = 0;
	if(jReserved) {
		Reserved = (char *)getByteArrayElements(java_env, jReserved);
		if(Reserved) {
			strncpy((char *)((*(TAG_BEXT **)&pointer)->Reserved), Reserved, 190);
		}
		releaseByteArrayElements(java_env, jReserved, Reserved);
	}
	else {
		(*(TAG_BEXT **)&pointer)->Reserved[0] = 0;
	}
}



