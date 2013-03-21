/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright © 2007 Jérôme JOUVIE (Jouvieje)
 *
 * Created on 02 jul. 2007
 * @version file v1.0.0
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
 * FMOD Ex is an API (Application Programming Interface) that allow you to use music
 * and creating sound effects with a lot of sort of musics.
 * FMOD is at :
 * 		http://www.fmod.org/
 * The reason of this project is that FMOD Ex can't be used direcly with Java, so I've created
 * this project to do this.
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

const char * NULL_BUFFER =				"";
const char * NULL_POINTER =				"";
const char * NULL_OBJECT_POINTER =		"";
const char * NULL_BASS_3DVECTOR =		"";
const char * NULL_BASS_CHANNELINFO =	"";
const char * NULL_BASS_DEVICEINFO =		"";
const char * NULL_BASS_DX8_CHORUS =		"";
const char * NULL_BASS_DX8_COMPRESSOR =	"";
const char * NULL_BASS_DX8_DISTORTION =	"";
const char * NULL_BASS_DX8_ECHO =		"";
const char * NULL_BASS_DX8_FLANGER =	"";
const char * NULL_BASS_DX8_GARGLE =		"";
const char * NULL_BASS_DX8_I3DL2REVERB ="";
const char * NULL_BASS_DX8_PARAMEQ =	"";
const char * NULL_BASS_DX8_REVERB =		"";
const char * NULL_BASS_FILEPROCS =		"";
const char * NULL_BASS_INFO =			"";
const char * NULL_BASS_PLUGININFO =		"";
const char * NULL_BASS_PLUGINFORM =		"";
const char * NULL_BASS_RECORDINFO =		"";
const char * NULL_BASS_SAMPLE =			"";
const char * NULL_TAG_BEXT =			"";
const char * NULL_TAG_ID3 =				"";
const char * FATAL_ERROR_MESSAGE =		"An exception occures but it can't be thrown !";

void ThrowException(JNIEnv *jenv, ExceptionType type, const char *message) {
	jclass exception;
	switch(type) {
//		case CallbackException:				exception = jenv->FindClass("org/jouvieje/bass/exceptions/CallbackException"); break;
		case NullPointerException:			exception = jenv->FindClass("java/lang/NullPointerException"); break;
		case InitException:					exception = jenv->FindClass("org/jouvieje/bass/exceptions/InitException"); break;
		case RuntimeException:				exception = jenv->FindClass("java/lang/RuntimeException"); break;
		case OutOfMemoryError:				exception = jenv->FindClass("java/lang/OutOfMemoryError"); break;
//		case IndexOutOfBoundsException:		exception = jenv->FindClass("java/lang/IndexOutOfBoundsException"); break;
//		case IllegalArgumentException:		exception = jenv->FindClass("java/lang/IllegalArgumentException"); break;
//		case ArithmeticException:			exception = jenv->FindClass("java/lang/ArithmeticException"); break;
//		case IOException:					exception = jenv->FindClass("java/io/IOException"); break;
//		case UnknownError:
		default:							exception = jenv->FindClass("java/lang/UnknownError");
	}

	if(exception) {
		jenv->ThrowNew(exception, message);
		jenv->DeleteLocalRef(exception);
	}
}
bool CheckAllocation(JNIEnv *jenv, void *memAllocated) {
	if(memAllocated == NULL) {
		ThrowException(jenv, OutOfMemoryError, "");
		return false;
	}
	else {
		return true;
	}
}

jclass stringClass = 0;
jclass getStringClass(JNIEnv *jenv) {
	if(!stringClass) {
		stringClass = (jclass)jenv->NewGlobalRef(jenv->FindClass("java/lang/String"));
	}
	return stringClass;
}
jmethodID getBytesId = 0;
jmethodID getGetBytesId(JNIEnv *jenv) {
	if(getBytesId == 0) {
		getBytesId = jenv->GetMethodID(getStringClass(jenv), "getBytes", "()[B");
	}
	return getBytesId;
}

char *getByteArrayElements(JNIEnv *jenv, jbyteArray array) {
	if(array) {
		const jsize length = jenv->GetArrayLength(array);
		const jbyte *chars = jenv->GetByteArrayElements(array, 0);
		char *copy = new char[length+1];		//Allocate memory
		if(!CheckAllocation(jenv, copy)) {
			return 0;
		}

		for(int i = 0; i < length; i++) {
			copy[i] = (char)chars[i];
		}
		copy[length] = 0;		//End of the string
		jenv->ReleaseByteArrayElements(array, (jbyte *)chars, 0);

		return copy;
	}
	return 0;
}

void releaseByteArrayElements(JNIEnv *jenv, jbyteArray array, const char *chars) {
	if(chars) {
		delete [] chars;						//Deallocate memory
		chars = NULL;
	}
}

char *getStringElements(JNIEnv *jenv, jstring string) {
	if(string) {
		jbyteArray array = (jbyteArray)jenv->CallObjectMethod(string, getGetBytesId(jenv));
		return getByteArrayElements(jenv, array);
	}
	return 0;
}

void releaseStringElements(JNIEnv *jenv, jstring string, const char *chars) {
	if(chars) {
		delete [] chars;						//Deallocate memory
		chars = NULL;
	}
}