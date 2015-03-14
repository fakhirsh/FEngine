//
//  IOManagerAndroid.h
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "IOManager.h"

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/log.h>

namespace FEngine
{
    /**
     * This is the default file manager using standard C+ fstream libraries for reading files
     */
    class IOManagerAndroid : public IOManager
    {
    public:
        IOManagerAndroid();
        virtual ~IOManagerAndroid();
        
        /**
         * Opens file natively and returns raw data stream.
         */
        //virtual bool GetFileStream(std::string inFile, std::string & dataStream);
        
        virtual bool GetAssetStream(std::string assetPath, std::vector<char> & buffer);
        
        //virtual unsigned int GetGLTextureFromPngFile(std::string pngFile);

        static AAssetManager * assetManager;
        
    private:
        
    };
    
};


