//
//  BasicShareAndroid.h
//  FEngine
//
//  Created by Fakhir Shaheen on 24/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "BasicShare.h"

#include <jni.h>
#include <string>

namespace FEngine
{
    class BasicShareAndroid : public BasicShare
    {
    public:
        BasicShareAndroid(){}
        virtual ~BasicShareAndroid(){}
        
        virtual bool    Share       ();

        void			SetEnv		(JNIEnv * env);
        
    private:
        
        JNIEnv * _env;
    };
}