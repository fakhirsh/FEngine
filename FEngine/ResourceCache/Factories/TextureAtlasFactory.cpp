//
//  TextureAtlasFactory.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "TextureAtlasFactory.h"
#include "../../2D/TextureAtlas.h"
#include "../ResourceCache.h"
#include "../IOManager.h"
#include "../../System/App.h"


#include <string>
#include <sstream>


extern FEngine::App * gApp;

namespace FEngine
{
    using namespace std;
    
    TextureAtlasFactory::TextureAtlasFactory()
    {
    
    }
    
    TextureAtlasFactory::~TextureAtlasFactory()
    {
    
    }
        
    TextureAtlasPtr TextureAtlasFactory::CreateTextureAtlas(const string & atlasName)
    {
        TextureAtlasPtr taPtr;
        
        taPtr = ResourceCache::Get()->GetTextureAtlas(atlasName);
        
        // TextureAtlas aleady loaded in the Resource Cache
        if (taPtr) return taPtr;
        
        // Otherwise load atlas and return its pointer
        taPtr = boost::make_shared<FEngine::TextureAtlas>();
        
        std::vector<char> textureData;
        
        IOManager * ioMgr = gApp->GetIOManager();
        
        // Get full path to PNG file
        std::string fullTexturePath = gApp->GetAssetPath() + "Textures/" + atlasName + ".png";
        // Read raw byte stream from the source file
        ioMgr->GetAssetStream(fullTexturePath, textureData);
        
        std::string textureString;
        for (int i = 0; i < textureData.size(); i++)
        {
            textureString += textureData[i];
        }
        
        std::istringstream textureStream( textureString );
        
        std::vector<char> metaData;
        
        // Get full path to meta data
        std::string fullMetaPath = gApp->GetAssetPath() + "Textures/" + atlasName + ".xml";
        // Read raw byte stream from the source file
        ioMgr->GetAssetStream(fullMetaPath, metaData);
        
        std::string metaString;
        for (int i = 0; i < metaData.size(); i++)
        {
            metaString += metaData[i];
        }
        
        taPtr->Init(atlasName, textureStream, metaString);
        
        ResourceCache::Get()->AddTextureAtlas(taPtr);

        
        return taPtr;
    }
        
    
}