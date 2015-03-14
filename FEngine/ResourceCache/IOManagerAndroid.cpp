//
//  FileManagerDefault.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "IOManagerAndroid.h"

#include <jni.h>


namespace FEngine
{

    AAssetManager * IOManagerAndroid::assetManager = NULL;
    
    IOManagerAndroid::IOManagerAndroid()
    {
        
    }
    
    IOManagerAndroid::~IOManagerAndroid()
    {
        
    }
    
    bool IOManagerAndroid::GetAssetStream(std::string assetPath, std::vector<char> & buffer)
    {
        
        // Had to do this because otherwise the compiler was whining about
        // passing incorrect types --- namespaces, static variables and
        // that sort of crap....
        //AAssetManager * assetMgr = assetManager;
        
        AAsset * asset = AAssetManager_open(assetManager, assetPath.c_str(), AASSET_MODE_UNKNOWN);
        if(!asset)
        {
            return false;
        }
        
        int size = AAsset_getLength(asset);
        
        buffer.resize(size);
        AAsset_read (asset, &buffer[0], size);
        
        AAsset_close(asset);
        
        return true;
    }
    
};

