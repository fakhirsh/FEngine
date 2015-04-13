//
//  Log.h
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <string>

namespace FEngine
{
    class Log
    {
    public:
        Log();
        virtual ~Log();
        
        bool            Init            ();
        void            Print           (std::string message, std::string function = "", int lineNo = -1);
        
    private:
        // Internal buffer to redirect Log messages to game UI
        void            PrintToMemory   (std::string message);
        void            PrintToXML      (std::string message);
        
        virtual void    PrintToNetwork  (std::string message)   =   0;
        virtual void    PrintToConsole  (std::string message)   =   0;
        
        //bool    _printToXML;
        
        std::string     _memoryLog;
    };
}