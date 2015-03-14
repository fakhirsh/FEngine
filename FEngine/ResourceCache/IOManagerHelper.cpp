//
//  IOManagerHelper.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "IOManagerHelper.h"

namespace FEngine
{
    /**
     * Common OS independent helper IO functions
     */
    
    namespace IOManagerHelper
    {
        
        bool GetFileStreamUsingCPP(std::string inFile, std::string & dataStream)
        {
            std::ifstream sourceFile( inFile.c_str() );
            
            //Source file loaded
            if( sourceFile )
            {
                // Get RAW data stream from file source
                dataStream.assign( ( std::istreambuf_iterator< char >( sourceFile ) ), std::istreambuf_iterator< char >() );
                return true;
            }
            else
            {
                // Source file couldn't be loaded.
                return false;
            }
        }
        
    };
    
};
