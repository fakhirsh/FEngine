//
//  ResourceCache.h
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../PointerDefs.h"

#include <string>
#include <map>


namespace FEngine
{

    class ResourceCache
    {
    public:
        ~ResourceCache();
        
        static ResourceCache * Get          ();
        
        void            Init                ();
        
        /**
         * @param	program			Actual pre-initialised program object
         */
        bool            AddProgram          (ProgramPtr program);
        ProgramPtr      GetProgram          (std::string programName);
        void            RemoveProgram       (std::string programName);
        
        /**
         * @param	TextureAtlas			Actual pre-initialised Texture Atlas object
         */
        bool            AddTextureAtlas     (TextureAtlasPtr textureAtlas);
        TextureAtlasPtr GetTextureAtlas     (std::string textureAtlasName);
        void            RemoveTextureAtlas  (std::string textureAtlasName);
        
    private:
        ResourceCache();
        
        static ResourceCache *              _instance;
        
        // Dictionary of all Shaders
        std::map<std::string, ProgramPtr >	_programMap;
        
        // Dictionary of all VBOs
        //std::map<std::string, VBO * >		_vboMap;
        
        // Dictionary of all Textures Atlases
        std::map<std::string, TextureAtlasPtr >	_textureAtlasMap;

    };

};

