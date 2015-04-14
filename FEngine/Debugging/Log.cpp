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
        int elapsedTimeINT = gApp->GetElapsedTime();
        int sec = elapsedTimeINT % 60;
        elapsedTimeINT /= 60;
        int min = elapsedTimeINT % 60;
        
        string elapsedTimeStr = string("m:") + to_string(min) + string(" s:") + to_string(sec);
        string newStr = string("[Dela|") + elapsedTimeStr + string("]  ") + message;
        if(function != "")
        {
            newStr += string(" {Fn:") + function;
            
            if (lineNo != -1) {
                newStr += string(" - Line:") + std::to_string(lineNo);
            }
            newStr += string("}");
        }
        
        newStr += "\n";
        
        PrintToConsole(newStr);
        //PrintToMemory(newStr);
    }
    
    void Log::PrintToXML (std::string message)
    {
    
    }
    
    void Log::PrintToMemory (std::string message)
    {
        _memoryLog += message;
    }
    
}