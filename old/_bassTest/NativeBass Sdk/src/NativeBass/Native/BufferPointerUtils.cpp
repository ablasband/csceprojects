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
#include "JavaObject.h"
#include "org_jouvieje_bass_misc_PointerUtilsJNI.h"
#include "org_jouvieje_bass_misc_BufferUtilsJNI.h"


									/*Buffer*/

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_misc_BufferUtilsJNI_getBufferAddress(JNIEnv *jenv, jclass jcls, jobject jarg1, jint jarg1_) {
	void *arg1 = 0;
	if(jarg1)
		arg1 = (char *)jenv->GetDirectBufferAddress(jarg1)+jarg1_;

	POINTER_TYPE jresult/* = 0*/;
	*(void **)&jresult = arg1;
	return (jlong)jresult;
}

JNIEXPORT jobject JNICALL Java_org_jouvieje_bass_misc_BufferUtilsJNI_newDirectByteBuffer(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
	if(!jarg1) {
		ThrowException(jenv, NullPointerException, NULL_BUFFER);
		return 0;
	}
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
	void * arg1 = *(void **)&_arg1;
	return jenv->NewDirectByteBuffer(arg1, jarg2);
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_misc_BufferUtilsJNI_writeNullTerminal(JNIEnv *jenv, jclass jcls, jobject jarg1, jint jarg1_) {
	if(!jarg1) {
		ThrowException(jenv, NullPointerException, NULL_BUFFER);
		return;
	}
	char *arg1 = (char *)jenv->GetDirectBufferAddress(jarg1)+jarg1_;
	if(arg1)
		strcpy(arg1, "");
}

									/*PointerUtils*/

JNIEXPORT jstring JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_Pointer_1toString(JNIEnv *jenv, jclass jcls, jlong jarg1) {
	if(!jarg1) {
		ThrowException(jenv, NullPointerException, NULL_POINTER);
		return 0;
	}
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
	char *arg1 = *(char **)&_arg1;
	jstring jresult = jenv->NewStringUTF(arg1);
	return jresult;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_Pointer_1strlen(JNIEnv *jenv, jclass jcls, jlong jarg1) {
	if(!jarg1) {
		ThrowException(jenv, NullPointerException, NULL_POINTER);
		return 0;
	}
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
	char *arg1 = *(char **)&_arg1;
	int jresult = strlen(arg1);
	return (jint)jresult;
}

JNIEXPORT jint JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_asInt(JNIEnv *jenv, jclass jcls, jlong jarg1) {
	if(!jarg1) {
		ThrowException(jenv, NullPointerException, NULL_POINTER);
		return 0;
	}
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
	int jreturn = *(int *)&_arg1;
	return (jint)jreturn;
}

JNIEXPORT jfloat JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_asFloat(JNIEnv *jenv, jclass jcls, jlong jarg1) {
	if(!jarg1) {
		ThrowException(jenv, NullPointerException, NULL_POINTER);
		return 0;
	}
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
	float jreturn = *(float *)&_arg1;
	return (jfloat)jreturn;
}

JNIEXPORT jdouble JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_asDouble(JNIEnv *jenv, jclass jcls, jlong jarg1) {
	if(!jarg1) {
		ThrowException(jenv, NullPointerException, NULL_POINTER);
		return 0;
	}
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
	double jreturn = *(double *)&_arg1;
	return (jdouble)jreturn;
}

									/*ObjectPointer*/

class ObjectPointer : public JavaObject {
public:
	ObjectPointer(JNIEnv *jenv, jobject obj) : JavaObject(jenv){
		object = 0;
		setObject(jenv, obj);
	}
	~ObjectPointer(){
		JNIEnv *jenv = acquire_jenv();
		deleteObject(jenv);
	}

	void setObject(JNIEnv *jenv, jobject obj) {
		deleteObject(jenv);
		object = jenv->NewGlobalRef(obj);
	}
	jobject getObject() {
		return object;
	}

private:
	jobject object;
	void deleteObject(JNIEnv *jenv) {
		if(object) {
			jenv->DeleteGlobalRef(object);
			object = 0;
		}
	}
};

JNIEXPORT jlong JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_new_1ObjectPointer(JNIEnv *jenv, jclass jcls, jobject jarg1) {
	ObjectPointer *result = new ObjectPointer(jenv, jarg1);
	CheckAllocation(jenv, result);

    POINTER_TYPE jresult/* = 0*/;
    *(ObjectPointer **)&jresult = result;
    return (jlong)jresult;
}

JNIEXPORT jobject JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_get_1ObjectPointer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    if (!jarg1) {
        ThrowException(jenv, NullPointerException, NULL_OBJECT_POINTER);
        return 0;
    }
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
    ObjectPointer *arg1 = *(ObjectPointer **)&_arg1;
	return arg1->getObject();
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_set_1ObjectPointer(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg2) {
    if (!jarg1) {
        ThrowException(jenv, NullPointerException, NULL_OBJECT_POINTER);
        return ;
    }
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
    ObjectPointer *arg1 = *(ObjectPointer **)&_arg1;
	arg1->setObject(jenv, jarg2);
}

JNIEXPORT void JNICALL Java_org_jouvieje_bass_misc_PointerUtilsJNI_delete_1ObjectPointer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
	POINTER_TYPE _arg1 = (POINTER_TYPE)jarg1;
	delete *(ObjectPointer **)&_arg1;
}
