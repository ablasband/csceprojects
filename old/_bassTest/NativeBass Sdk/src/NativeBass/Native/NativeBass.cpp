/**
 * 						NativeBass Project
 *
 * Want to use BASS (www.un4seen.com) in the Java language ? NativeBass is made for you.
 * Copyright � 2007 J�r�me JOUVIE (Jouvieje)
 *
 * Created on 02 jul. 2007
 * @version file v1.0.0
 * @author J�r�me JOUVIE (Jouvieje)
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

#include "NativeBass.h"
#include "bass.h"
#include "CallbackManager.h"
#include "org_jouvieje_bass_Init.h"
#include "org_jouvieje_bass_BassJNI.h"
#include "org_jouvieje_bass_defines_DefineJNI.h"
#pragma comment(lib, "bass.lib")

//The platform in which this library is compiled
#define PLATFORM WIN_32
//#define PLATFORM WIN_64
//#define PLATFORM LINUX
//#define PLATFORM LINUX_64
//#define PLATFORM MAC

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_defines_DefineJNI_get_1BASSVERSION(JNIEnv *jenv, jclass jcls) {
	return BASSVERSION;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_defines_DefineJNI_get_1NATIVEBASS_1VERSION(JNIEnv *jenv, jclass jcls) {
	return NATIVEBASS_VERSION;
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_Init_attachJavaVM(JNIEnv *jenv, jclass jcls) {
	attachJavaVM(jenv);
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_Init_get_1PLATFORM(JNIEnv *jenv, jclass jcls) {
	return PLATFORM;
}
