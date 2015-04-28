//
//  BasicShareAndroid.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 24/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "BasicShareAndroid.h"

#include "../Debugging/LogDefault.h"
#include "../System/App.h"

extern FEngine::App * gApp;

namespace FEngine
{

	void BasicShareAndroid::SetEnv (JNIEnv * env)
	{
		_env = env;
	}

	bool BasicShareAndroid::Share ()
	{

		jclass clazz = _env->FindClass("com/delagames/zombietreat/BasicShareAndroid");
    	jmethodID methodID = _env->GetStaticMethodID(clazz, "Share", "()V");
    	_env->CallStaticVoidMethod(clazz, methodID);
        
    	return true;
	}

}