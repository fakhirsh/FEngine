//
//  Facebook.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Serialize.h"

#include <jni.h>
#include <string>

namespace FEngine
{
    class SerializeAndroid : public Serialize
    {
    public:
        SerializeAndroid(){}
        virtual ~SerializeAndroid(){}
        
        
        virtual void SetHighScore(int score);
        virtual int  GetHighScore();
        
        void        SetEnv		(JNIEnv * env);
        
    private:
        
        JNIEnv * _env;
    };
}