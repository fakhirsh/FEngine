//
//  FileManagerDefault.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "IOManagerDefault.h"
//#include "IOManagerHelper.h"

#include <fstream>


namespace Fakhir
{
    IOManagerDefault::IOManagerDefault()
    {
        
    }
    
    IOManagerDefault::~IOManagerDefault()
    {
        
    }
    
    bool IOManagerDefault::GetAssetStream(std::string assetPath, std::vector<char> & buffer)
    {
        
        std::ifstream assetFile(assetPath.c_str(), std::ios::binary);
        if (!assetFile)
        {
            return false;
        }
        
        // Calculate file size
        assetFile.seekg (0, assetFile.end);
        int fileSize = (int)assetFile.tellg();
        assetFile.seekg (0, assetFile.beg);
        
        buffer.resize(fileSize);
        
        assetFile.read(&buffer[0], fileSize);
        
        assetFile.close();
        
        return true;
    }
    
    /*
    bool IOManagerDefault::GetFileStream(std::string inFile, std::string & dataStream)
    {
        // Reuse common functions as much as possible.
        if (!IOManagerHelper::GetFileStreamUsingCPP(inFile, dataStream)) {
            return false;
        }
        
        return true;
        
        std::ifstream sourceFile( inFile.c_str() );
        
        //Source file loaded
        if( sourceFile )
        {
            // Get RAW data stream from file source
            dataStream.assign( ( std::istreambuf_iterator< char >( sourceFile ) ), std::istreambuf_iterator< char >() );
        }
        else
        {
            // Source file couldn't be loaded.
            // return loading error here...
        }
         
    }
    */
        
    //unsigned int IOManagerDefault::GetGLTextureFromPngFile(std::string pngFile)
    //{
    //   return 0;
    //}
    
};

