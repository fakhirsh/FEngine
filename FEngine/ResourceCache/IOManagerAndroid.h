//
//  IOManagerAndroid.h
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __Game__IOManagerAndroid__
#define __Game__IOManagerAndroid__

#include "IOManager.h"

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/log.h>

namespace Fakhir
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


#endif /* defined(__Game__IOManagerAndroid__) */
