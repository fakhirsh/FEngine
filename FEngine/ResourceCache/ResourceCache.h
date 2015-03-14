//
//  ResourceCache.h
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __WordGame__ResourceCache__
#define __WordGame__ResourceCache__


#include <string>
#include <map>

namespace Fakhir
{
    // PLEASE ADD COMMENTS About how to use this class

    class Program;
    class Texture;
    //class VBO;

    class ResourceCache
    {
    public:
        ~ResourceCache(void);
        
        static ResourceCache * Get();
        void		Init();
        
        /**
         * @param	texture			Actual pre-initialised texture object
         */
        bool		AddTexture(Texture * texture);
        Texture *	GetTexture(std::string textureName);
        void		RemoveTexture(std::string textureName);
        
        /**
         * @param	program			Actual pre-initialised program object
         */
        bool		AddProgram(Program * program);
        Program *	GetProgram(std::string programName);
        void		RemoveProgram(std::string programName);
        
        /**
         * @param	VBO				Actual pre-loaded VBO
         */
        //bool		AddVBO(VBO * vbo);
        //VBO	*	GetVBO(std::string vboName);
        //void		RemoveVBO(std::string vboName);
        
        
    private:
        ResourceCache(void);
        
        static ResourceCache * _instance;
        
        // Dictionary of all textures
        std::map<std::string, Texture * >	_textureMap;
        
        // Dictionary of all Shaders
        std::map<std::string, Program * >	_programMap;
        
        // Dictionary of all VBOs
        //std::map<std::string, VBO * >		_vboMap;
        
    };

};

#endif /* defined(__WordGame__ResourceCache__) */
