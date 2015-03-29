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
        const XMLElement * e = rootnode->FirstChildElement();
        
        snPtr = CreateViewNode(e);
        
        
        return snPtr;

    }
    
    SceneNode2DPtr View2DFactory::CreateViewNode(const tinyxml2::XMLElement * viewElement)
    {
        SpriteNodePtr snPtr = boost::make_shared<SpriteNode>();
        
        string name = viewElement->Value();
        
        while(viewElement)
        {
            if (string(viewElement->Value()) == "Sprite") {
                
                SpriteNodeFactory sf;
                snPtr = sf.CreateSpriteNode(viewElement);
            }
            else if(string(viewElement->Value()) == "View")
            {
                SceneNode2DPtr childSnPtr = CreateViewNode(viewElement->FirstChildElement());
                snPtr->AddChild(childSnPtr);
            }
            
            viewElement = viewElement->NextSiblingElement();
        }
        
        return snPtr;
    }
    
}