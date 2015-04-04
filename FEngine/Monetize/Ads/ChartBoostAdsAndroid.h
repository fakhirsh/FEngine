//
//  ChartBoostAdsAndroid.h
//  FEngine
//
//  Created by Fakhir Shaheen on 04/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../Ads.h"

#include <jni.h>

namespace FEngine
{
    class ChartBoostAdsAndroid : public Ads
    {
    public:
        explicit ChartBoostAdsAndroid();
        virtual ~ChartBoostAdsAndroid();
        
        virtual bool    Init                ();
        virtual bool    ShowBanner          ();
        virtual bool    HideBanner          ();
        virtual bool    ShowInterstitial    ();
        virtual bool    HideInterstitial    ();
        virtual bool    ShowMoreApps        ();
        virtual bool    HideMoreApps        ();
        
        void			SetEnv				(JNIEnv * env);
        
    private:
        
        JNIEnv * _env;
    };
}