//
//  Facebook.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SerializeAndroid.h"

#include "../Debugging/LogDefault.h"
#include "../System/App.h"

extern FEngine::App * gApp;

namespace FEngine
{
    
    void SerializeAndroid::SetEnv (JNIEnv * env)
    {
        _env = env;
    }
    
    void SerializeAndroid::SetHighScore(int score)
    {
        jclass clazz = _env->FindClass("com/delagames/zombietreat/SerializeAndroid");
        
        if(!clazz){
            gApp->GetLog()->Print("------------>>>>> BasicShareAndroid::SetHighScore ====>   Class not found");
            return;
        }
        
        jmethodID methodID = _env->GetStaticMethodID(clazz, "SetHighScore", "(I)V");
        
        if(!methodID){
            gApp->GetLog()->Print("------------>>>>> BasicShareAndroid::SetHighScore ====>   Method not found");
            return;
        }
        
        _env->CallStaticVoidMethod(clazz, methodID, score);
    }
    
    int  SerializeAndroid::GetHighScore()
    {
        
        jclass clazz = _env->FindClass("com/delagames/zombietreat/SerializeAndroid");
        
        if(!clazz){
            gApp->GetLog()->Print("------------>>>>> SerializeAndroid::Share ====>   Class not found");
            return 0;
        }
        
        jmethodID methodID = _env->GetStaticMethodID(clazz, "GetHighScore", "()I");
        
        if(!methodID){
            gApp->GetLog()->Print("------------>>>>> SerializeAndroid::Share ====>   Method not found");
            return 0;
        }
        
        int highScore = _env->CallStaticIntMethod(clazz, methodID);
        
        return highScore;
    }

}