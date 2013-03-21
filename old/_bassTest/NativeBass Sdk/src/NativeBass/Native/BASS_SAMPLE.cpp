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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1new(JNIEnv *java_env, jclass jcls) {
	BASS_SAMPLE *result_ = new BASS_SAMPLE();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(BASS_SAMPLE **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(BASS_SAMPLE **)&pointer;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1freq(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->freq;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1freq(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jfreq) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD freq = (DWORD)jfreq;
	(*(BASS_SAMPLE **)&pointer)->freq = freq;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1volume(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_SAMPLE **)&pointer)->volume;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1volume(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jvolume) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float volume = (float)jvolume;
	(*(BASS_SAMPLE **)&pointer)->volume = volume;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1pan(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_SAMPLE **)&pointer)->pan;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1pan(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jpan) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float pan = (float)jpan;
	(*(BASS_SAMPLE **)&pointer)->pan = pan;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->flags;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1flags(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jflags) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD flags = (DWORD)jflags;
	(*(BASS_SAMPLE **)&pointer)->flags = flags;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1length(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->length;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1length(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jlength) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD length = (DWORD)jlength;
	(*(BASS_SAMPLE **)&pointer)->length = length;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1max(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->max;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1max(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jmax) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD max = (DWORD)jmax;
	(*(BASS_SAMPLE **)&pointer)->max = max;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1origres(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->origres;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1origres(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jorigres) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD origres = (DWORD)jorigres;
	(*(BASS_SAMPLE **)&pointer)->origres = origres;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1chans(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->chans;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1chans(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jchans) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD chans = (DWORD)jchans;
	(*(BASS_SAMPLE **)&pointer)->chans = chans;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1mingap(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->mingap;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1mingap(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jmingap) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD mingap = (DWORD)jmingap;
	(*(BASS_SAMPLE **)&pointer)->mingap = mingap;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1mode3d(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->mode3d;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1mode3d(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jmode3d) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD mode3d = (DWORD)jmode3d;
	(*(BASS_SAMPLE **)&pointer)->mode3d = mode3d;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1mindist(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_SAMPLE **)&pointer)->mindist;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1mindist(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jmindist) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float mindist = (float)jmindist;
	(*(BASS_SAMPLE **)&pointer)->mindist = mindist;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1maxdist(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_SAMPLE **)&pointer)->maxdist;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1maxdist(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat jmaxdist) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float maxdist = (float)jmaxdist;
	(*(BASS_SAMPLE **)&pointer)->maxdist = maxdist;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1iangle(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->iangle;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1iangle(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jiangle) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD iangle = (DWORD)jiangle;
	(*(BASS_SAMPLE **)&pointer)->iangle = iangle;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1oangle(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->oangle;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1oangle(JNIEnv *java_env, jclass jcls, jlong jpointer, jint joangle) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD oangle = (DWORD)joangle;
	(*(BASS_SAMPLE **)&pointer)->oangle = oangle;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1outvol(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float result_ = (*(BASS_SAMPLE **)&pointer)->outvol;
	return (jfloat)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1outvol(JNIEnv *java_env, jclass jcls, jlong jpointer, jfloat joutvol) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	float outvol = (float)joutvol;
	(*(BASS_SAMPLE **)&pointer)->outvol = outvol;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1vam(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->vam;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1vam(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jvam) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD vam = (DWORD)jvam;
	(*(BASS_SAMPLE **)&pointer)->vam = vam;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1get_1priority(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD result_ = (*(BASS_SAMPLE **)&pointer)->priority;
	return (jint)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_BASS_1SAMPLE_1set_1priority(JNIEnv *java_env, jclass jcls, jlong jpointer, jint jpriority) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_BASS_SAMPLE);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	DWORD priority = (DWORD)jpriority;
	(*(BASS_SAMPLE **)&pointer)->priority = priority;
}



