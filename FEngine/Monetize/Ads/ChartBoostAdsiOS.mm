//
//  ChartBoostAdsiOS.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 04/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ChartBoostAdsiOS.h"


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UIKit/UIView.h>

#import <Chartboost/Chartboost.h>
#import <Chartboost/CBNewsfeed.h>
#import <CommonCrypto/CommonDigest.h>
#import <AdSupport/AdSupport.h>

namespace FEngine
{
    ChartBoostAdsiOS::ChartBoostAdsiOS()
    {

    }
    
    ChartBoostAdsiOS::~ChartBoostAdsiOS()
    {
    
    }
        
    bool ChartBoostAdsiOS::Init ()
    {
        // Initialize the Chartboost library
        // "self" is the AppDelegate instance...
        //
     //   [Chartboost startWithAppId:@"548b0cc0c909a646d0c2721a"
     //                 appSignature:@"6d8b8d11fea8509903b7ecfff399f00c09932e0b"
     //                     delegate:(id<ChartboostDelegate>)self];
        
        return true;
    }
    
    bool ChartBoostAdsiOS::PreLoad ()
    {
        [Chartboost cacheInterstitial:CBLocationHomeScreen];
        
        return true;
    }
    
    bool ChartBoostAdsiOS::ShowBanner ()
    {
        return true;
    }
    
    bool ChartBoostAdsiOS::HideBanner ()
    {
        return true;
    }
    
    bool ChartBoostAdsiOS::ShowInterstitial ()
    {
        [Chartboost showInterstitial:CBLocationHomeScreen];
        
        return true;
    }
    
    bool ChartBoostAdsiOS::HideInterstitial ()
    {
        return true;
    }
    
    bool ChartBoostAdsiOS::ShowMoreApps ()
    {
        [Chartboost showMoreApps:CBLocationHomeScreen];
        
        return true;
    }
    
    bool ChartBoostAdsiOS::HideMoreApps ()
    {
        return true;
    }

}

