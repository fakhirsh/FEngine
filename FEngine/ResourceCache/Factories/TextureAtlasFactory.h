//
//  TextureAtlasFactory.h
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../../PointerDefs.h"

#include <string>

namespace FEngine
{
    class TextureAtlasFactory
    {
    public:
        TextureAtlasFactory();
        ~TextureAtlasFactory();
        
        TextureAtlasPtr CreateTextureAtlas(const std::string & atlasName);
        
    private:
        
    };
}