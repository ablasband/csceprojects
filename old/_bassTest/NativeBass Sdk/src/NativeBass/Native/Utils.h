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

#ifndef UTILS_H_
#define UTILS_H_

#include "Includes.h"
#include <iostream>

typedef enum {
//	CallbackException,
	NullPointerException,
	InitException,
	RuntimeException,
	OutOfMemoryError
//	IndexOutOfBoundsException,
//	IllegalArgumentException,
//	ArithmeticException,
//	IOException,
//	UnknownError
} ExceptionType;

extern const char * NULL_BUFFER;
extern const char * NULL_POINTER;
extern const char * NULL_OBJECT_POINTER;
extern const char * NULL_BASS_3DVECTOR;
extern const char * NULL_BASS_CHANNELINFO;
extern const char * NULL_BASS_DEVICEINFO;
extern const char * NULL_BASS_DX8_CHORUS;
extern const char * NULL_BASS_DX8_COMPRESSOR;
extern const char * NULL_BASS_DX8_DISTORTION;
extern const char * NULL_BASS_DX8_ECHO;
extern const char * NULL_BASS_DX8_FLANGER;
extern const char * NULL_BASS_DX8_GARGLE;
extern const char * NULL_BASS_DX8_I3DL2REVERB;
extern const char * NULL_BASS_DX8_PARAMEQ;
extern const char * NULL_BASS_DX8_REVERB;
extern const char * NULL_BASS_FILEPROCS;
extern const char * NULL_BASS_INFO;
extern const char * NULL_BASS_PLUGININFO;
extern const char * NULL_BASS_PLUGINFORM;
extern const char * NULL_BASS_RECORDINFO;
extern const char * NULL_BASS_SAMPLE;
extern const char * NULL_TAG_BEXT;
extern const char * NULL_TAG_ID3;
extern const char * FATAL_ERROR_MESSAGE;

/**
 * Exception
 */
extern void ThrowException(JNIEnv *jenv, ExceptionType type, const char *message);
extern bool CheckAllocation(JNIEnv *jenv, void *memAllocated);

/**
 * String manipulation
 */
extern jclass getStringClass(JNIEnv *jenv);
extern char *getByteArrayElements(JNIEnv *jenv, jbyteArray s);
extern void releaseByteArrayElements(JNIEnv *jenv, jbyteArray jarg1, const char *chars);
extern char *getStringElements(JNIEnv *jenv, jstring string);	/* It is better to use getByteArrayElements */
extern void releaseStingElements(JNIEnv *jenv, jstring string, const char *chars);

#endif
