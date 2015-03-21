//
//  ResourceCache.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "ResourceCache.h"

#include "../2D/TextureAtlas.h"
#include "../Renderer/GLES20/Program.h"
//#include "../Renderer/VBO.h"

namespace FEngine
{
    
    ResourceCache * ResourceCache::_instance = NULL;

    ResourceCache::ResourceCache(void)
    {
    }


    ResourceCache::~ResourceCache(void)
    {
    }

    ResourceCache * ResourceCache::Get()
    {
        if(!_instance)
        {
            _instance = new ResourceCache();
            _instance->Init();
        }
        
        return _instance;
    }

    void ResourceCache::Init()
    {
        
    }

    
    /////////////////////////////////////////////////////////////////////////////////
    /////////////  PROGRAM RELATED  /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////

    bool ResourceCache::AddProgram(ProgramPtr program)
    {
        if(_programMap[program->GetName()]) return false;
        
        _programMap[program->GetName()] = program;
        
        return true;
    }

    ProgramPtr ResourceCache::GetProgram(std::string programName)
    {
        return _programMap[programName];
    }

    void ResourceCache::RemoveProgram(std::string programName)
    {
        ProgramPtr p = _programMap[programName];
        if(p)
        {
            std::map<std::string, ProgramPtr>::iterator it;
            it = _programMap.find(programName);
            _programMap.erase(it);
            
            p->Unload();
        }
    }

    /////////////////////////////////////////////////////////////////////////////////
    /////////////  TEXTURE ATLAS RELATED  ///////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////

    
    bool ResourceCache::AddTextureAtlas (TextureAtlasPtr textureAtlas)
    {
        if(_textureAtlasMap[textureAtlas->GetName()]) return false;
        
        _textureAtlasMap[textureAtlas->GetName()] = textureAtlas;
        
        return true;
    }
    
    TextureAtlasPtr ResourceCache::GetTextureAtlas (std::string textureAtlasName)
    {
        return _textureAtlasMap[textureAtlasName];
    }
    
    void ResourceCache::RemoveTextureAtlas (std::string textureAtlasName)
    {
        TextureAtlasPtr t = _textureAtlasMap[textureAtlasName];
        if(t)
        {
            std::map<std::string, TextureAtlasPtr>::iterator it;
            it = _textureAtlasMap.find(textureAtlasName);
            _textureAtlasMap.erase(it);
            
            //
            //t->UnLoad();
            
        }
    }

};

