//
//  StubAds.h
//  FEngine
//
//  Created by Fakhir Shaheen on 04/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../Ads.h"

namespace FEngine
{
    class AdsStub : public Ads
    {
    public:
        explicit AdsStub();
        virtual ~AdsStub();
        
        virtual bool    Init                ();
        virtual bool    PreLoad             ();
        virtual bool    ShowBanner          ();
        virtual bool    HideBanner          ();
        virtual bool    ShowInterstitial    ();
        virtual bool    HideInterstitial    ();
        virtual bool    ShowMoreApps        ();
        virtual bool    HideMoreApps        ();
    };
}