//
//  TextureAtlas.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "TextureAtlas.h"
#include "Texture.h"
#include "../ResourceCache/ResourceCache.h"

#include "../System/App.h"

#include "../Common.h"

extern FEngine::App * gApp;

namespace FEngine
{

    using namespace tinyxml2;
    
    TextureAtlas::TextureAtlas()
    {
        
    }

    TextureAtlas::~TextureAtlas()
    {
    }

    bool TextureAtlas::Init(std::string atlasName, std::istream & textureStream, const std::string & metaDataXMLStream)
    {

        // Load generate OpenGL texture from raw PNG file stream
        
        _texture = boost::make_shared<FEngine::Texture>();
        
        if(!_texture->LoadFromStream(textureStream))
        {
            std::cout << "TextureAtlas::Init -> Failed to load texture" << std::endl;
            return false;
        }
        _texture->SetName(atlasName);
        //ResourceCache::Get()->AddTexture(_texture);
        
        //int textureWidth = ResourceCache::Get()->GetTexture(textureName)->GetWidth();
        //int textureHeight = ResourceCache::Get()->GetTexture(textureName)->GetHeight();
        
        int textureWidth    =   _texture->GetWidth();
        int textureHeight   =   _texture->GetHeight();
        
        // Load atlas meta data from raw XML stream
        
        XMLDocument coordXMLdoc;
        XMLError xmlErr;
        
        xmlErr = coordXMLdoc.Parse(metaDataXMLStream.c_str());
        
        
        if(xmlErr != XML_SUCCESS)
        {
            std::cout << "TextureAtlas::Init -> Failed to parse metadata XML" << std::endl;
            return false;
        }
        
        XMLNode * rootnode = coordXMLdoc.FirstChild();
        XMLNode * childNode = rootnode->FirstChild();
        XMLElement * e = childNode->ToElement();
        
        while(e)
        {
            std::string name = e->Attribute("name");
            std::string x = e->Attribute("x");
            std::string y = e->Attribute("y");
            std::string width = e->Attribute("width");
            std::string height = e->Attribute("height");
            
            SpriteMetaData s;
            s.x = atoi(x.c_str());
            s.y = atoi(y.c_str());
            s.width = atoi(width.c_str());
            s.height = atoi(height.c_str());
            
            s.u = float(s.x) / float(textureWidth);
            s.v = 1.0f - float(s.y) / float(textureHeight);
            s.uW = float(s.x + s.width) / float(textureWidth);
            s.vH = 1.0f - float(s.y + s.height) / float(textureHeight);
            
            _atlasData[name] = s;
            
            if(e->NextSibling())
            {
                e = e->NextSibling()->ToElement();
            }
            else
            {
                e = NULL;
            }
        }
        
        return true;
    }

    int TextureAtlas::GetX(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.x;
    }

    int TextureAtlas::GetY(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.y;
    }

    int TextureAtlas::GetWidth(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.width;
    }

    int TextureAtlas::GetHeight(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.height;
    }

    float TextureAtlas::GetU(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.u;
    }

    float TextureAtlas::GetV(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.v;
    }

    float TextureAtlas::GetUWidth(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.uW;
    }

    float TextureAtlas::GetVHeight(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.vH;
    }

    bool TextureAtlas::IsRotated(std::string spriteName)
    {
        SpriteMetaData s = _atlasData[spriteName];
        return s.rotated;
    }
    
    void TextureAtlas::Bind()
    {
        _texture->Bind();
    }

    void TextureAtlas::UnBind()
    {
        _texture->UnBind();
    }

    unsigned int TextureAtlas::GetTextureID()
    {
        return _texture->GetID();
    }

    std::string TextureAtlas::GetName()
    {
        return _textureAtlasName;
    }
    
    unsigned int TextureAtlas::GetID()
    {
        return _id;
    }
    
};


