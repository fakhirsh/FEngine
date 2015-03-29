//
//  SpriteNodeFactory.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SpriteNodeFactory.h"

#include <string>
#include <iostream>
//#include <cstdlib>

#include "../../2D/SpriteNode.h"
#include "../../2D/SceneNodeProperties2D.h"
#include "../../2D/TextureAtlas.h"

#include "../../Utility/Math.h"
#include "../../ResourceCache/IOManager.h"
#include "../../System/App.h"

#include "TextureAtlasFactory.h"
#include "ProgramFactory.h"


extern FEngine::App * gApp;

namespace FEngine
{
    using namespace tinyxml2;
    using namespace std;
    
    SpriteNodeFactory::SpriteNodeFactory()
    {
        
    }
    
    SpriteNodeFactory::~SpriteNodeFactory()
    {
        
    }

    SpriteNodePtr SpriteNodeFactory::CreateSpriteNode(const XMLElement * viewElement)
    {
        
        SpriteNodePtr snPtr = boost::make_shared<SpriteNode>();
        snPtr->SetID(gApp->GetNextGUID());
        
        string name = viewElement->Attribute("spriteName");
        snPtr->GetSceneNodeProperties()->name = name;
        
        ProgramFactory pf;
        name = viewElement->Attribute("programName");
        snPtr->GetSceneNodeProperties()->program = pf.CreateProgram(name);
        
        TextureAtlasFactory taf;
        name = viewElement->Attribute("atlasName");
        TextureAtlasPtr taPtr = taf.CreateTextureAtlas(name);
        
        string spriteName = snPtr->GetSceneNodeProperties()->name;
        
        if(!taPtr->IsSpriteValid(spriteName)){
            cout << "SpriteNodeFactory::CreateSpriteNode: Invalid sprite name -> " << spriteName << endl;
            return SpriteNodePtr();
        }
        
        snPtr->GetSceneNodeProperties()->width         =   taPtr->GetWidth(spriteName);
        snPtr->GetSceneNodeProperties()->height        =   taPtr->GetHeight(spriteName);
        snPtr->GetSceneNodeProperties()->u             =   taPtr->GetU(spriteName);
        snPtr->GetSceneNodeProperties()->v             =   taPtr->GetV(spriteName);
        snPtr->GetSceneNodeProperties()->uW            =   taPtr->GetUWidth(spriteName);
        snPtr->GetSceneNodeProperties()->vH            =   taPtr->GetVHeight(spriteName);
        
        snPtr->GetSceneNodeProperties()->textureAtlas = taPtr;
        
        viewElement = viewElement->FirstChildElement();
        
        while(viewElement)
        {
            if(string(viewElement->Value()) == "Position")
            {
                string sX = viewElement->Attribute("x");
                string sY = viewElement->Attribute("y");
                
                snPtr->GetSceneNodeProperties()->x = atoi(sX.c_str());
                snPtr->GetSceneNodeProperties()->y = atoi(sY.c_str());
            }
            else if(string(viewElement->Value()) == "Scale")
            {
                string sX = viewElement->Attribute("x");
                string sY = viewElement->Attribute("y");
                
                snPtr->GetSceneNodeProperties()->scaleX = atof(sX.c_str());
                snPtr->GetSceneNodeProperties()->scaleY = atof(sY.c_str());
            }
            else if(string(viewElement->Value()) == "Alpha")
            {
                string a = viewElement->Attribute("value");
                snPtr->GetSceneNodeProperties()->alpha = atof(a.c_str());
            }
            else if(string(viewElement->Value()) == "Angle")
            {
                string a = viewElement->Attribute("value");
                snPtr->GetSceneNodeProperties()->angle = Math::DegToRad(atof(a.c_str()));
            }
            else if(string(viewElement->Value()) == "Tint")
            {
                string r = viewElement->Attribute("r");
                string g = viewElement->Attribute("g");
                string b = viewElement->Attribute("b");
                
                snPtr->GetSceneNodeProperties()->tintColor.r = atof(r.c_str());
                snPtr->GetSceneNodeProperties()->tintColor.g = atof(g.c_str());
                snPtr->GetSceneNodeProperties()->tintColor.b = atof(b.c_str());
            }
            
            viewElement = viewElement->NextSiblingElement();
        }
        
        return snPtr;
        
    }
    
}