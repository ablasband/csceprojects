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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1new(JNIEnv *java_env, jclass jcls) {
	BASS_INFO *result_ = new BASS_INFO();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_INFO **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_INFO **)&pointer;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->flags;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jflags) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD flags = (DWORD)jflags;
	(*(BASS_INFO **)&pointer)->flags = flags;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1hwsize(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->hwsize;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1hwsize(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jhwsize) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD hwsize = (DWORD)jhwsize;
	(*(BASS_INFO **)&pointer)->hwsize = hwsize;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1hwfree(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->hwfree;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1hwfree(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jhwfree) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD hwfree = (DWORD)jhwfree;
	(*(BASS_INFO **)&pointer)->hwfree = hwfree;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1freesam(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->freesam;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1freesam(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jfreesam) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD freesam = (DWORD)jfreesam;
	(*(BASS_INFO **)&pointer)->freesam = freesam;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1free3d(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->free3d;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1free3d(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jfree3d) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD free3d = (DWORD)jfree3d;
	(*(BASS_INFO **)&pointer)->free3d = free3d;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1minrate(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->minrate;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1minrate(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jminrate) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD minrate = (DWORD)jminrate;
	(*(BASS_INFO **)&pointer)->minrate = minrate;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1maxrate(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->maxrate;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1maxrate(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jmaxrate) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD maxrate = (DWORD)jmaxrate;
	(*(BASS_INFO **)&pointer)->maxrate = maxrate;
}

JNIEXPORT jboolean JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1eax(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	BOOL result_ = (*(BASS_INFO **)&pointer)->eax;
	return (jboolean)(result_ != 0);
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1eax(JNIEnv *java_env, jclass jcls, jlong jpointer, jboolean jeax) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	BOOL eax = (BOOL)(jeax != 0);
	(*(BASS_INFO **)&pointer)->eax = eax;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1minbuf(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->minbuf;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1minbuf(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jminbuf) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD minbuf = (DWORD)jminbuf;
	(*(BASS_INFO **)&pointer)->minbuf = minbuf;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1dsver(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->dsver;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1dsver(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jdsver) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD dsver = (DWORD)jdsver;
	(*(BASS_INFO **)&pointer)->dsver = dsver;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1latency(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->latency;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1latency(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jlatency) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD latency = (DWORD)jlatency;
	(*(BASS_INFO **)&pointer)->latency = latency;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1initflags(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->initflags;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1initflags(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jinitflags) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD initflags = (DWORD)jinitflags;
	(*(BASS_INFO **)&pointer)->initflags = initflags;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1speakers(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->speakers;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1speakers(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jspeakers) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD speakers = (DWORD)jspeakers;
	(*(BASS_INFO **)&pointer)->speakers = speakers;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1get_1freq(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_INFO **)&pointer)->freq;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1INFO_1set_1freq(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jfreq) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_INFO);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD freq = (DWORD)jfreq;
	(*(BASS_INFO **)&pointer)->freq = freq;
}



