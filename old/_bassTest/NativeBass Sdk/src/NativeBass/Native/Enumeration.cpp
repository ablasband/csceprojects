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
#include "org_jouvieje_bass_enumerations_EnumerationJNI.h"
#include "CallbackManager.h"

				/* EAX_ENVIRONMENT */

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1GENERIC(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_GENERIC;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1PADDEDCELL(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_PADDEDCELL;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1ROOM(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_ROOM;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1BATHROOM(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_BATHROOM;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1LIVINGROOM(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_LIVINGROOM;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1STONEROOM(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_STONEROOM;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1AUDITORIUM(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_AUDITORIUM;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1CONCERTHALL(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_CONCERTHALL;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1CAVE(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_CAVE;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1ARENA(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_ARENA;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1HANGAR(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_HANGAR;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1CARPETEDHALLWAY(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_CARPETEDHALLWAY;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1HALLWAY(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_HALLWAY;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1STONECORRIDOR(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_STONECORRIDOR;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1ALLEY(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_ALLEY;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1FOREST(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_FOREST;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1CITY(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_CITY;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1MOUNTAINS(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_MOUNTAINS;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1QUARRY(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_QUARRY;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1PLAIN(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_PLAIN;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1PARKINGLOT(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_PARKINGLOT;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1SEWERPIPE(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_SEWERPIPE;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1UNDERWATER(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_UNDERWATER;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1DRUGGED(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_DRUGGED;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1DIZZY(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_DIZZY;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1PSYCHOTIC(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_PSYCHOTIC;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1EAX_1ENVIRONMENT_1COUNT(JNIEnv *java_env, jclass jcls) {
	return (jint)EAX_ENVIRONMENT_COUNT;
}

				/* STREAMPROC_SPECIAL */

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1STREAMPROC_1DUMMY(JNIEnv *java_env, jclass jcls) {
	return (jint)STREAMPROC_DUMMY;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1STREAMPROC_1PUSH(JNIEnv *java_env, jclass jcls) {
	return (jint)STREAMPROC_PUSH;
}

				/* BASS_FX_DX8 */

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1CHORUS(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_CHORUS;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1COMPRESSOR(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_COMPRESSOR;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1DISTORTION(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_DISTORTION;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1ECHO(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_ECHO;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1FLANGER(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_FLANGER;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1GARGLE(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_GARGLE;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1I3DL2REVERB(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_I3DL2REVERB;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1PARAMEQ(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_PARAMEQ;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_enumerations_EnumerationJNI_get_1BASS_1FX_1DX8_1REVERB(JNIEnv *java_env, jclass jcls) {
	return (jint)BASS_FX_DX8_REVERB;
}


