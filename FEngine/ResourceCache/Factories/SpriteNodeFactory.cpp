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

    SceneNode2DPtr SpriteNodeFactory::CreateSpriteNode(const XMLElement * sceneNodeElement)
    {
        
        SceneNode2DPtr snPtr;
        
        // Get the xml Resource file for this view
        string xmlFile = sceneNodeElement->Attribute("xmlFile");
        
        // Load view xml file
        std::vector<char> viewMetaData;
        
        // Get full path to meta data
        std::string fullMetaPath = gApp->GetAssetPath() + "Views/" + xmlFile;
        // Read raw byte stream from the source file
        IOManager * ioMgr = gApp->GetIOManager();
        ioMgr->GetAssetStream(fullMetaPath, viewMetaData);
        
        std::string viewMetaString;
        for (int i = 0; i < viewMetaData.size(); i++)
        {
            viewMetaString += viewMetaData[i];
        }

        XMLDocument coordXMLdoc;
        XMLError xmlErr;
        
        xmlErr = coordXMLdoc.Parse(viewMetaString.c_str());
        
        if(xmlErr != XML_SUCCESS)
        {
            std::cout << "SpriteNodeFactory::CreateSpriteNode -> Failed to parse view XML" << xmlFile << std::endl;
            return snPtr;
        }
        
        XMLNode * rootnode = coordXMLdoc.FirstChild();
        XMLNode * childNode = rootnode->FirstChild();
        const XMLElement * e = childNode->ToElement();
    
        snPtr = CreateView(e);
        
        return snPtr;
        
    }
    
    SceneNode2DPtr SpriteNodeFactory::CreateView(const tinyxml2::XMLElement * viewElement)
    {
        SpriteNodePtr snPtr = boost::make_shared<SpriteNode>();

        string name = viewElement->Value();
        
        while(viewElement)
        {
            if (string(viewElement->Value()) == "Sprite") {
                
                string name = viewElement->Attribute("spriteName");
                snPtr->GetSceneNodeProperties()->name = name;
                
                ProgramFactory pf;
                name = viewElement->Attribute("programName");
                snPtr->GetSceneNodeProperties()->program = pf.CreateProgram(name);
                
                TextureAtlasFactory taf;
                name = viewElement->Attribute("atlasName");
                TextureAtlasPtr taPtr = taf.CreateTextureAtlas(name);
                
                string spriteName = snPtr->GetSceneNodeProperties()->name;
                
                snPtr->GetSceneNodeProperties()->width         =   taPtr->GetWidth(spriteName);
                snPtr->GetSceneNodeProperties()->height        =   taPtr->GetHeight(spriteName);
                snPtr->GetSceneNodeProperties()->u             =   taPtr->GetU(spriteName);
                snPtr->GetSceneNodeProperties()->v             =   taPtr->GetV(spriteName);
                snPtr->GetSceneNodeProperties()->uW            =   taPtr->GetUWidth(spriteName);
                snPtr->GetSceneNodeProperties()->vH            =   taPtr->GetVHeight(spriteName);
                
                snPtr->GetSceneNodeProperties()->textureAtlas = taPtr;
            }
            else if(string(viewElement->Value()) == "Position")
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
            else if(string(viewElement->Value()) == "View")
            {
                SceneNode2DPtr childSnPtr = CreateView(viewElement->FirstChildElement());
                snPtr->AddChild(childSnPtr);
            }
            
            viewElement = viewElement->NextSiblingElement();
        }

        return snPtr;
    }
    
}