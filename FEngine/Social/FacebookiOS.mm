//
//  FacebookiOS.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "FacebookiOS.h"


#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKShareKit/FBSDKShareKit.h>
#import <FBSDKLoginKit/FBSDKLoginKit.h>

namespace FEngine
{

    FacebookiOS::FacebookiOS()
    {
        _viewController = nil;
    }
    
    FacebookiOS::~FacebookiOS()
    {
    
    }
    
    bool FacebookiOS::ShareURL (std::string contentURL, std::string imgURL, std::string title, std::string description)
    {
        
        FBSDKShareLinkContent *content = [[FBSDKShareLinkContent alloc] init];
        content.contentURL          =   [NSURL URLWithString:[NSString stringWithUTF8String:contentURL.c_str()]];
        content.imageURL            =   [NSURL URLWithString:[NSString stringWithUTF8String:imgURL.c_str()]];
        content.contentTitle        =   [NSString stringWithUTF8String:title.c_str()];
        content.contentDescription  =   [NSString stringWithUTF8String:description.c_str()];
        
        FBSDKShareDialog *dialog = [[FBSDKShareDialog alloc] init];
        dialog.fromViewController = _viewController;
        dialog.shareContent = content;
        dialog.mode = FBSDKShareDialogModeWeb;
        [dialog show];
        
        return true;
    }

    void FacebookiOS::SetViewController (UIViewController * viewController)
    {
        _viewController = viewController;
    }
}