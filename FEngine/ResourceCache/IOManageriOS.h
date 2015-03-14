//
//  IOManageriOS.h
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __Game__IOManageriOS__
#define __Game__IOManageriOS__

#include "IOManager.h"

namespace FEngine
{
    /**
     * Concrete class for handing files on iOS
     */
    class IOManageriOS : public IOManager
    {
    public:
        IOManageriOS();
        virtual ~IOManageriOS();
        
        /**
         * Opens file natively and returns raw data stream.
         */
        //virtual bool GetFileStream(std::string inFile, std::string & dataStream);
        
        virtual bool GetAssetStream(std::string assetPath, std::vector<char> & buffer);
        
        //unsigned int GetGLTextureFromPngFile(std::string pngFile);
        
    private:
        
    };

};

#endif /* defined(__Game__IOManageriOS__) */
