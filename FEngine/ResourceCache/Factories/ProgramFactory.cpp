//
//  ProgramFactory.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ProgramFactory.h"
#include <string>

#include "../../ResourceCache/IOManager.h"
#include "../../System/App.h"
#include "../ResourceCache.h"

#include "../../Renderer/GLES20/TexturedVertexProgram.h"
#include "../../Renderer/GLES20/SimpleVertex2DProgram.h"

namespace FEngine
{

    using namespace std;
    
    ProgramFactory::ProgramFactory()
    {
    
    }
    
    ProgramFactory::~ProgramFactory()
    {
    
    }
        
    ProgramPtr ProgramFactory::CreateProgram(const std::string & name)
    {
        ProgramPtr progPtr;
        
        progPtr = ResourceCache::Get()->GetProgram(name);
        
        // Program is already loaded. Simply return the current one.
        if(progPtr) return progPtr;
        
        // Program not found, load it, initialize it and then return it.
        
        if(name == "TintedTexture")
        {
            progPtr = boost::make_shared<TexturedVertexProgram>();
        }
        else if(name == "SimpleVertex2D")
        {
            progPtr = boost::make_shared<SimpleVertex2DProgram>();
        }
        
        progPtr->Init();
        progPtr->Bind();
        
        ResourceCache::Get()->AddProgram(progPtr);
        
        return progPtr;
    }

}