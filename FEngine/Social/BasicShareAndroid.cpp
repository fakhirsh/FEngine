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

		if(!_env){
			gApp->GetLog()->Print("------------>>>>> BasicShareAndroid::Share ====>   Class Environment is NULL");
			return false;
		}

		jclass clazz = _env->FindClass("com/delagames/zombietreat/BasicShareAndroid");

		if(!clazz){
			gApp->GetLog()->Print("------------>>>>> BasicShareAndroid::Share ====>   Class not found");
			return false;
		}
		
    	jmethodID methodID = _env->GetStaticMethodID(clazz, "Share", "()V");

		if(!methodID){
			gApp->GetLog()->Print("------------>>>>> BasicShareAndroid::Share ====>   Method not found");
			return false;
		}

    	_env->CallStaticVoidMethod(clazz, methodID);
        
    	return true;
	}

}