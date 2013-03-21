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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1newArray(JNIEnv *java_env, jclass jcls, jint length) {
	BASS_PLUGINFORM *array = new BASS_PLUGINFORM[(int)length];
	if((int)length > 0) { CheckAllocation(java_env, array); }
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_PLUGINFORM **)&jresult = array;
	return (jlong)jresult;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1SIZEOF(JNIEnv *java_env, jclass jcls) {
	return (jint)sizeof(BASS_PLUGINFORM);
}

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1new(JNIEnv *java_env, jclass jcls) {
	BASS_PLUGINFORM *result_ = new BASS_PLUGINFORM();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_PLUGINFORM **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_PLUGINFORM **)&pointer;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1get_1ctype(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGINFORM);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_PLUGINFORM **)&pointer)->ctype;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1set_1ctype(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jctype) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGINFORM);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD ctype = (DWORD)jctype;
	(*(BASS_PLUGINFORM **)&pointer)->ctype = ctype;
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1get_1name(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGINFORM);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	const char *result_ = (const char *)((*(BASS_PLUGINFORM **)&pointer)->name);
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1set_1name(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jname) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGINFORM);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *name = 0;
	if(jname) {
		name = getByteArrayElements(java_env, jname);
		(*(BASS_PLUGINFORM **)&pointer)->name = name;
	}
	else {
		(*(BASS_PLUGINFORM **)&pointer)->name = (char *)0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1get_1exts(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGINFORM);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	const char *result_ = (const char *)((*(BASS_PLUGINFORM **)&pointer)->exts);
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1PLUGINFORM_1set_1exts(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jexts) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_PLUGINFORM);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *exts = 0;
	if(jexts) {
		exts = getByteArrayElements(java_env, jexts);
		(*(BASS_PLUGINFORM **)&pointer)->exts = exts;
	}
	else {
		(*(BASS_PLUGINFORM **)&pointer)->exts = (char *)0;
	}
}



