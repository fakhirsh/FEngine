//
//  FacebookiOS.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once


#include "Facebook.h"

#import <UIKit/UIKit.h>

namespace FEngine
{
    class FacebookiOS : public Facebook
    {
    public:
        FacebookiOS();
        virtual ~FacebookiOS();
        
        virtual bool    ShareURL            (std::string contentURL, std::string imgURL, std::string title, std::string description);

        void            SetViewController   (UIViewController * viewController);
        
    private:
        UIViewController * _viewController;
    };
}