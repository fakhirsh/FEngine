//
//  View2DFactory.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 25/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "View2DFactory.h"

#include <string>
#include <iostream>
//#include <cstdlib>

#include "../../2D/SpriteNode.h"
#include "../../2D/ViewNode.h"
#include "../../2D/SceneNodeProperties2D.h"
#include "../../2D/TextureAtlas.h"

#include "../../Utility/Math.h"
#include "../../ResourceCache/IOManager.h"
#include "../../System/App.h"

#include "TextureAtlasFactory.h"
#include "ProgramFactory.h"
#include "SpriteNodeFactory.h"


extern FEngine::App * gApp;

namespace FEngine
{
    using namespace tinyxml2;
    using namespace std;
    
    View2DFactory::View2DFactory()
    {
        
    }
    
    View2DFactory::~View2DFactory()
    {
        
    }
        
    SceneNode2DPtr View2DFactory::CreateView(const string & xmlFile)
    {
        SceneNode2DPtr snPtr;
        
        // Load view xml file
        std::vector<char> viewMetaData;
        
        // Get full path to meta data
        std::string fullMetaPath = gApp->GetAssetPath() + xmlFile;
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
        const XMLElement * e = rootnode->ToElement();
        
        snPtr = CreateViewNode(e);

        return snPtr;

    }
    
    /**
     *    Views can be of differen types:
     *    1) "empty"	: Empty Container
     *    2) "sprite"	: A sprite having an atlas and a program.
     *    3) "font"	: A font object
     *    etc etc
     */
    SceneNode2DPtr View2DFactory::CreateViewNode(const tinyxml2::XMLElement * viewElement)
    {
        SceneNode2DPtr viewPtr;
        string viewType = viewElement->Attribute("type");
        if(viewType == "empty"){
            viewPtr = boost::make_shared<FEngine::ViewNode>();
        }
        else if(viewType == "sprite"){
            viewPtr = boost::make_shared<FEngine::SpriteNode>();
        }
        else{
            return SceneNode2DPtr();
        }
        
        viewPtr->GetSceneNodeProperties()->name = viewElement->Attribute("name");
        
        // Now process elements withing the current view
        viewElement = viewElement->FirstChildElement();
        
        while(viewElement)
        {
            if(string(viewElement->Value()) == "Position")
            {
                string sX = viewElement->Attribute("x");
                string sY = viewElement->Attribute("y");
                string sZ = viewElement->Attribute("z");
                
                viewPtr->GetSceneNodeProperties()->x = atoi(sX.c_str());
                viewPtr->GetSceneNodeProperties()->y = atoi(sY.c_str());
                viewPtr->GetSceneNodeProperties()->zOrder = atoi(sZ.c_str());
            }
            else if(string(viewElement->Value()) == "Scale")
            {
                string sX = viewElement->Attribute("x");
                string sY = viewElement->Attribute("y");
                
                viewPtr->GetSceneNodeProperties()->scaleX = atof(sX.c_str());
                viewPtr->GetSceneNodeProperties()->scaleY = atof(sY.c_str());
            }
            else if(string(viewElement->Value()) == "Alpha")
            {
                string a = viewElement->Attribute("value");
                viewPtr->GetSceneNodeProperties()->alpha = atof(a.c_str());
            }
            else if(string(viewElement->Value()) == "Angle")
            {
                string a = viewElement->Attribute("value");
                viewPtr->GetSceneNodeProperties()->angle = atof(a.c_str());
            }
            else if(string(viewElement->Value()) == "Tint")
            {
                string r = viewElement->Attribute("r");
                string g = viewElement->Attribute("g");
                string b = viewElement->Attribute("b");
                
                viewPtr->GetSceneNodeProperties()->tintColor.r = atof(r.c_str());
                viewPtr->GetSceneNodeProperties()->tintColor.g = atof(g.c_str());
                viewPtr->GetSceneNodeProperties()->tintColor.b = atof(b.c_str());
            }
            else if(string(viewElement->Value()) == "Anchor")
            {
                float x, y;
                sscanf(viewElement->Attribute("x"), "%f", &x);
                sscanf(viewElement->Attribute("y"), "%f", &y);
                
                viewPtr->GetSceneNodeProperties()->anchor.x = x;
                viewPtr->GetSceneNodeProperties()->anchor.y = y;
            }
            else if(string(viewElement->Value()) == "Shear")
            {
                float x, y;
                sscanf(viewElement->Attribute("x"), "%f", &x);
                sscanf(viewElement->Attribute("y"), "%f", &y);
                
                viewPtr->GetSceneNodeProperties()->shearX = x;
                viewPtr->GetSceneNodeProperties()->shearY = y;
            }
            else if(string(viewElement->Value()) == "Sprite")
            {
                string name = viewElement->Attribute("name");
                viewPtr->GetSceneNodeProperties()->name = name;
                
                ProgramFactory pf;
                name = viewElement->Attribute("programName");
                viewPtr->GetSceneNodeProperties()->program = pf.CreateProgram(name);
                
                TextureAtlasFactory taf;
                name = viewElement->Attribute("atlasName");
                TextureAtlasPtr taPtr = taf.CreateTextureAtlas(name);
                
                string spriteName = viewPtr->GetSceneNodeProperties()->name;
                
                if(!taPtr->IsSpriteValid(spriteName)){
                    cout << "SpriteNodeFactory::CreateSpriteNode: Invalid sprite name -> " << spriteName << endl;
                    return SpriteNodePtr();
                }
                
                viewPtr->GetSceneNodeProperties()->width         =   taPtr->GetWidth(spriteName);
                viewPtr->GetSceneNodeProperties()->height        =   taPtr->GetHeight(spriteName);
                viewPtr->GetSceneNodeProperties()->u             =   taPtr->GetU(spriteName);
                viewPtr->GetSceneNodeProperties()->v             =   taPtr->GetV(spriteName);
                viewPtr->GetSceneNodeProperties()->uW            =   taPtr->GetUWidth(spriteName);
                viewPtr->GetSceneNodeProperties()->vH            =   taPtr->GetVHeight(spriteName);
                
                viewPtr->GetSceneNodeProperties()->textureAtlas = taPtr;

            }
            else if(string(viewElement->Value()) == "View")
            {
                SceneNode2DPtr childViewPtr = CreateViewNode(viewElement);
                viewPtr->AddChild(childViewPtr);
            }
            
            viewElement = viewElement->NextSiblingElement();
        }
        
        return viewPtr;
    }
    
}

