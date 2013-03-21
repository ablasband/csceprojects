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

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1new(JNIEnv *java_env, jclass jcls) {
	TAG_ID3 *result_ = new TAG_ID3();
	CheckAllocation(java_env, result_);
	POINTER_TYPE jresult/* = 0*/;
	*(TAG_ID3 **)&jresult = result_;
	return (jlong)jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1delete(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	delete *(TAG_ID3 **)&pointer;
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1get_1id(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_ID3 **)&pointer)->id;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1set_1id(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jid) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *id = 0;
	if(jid) {
		id = (char *)getByteArrayElements(java_env, jid);
		if(id) {
			strncpy((char *)((*(TAG_ID3 **)&pointer)->id), id, 3);
		}
		releaseByteArrayElements(java_env, jid, id);
	}
	else {
		(*(TAG_ID3 **)&pointer)->id[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1get_1title(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_ID3 **)&pointer)->title;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1set_1title(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jtitle) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *title = 0;
	if(jtitle) {
		title = (char *)getByteArrayElements(java_env, jtitle);
		if(title) {
			strncpy((char *)((*(TAG_ID3 **)&pointer)->title), title, 30);
		}
		releaseByteArrayElements(java_env, jtitle, title);
	}
	else {
		(*(TAG_ID3 **)&pointer)->title[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1get_1artist(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_ID3 **)&pointer)->artist;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1set_1artist(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jartist) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *artist = 0;
	if(jartist) {
		artist = (char *)getByteArrayElements(java_env, jartist);
		if(artist) {
			strncpy((char *)((*(TAG_ID3 **)&pointer)->artist), artist, 30);
		}
		releaseByteArrayElements(java_env, jartist, artist);
	}
	else {
		(*(TAG_ID3 **)&pointer)->artist[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1get_1album(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_ID3 **)&pointer)->album;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1set_1album(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jalbum) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *album = 0;
	if(jalbum) {
		album = (char *)getByteArrayElements(java_env, jalbum);
		if(album) {
			strncpy((char *)((*(TAG_ID3 **)&pointer)->album), album, 30);
		}
		releaseByteArrayElements(java_env, jalbum, album);
	}
	else {
		(*(TAG_ID3 **)&pointer)->album[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1get_1year(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_ID3 **)&pointer)->year;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1set_1year(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jyear) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *year = 0;
	if(jyear) {
		year = (char *)getByteArrayElements(java_env, jyear);
		if(year) {
			strncpy((char *)((*(TAG_ID3 **)&pointer)->year), year, 4);
		}
		releaseByteArrayElements(java_env, jyear, year);
	}
	else {
		(*(TAG_ID3 **)&pointer)->year[0] = 0;
	}
}

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1get_1comment(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *result_ = (char *)(*(TAG_ID3 **)&pointer)->comment;
	jstring jresult = 0;
	if(result_) {
		jresult = java_env->NewStringUTF(result_);
	}
	return jresult;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1set_1comment(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyteArray jcomment) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	char *comment = 0;
	if(jcomment) {
		comment = (char *)getByteArrayElements(java_env, jcomment);
		if(comment) {
			strncpy((char *)((*(TAG_ID3 **)&pointer)->comment), comment, 30);
		}
		releaseByteArrayElements(java_env, jcomment, comment);
	}
	else {
		(*(TAG_ID3 **)&pointer)->comment[0] = 0;
	}
}

JNIEXPORT jbyte JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1get_1genre(JNIEnv *java_env, jclass jcls, jlong jpointer) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return 0;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	BYTE result_ = (*(TAG_ID3 **)&pointer)->genre;
	return (jbyte)result_;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_structures_StructureJNI_TAG_1ID3_1set_1genre(JNIEnv *java_env, jclass jcls, jlong jpointer, jbyte jgenre) {
	if(!jpointer) {
		ThrowException(java_env, NullPointerException, NULL_TAG_ID3);
		return;
	}
	POINTER_TYPE pointer = (POINTER_TYPE)jpointer;
	BYTE genre = (BYTE)jgenre;
	(*(TAG_ID3 **)&pointer)->genre = genre;
}



