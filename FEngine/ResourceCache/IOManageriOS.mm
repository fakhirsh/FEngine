//
//  FileManageriOS.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/12/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#import <UIKit/UIKit.h>

#include "IOManageriOS.h"
#include "IOManagerHelper.h"

#include "../Common.h"

namespace Fakhir
{
    IOManageriOS::IOManageriOS()
    {
    
    }
    
    IOManageriOS::~IOManageriOS()
    {
    
    }
    
    bool IOManageriOS::GetAssetStream(std::string assetPath, std::vector<char> & buffer)
    {
        return false;
    }
    
    /*
    bool IOManageriOS::GetFileStream(std::string inFile, std::string & dataStream)
    {
        // ... To be implemented ...
        // Reuse common functions as much as possible.
        if (!IOManagerHelper::GetFileStreamUsingCPP(inFile, dataStream)) {
            return false;
        }
        
        return true;
    }
    */
    /*
    unsigned int IOManageriOS::GetGLTextureFromPngFile(std::string pngFile)
    {
        // Load PNG data into memory
        NSString* path = [NSString stringWithUTF8String:pngFile.c_str()];
        UIImage* sourceImage = [UIImage imageWithContentsOfFile:path];
        UIImage* flippedImage = [UIImage imageWithCGImage:sourceImage.CGImage
                                                    scale:sourceImage.scale
                                              orientation:UIImageOrientationUpMirrored];
        
        CGImageRef cgImage = flippedImage.CGImage;
        
        int width = CGImageGetWidth(cgImage);
        int height = CGImageGetHeight(cgImage);

        CFDataRef imageData = CGDataProviderCopyData(CGImageGetDataProvider(cgImage));
        
        // Generate GL texture.
        GLuint glTexture = 0;
        glGenTextures(1, &glTexture);
        glBindTexture(GL_TEXTURE_2D, glTexture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        void * pixels = (void*) CFDataGetBytePtr(imageData);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
        
        // GL texture is ready. Finally release PNG from memory
        CFRelease(imageData);
        
        return (unsigned int)glTexture;
    }
     */
    
};