//
//  LogAndroid.h
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Log.h"

#include <string>

namespace FEngine
{
    class LogAndroid : public Log
    {
    public:
        LogAndroid();
        virtual ~LogAndroid();
        
    private:
        virtual void    PrintToConsole  (std::string message);
        virtual void    PrintToNetwork  (std::string message);
        
    };
}