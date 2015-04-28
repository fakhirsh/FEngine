//
//  Ads.h
//  FEngine
//
//  Created by Fakhir Shaheen on 04/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

namespace FEngine
{
    class Ads
    {
    public:
        //Ads();
        //virtual ~Ads();
        
        virtual bool    Init                ()  =   0;
        virtual bool    PreLoad             ()  =   0;
        virtual bool    ShowBanner          ()  =   0;
        virtual bool    HideBanner          ()  =   0;
        virtual bool    ShowInterstitial    ()  =   0;
        virtual bool    HideInterstitial    ()  =   0;
        virtual bool    ShowMoreApps        ()  =   0;
        virtual bool    HideMoreApps        ()  =   0;
    };
}