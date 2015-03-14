//
//  IOManagerHelper.h
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <string>
#include <fstream>

namespace FEngine
{
    /**
     * Common OS independent helper IO functions
     * Reason for creating this separate file is to reuse functions as much as possible
     */
    
    namespace IOManagerHelper
    {
        bool GetFileStreamUsingCPP(std::string inFile, std::string & dataStream);
    };
    
};

