//
//  BasicShareiOS.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 24/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "BasicShareiOS.h"

#include "../Debugging/LogDefault.h"
#include "../System/App.h"

extern FEngine::App * gApp;


namespace FEngine
{
 
    bool BasicShareiOS::Share()
    {
        
        gApp->GetLog()->Print("BasicShareiOS::Share()");
        
        return true;
    }
    
}