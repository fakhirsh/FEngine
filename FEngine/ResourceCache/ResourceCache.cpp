//
//  ResourceCache.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "ResourceCache.h"

#include "../Graphics2D/Texture.h"
#include "../Renderer/GLES20/Program.h"
//#include "../Renderer/VBO.h"

namespace Fakhir
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
    /////////////  TEXTURE RELATED  /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////

    bool ResourceCache::AddTexture(Texture * texture)
    {
        // CHeck if the textue is already loaded
        if(_textureMap[texture->GetName()]) return false;
        
        _textureMap[texture->GetName()] = texture;
        
        return true;
    }

    Texture * ResourceCache::GetTexture(std::string textureName)
    {
        return _textureMap[textureName];
    }

    void ResourceCache::RemoveTexture(std::string textureName)
    {
        Texture * tmpTex = _textureMap[textureName];
        if(tmpTex)
        {
            std::map<std::string, Texture *>::iterator it;
            it = _textureMap.find(textureName);
            _textureMap.erase(it);
            
            tmpTex->Unload();
            
            delete tmpTex;
        }
    }


    /////////////////////////////////////////////////////////////////////////////////
    /////////////  PROGRAM RELATED  /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////

    bool ResourceCache::AddProgram(Program * program)
    {
        if(_programMap[program->GetProgramName()]) return false;
        
        _programMap[program->GetProgramName()] = program;
        
        return true;
    }

    Program * ResourceCache::GetProgram(std::string programName)
    {
        return _programMap[programName];
    }

    void ResourceCache::RemoveProgram(std::string programName)
    {
        Program * p = _programMap[programName];
        if(p)
        {
            std::map<std::string, Program *>::iterator it;
            it = _programMap.find(programName);
            _programMap.erase(it);
            
            p->Unload();
            
            delete p;
        }
    }

    /////////////////////////////////////////////////////////////////////////////////
    /////////////////  VBO RELATED  /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
/*
    bool ResourceCache::AddVBO(VBO * vbo)
    {
        return true;
    }

    VBO * ResourceCache::GetVBO(std::string vboName)
    {
        return NULL;
    }

    void ResourceCache::RemoveVBO(std::string vboName)
    {
        
    }
*/
    
};

