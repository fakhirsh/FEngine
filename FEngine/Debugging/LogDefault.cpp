//
//  LogDefault.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "LogDefault.h"

#include <iostream>

using namespace std;

namespace FEngine
{

    LogDefault::LogDefault ()
    {
    
    }
    
    LogDefault::~LogDefault ()
    {
    
    }
        
    void LogDefault::PrintToConsole (std::string message)
    {
        cout << message;
    }
    
    void LogDefault::PrintToNetwork  (std::string message)
    {
        // SendToNetwork(message);
    }
}