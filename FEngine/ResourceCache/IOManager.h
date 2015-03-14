//
//  IOManager.h
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __Game__IOManager__
#define __Game__IOManager__


#include <string>
#include <vector>


namespace Fakhir
{
    /**
     * Abstract class for handing os dependent files
     */
    class IOManager
    {
    public:
        IOManager(){}
        virtual ~IOManager(){}
        
        /**
         * Gets RAW data stream from file
         */
        //virtual bool GetFileStream(std::string inFile, std::string & dataStream) = 0;
        
        virtual bool GetAssetStream(std::string assetPath, std::vector<char> & buffer) = 0;
        
        /**
         * Process PNG file and return OpenGL texture
         */
        //virtual unsigned int GetGLTextureFromPngFile(std::string pngFile) = 0;
        
    };

};

#endif /* defined(__Game__IOManager__) */
