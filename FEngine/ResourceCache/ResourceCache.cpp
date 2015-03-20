//
//  ResourceCache.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "ResourceCache.h"

//#include "../Graphics2D/Texture.h"
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
        if(_programMap[program->GetProgramName()]) return false;
        
        _programMap[program->GetProgramName()] = program;
        
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


};

