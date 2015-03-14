//
//  IOManagerDefault.h
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __Game__IOManagerDefault__
#define __Game__IOManagerDefault__

#include "IOManager.h"

namespace Fakhir
{
    /**
     * This is the default file manager using standard C+ fstream libraries for reading files
     */
    class IOManagerDefault : public IOManager
    {
    public:
        IOManagerDefault();
        virtual ~IOManagerDefault();
        
        /**
         * Opens file natively and returns raw data stream.
         */
        //virtual bool GetFileStream(std::string inFile, std::string & dataStream);
        
        virtual bool GetAssetStream(std::string assetPath, std::vector<char> & buffer);
        
        //virtual unsigned int GetGLTextureFromPngFile(std::string pngFile);
        
    private:
        
    };
    
};


#endif /* defined(__Game__IOManagerDefault__) */
