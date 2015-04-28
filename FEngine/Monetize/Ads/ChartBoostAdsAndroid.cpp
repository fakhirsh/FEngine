//
//  ChartBoostAdsAndroid.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 04/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ChartBoostAdsAndroid.h"

#include <android/log.h>

#include <iostream>

namespace FEngine
{
    
    ChartBoostAdsAndroid::ChartBoostAdsAndroid()
    {
        
    }
    
    ChartBoostAdsAndroid::~ChartBoostAdsAndroid()
    {
        
    }
    
    void ChartBoostAdsAndroid::SetEnv (JNIEnv * env)
    {
    	_env = env;
    }
            
    bool ChartBoostAdsAndroid::Init ()
    {
        return true;
    }
    
    bool ChartBoostAdsAndroid::PreLoad ()
    {
        jclass clazz = _env->FindClass("com/delagames/zombietreat/ChartboostAdsAndroid");
        jmethodID methodID = _env->GetStaticMethodID(clazz, "PreLoad", "()V");
        _env->CallStaticVoidMethod(clazz, methodID);
        
        return true;
    }
    
    bool ChartBoostAdsAndroid::ShowBanner ()
    {
        return true;
    }
    
    bool ChartBoostAdsAndroid::HideBanner ()
    {
        return true;
    }
    
    /**
     *   Explanation for parameter descriptor formats:
     *      http://journals.ecs.soton.ac.uk/java/tutorial/native1.1/implementing/method.html
     *      http://adamish.com/blog/archives/327
     * 
     *   Note:
     *      For a function with zero input params, just keep the signature empty "()V", no need to pass void. incorrect => (V)V
     */
    bool ChartBoostAdsAndroid::ShowInterstitial ()
    {
    	jclass clazz = _env->FindClass("com/delagames/zombietreat/ChartboostAdsAndroid");
    	jmethodID methodID = _env->GetStaticMethodID(clazz, "ShowInterstitial", "()V");
    	_env->CallStaticVoidMethod(clazz, methodID);
    
        return true;
    }
    
    bool ChartBoostAdsAndroid::HideInterstitial ()
    {
        return true;
    }
    
    bool ChartBoostAdsAndroid::ShowMoreApps ()
    {
        return true;
    }
    
    bool ChartBoostAdsAndroid::HideMoreApps ()
    {
        return true;
    }
    
}

