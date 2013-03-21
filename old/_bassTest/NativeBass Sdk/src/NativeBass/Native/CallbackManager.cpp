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
#include "malloc.h"
#include "CallbackManager.h"

jclass byteBufferClass = 0;
jclass getByteBufferClass(JNIEnv *java_env) {
	if(!byteBufferClass) {
		byteBufferClass = (jclass)java_env->NewGlobalRef(java_env->FindClass("java/nio/ByteBuffer"));
	}
	return byteBufferClass;
}

jclass caller = 0;
void connectCaller(JNIEnv *java_env) {
	caller = (jclass)java_env->NewGlobalRef(java_env->FindClass("org/jouvieje/bass/callbacks/CallbackBridge"));
	if(java_env->ExceptionCheck()) {
		java_env->ExceptionClear();
		caller = 0;
		ThrowException(java_env, InitException, "Connection to CallbackBridge fails.");
	}
}

jmethodID callbackId[9];
void connectCallbacks(JNIEnv *java_env) {
	static struct {
		const char *name;
		const char *signature;
	}callbacks[9] = {
		{"STREAMPROC_BRIDGE", "(JLjava/nio/ByteBuffer;IJ)I"},
		{"FILECLOSEPROC_BRIDGE", "(J)V"},
		{"FILELENPROC_BRIDGE", "(J)J"},
		{"FILEREADPROC_BRIDGE", "(JIJ)I"},
		{"FILESEEKPROC_BRIDGE", "(JJ)Z"},
		{"DOWNLOADPROC_BRIDGE", "(Ljava/nio/ByteBuffer;IJ)V"},
		{"SYNCPROC_BRIDGE", "(JIIJ)V"},
		{"DSPPROC_BRIDGE", "(JILjava/nio/ByteBuffer;IJ)V"},
		{"RECORDPROC_BRIDGE", "(JLjava/nio/ByteBuffer;IJ)Z"}
	};

	for(int i = 0; i < 9; i++) {
		callbackId[i] = java_env->GetStaticMethodID(caller, callbacks[i].name, callbacks[i].signature);
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionClear();
			ThrowException(java_env, InitException, "Connection to a Callback fails.");
			return;
		}
	}
}

JavaVM *jvm;
void attachJavaVM(JNIEnv *java_env) {
	java_env->GetJavaVM(&jvm);
	connectCaller(java_env);
	if(caller) {
		connectCallbacks(java_env);
	}
}
bool acquire_jenv(JNIEnv **java_env) {
	if(jvm->GetEnv((void **)java_env, JNI_VERSION_1_4) != JNI_OK) {
		jvm->AttachCurrentThread((void **)java_env, 0);
		return true;
	}
	return false;
}
void leave_jenv(bool attached) {
	if(attached) {
		jvm->DetachCurrentThread();
	}
}

DWORD CALLBACK STREAMPROC_BRIDGE(HSTREAM handle, void * buffer, DWORD length, void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	jlong jhandle = (jlong)(ADDRESS_TYPE)handle;
	jobject jbuffer = 0;
	if(buffer) {
		jbuffer = java_env->NewDirectByteBuffer((void *)buffer, length);
	}
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	jint result_ = java_env->CallStaticIntMethod(caller, callbackId[0], jhandle, jbuffer, (jint)length, (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
	return (DWORD)result_;
}

void CALLBACK FILECLOSEPROC_BRIDGE(void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	java_env->CallStaticVoidMethod(caller, callbackId[1], (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
}

QWORD CALLBACK FILELENPROC_BRIDGE(void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	jlong result_ = java_env->CallStaticLongMethod(caller, callbackId[2], (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
	return (QWORD)result_;
}

DWORD CALLBACK FILEREADPROC_BRIDGE(void * buffer, DWORD length, void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	POINTER_TYPE jbuffer/* = 0*/;
	*(void **)&jbuffer = buffer;
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	jint result_ = java_env->CallStaticIntMethod(caller, callbackId[3], (jlong)jbuffer, (jint)length, (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
	return (DWORD)result_;
}

BOOL CALLBACK FILESEEKPROC_BRIDGE(QWORD offset, void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	jboolean result_ = java_env->CallStaticBooleanMethod(caller, callbackId[4], (jlong)offset, (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
	return (BOOL)result_;
}

void CALLBACK DOWNLOADPROC_BRIDGE(const void * buffer, DWORD length, void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	jobject jbuffer = 0;
	if(buffer) {
		jbuffer = java_env->NewDirectByteBuffer((void *)buffer, length);
	}
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	java_env->CallStaticVoidMethod(caller, callbackId[5], jbuffer, (jint)length, (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
}

void CALLBACK SYNCPROC_BRIDGE(HSYNC handle, DWORD channel, DWORD data, void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	jlong jhandle = (jlong)(ADDRESS_TYPE)handle;
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	java_env->CallStaticVoidMethod(caller, callbackId[6], jhandle, (jint)channel, (jint)data, (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
}

void CALLBACK DSPPROC_BRIDGE(HDSP handle, DWORD channel, void * buffer, DWORD length, void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	jlong jhandle = (jlong)(ADDRESS_TYPE)handle;
	jobject jbuffer = 0;
	if(buffer) {
		jbuffer = java_env->NewDirectByteBuffer((void *)buffer, length);
	}
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	java_env->CallStaticVoidMethod(caller, callbackId[7], jhandle, (jint)channel, jbuffer, (jint)length, (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
}

BOOL CALLBACK RECORDPROC_BRIDGE(HRECORD handle, const void * buffer, DWORD length, void * user) {
	JNIEnv *java_env/* = 0*/;
	bool attached = acquire_jenv(&java_env);
	jlong jhandle = (jlong)(ADDRESS_TYPE)handle;
	jobject jbuffer = 0;
	if(buffer) {
		jbuffer = java_env->NewDirectByteBuffer((void *)buffer, length);
	}
	POINTER_TYPE juser/* = 0*/;
	*(void **)&juser = user;
	jboolean result_ = java_env->CallStaticBooleanMethod(caller, callbackId[8], jhandle, jbuffer, (jint)length, (jlong)juser);
	if(java_env->ExceptionCheck()) {
		java_env->Throw(java_env->ExceptionOccurred());
		if(java_env->ExceptionCheck()) {
			java_env->ExceptionDescribe();
			java_env->FatalError(FATAL_ERROR_MESSAGE);
		}
	}
	leave_jenv(attached);
	return (BOOL)result_;
}


