//
//  Log.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Log.h"

#include "../System/App.h"
#include "../Debugging/Log.h"

using namespace FEngine;
extern App * gApp;

using namespace std;

namespace FEngine
{
    
    Log::Log()
    {
        //_printToXML = false;
    }
    
    Log::~Log()
    {
    
    }
    
    bool Log::Init ()
    {
        return true;
    }
    
    void Log::Print (string message, string function, int lineNo)
    {
        string newStr = string("[FEngine|") + to_string(gApp->GetElapsedTime()) + string("]  ") + message;
        if(function != "")
        {
            newStr += string(" {Fn:") + function;
            
            if (lineNo != -1) {
                newStr += string(" - Line:") + std::to_string(lineNo);
            }
            newStr += string("}");
        }
        
        PrintToConsole(newStr);
    }
    
    void Log::PrintToXML (std::string message)
    {
    
    }
    
    void Log::PrintToMem (std::string message)
    {
    
    }
    
}