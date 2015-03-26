//
//  ActorFactory.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ActorFactory.h"

#include <string>
#include <iostream>
//#include <cstdlib>


#include "../../ActorManager/Actor.h"
#include "../../ActorManager/Components/PhysicsComponent.h"
#include "../../ActorManager/Components/TransformComponent.h"
#include "../../ActorManager/Components/ViewComponent.h"

#include "../../2D/SpriteNode.h"

#include "../../Utility/Math.h"
#include "../../ResourceCache/IOManager.h"
#include "../../System/App.h"

#include "View2DFactory.h"


extern FEngine::App * gApp;

namespace FEngine
{
    using namespace tinyxml2;
    using namespace std;
    
    ActorFactory::ActorFactory()
    {
    
    }
    
    ActorFactory::~ActorFactory()
    {
    
    }
        
    ActorPtr ActorFactory::CreateActor(std::string xmlFilePath)
    {
        ActorPtr actor;
        
        IOManager * ioMgr = gApp->GetIOManager();

        std::vector<char> metaData;

        // Get full path to meta data
        std::string fullMetaPath = gApp->GetAssetPath() + xmlFilePath;
        // Read raw byte stream from the source file
        ioMgr->GetAssetStream(fullMetaPath, metaData);

        std::string metaString;
        for (int i = 0; i < metaData.size(); i++){
            metaString += metaData[i];
        }

        // Load atlas meta data from raw XML stream

        XMLDocument coordXMLdoc;
        XMLError xmlErr;

        xmlErr = coordXMLdoc.Parse(metaString.c_str());


        if(xmlErr != XML_SUCCESS){
            std::cout << "ActorFactory::CreateActor -> Failed to parse actor XML " << xmlFilePath << std::endl;
            // Return a NULL pointer
            return ActorPtr();
        }

        actor = boost::make_shared<Actor>();
        actor->_actorID = gApp->GetNextGUID();
        
        // Root node (Actor)
        XMLNode * rootNode = coordXMLdoc.FirstChild();
        
        const XMLElement * e = rootNode->FirstChildElement();
        
        while (e) {
            
            if(string(e->Value()) == string("Components")){
                const XMLElement * comp = e->FirstChildElement();
            
                while (comp) {
                    if(string(comp->Value()) == string("ActorView")){
                        string viewXml = comp->Attribute("xmlFile");
                        View2DFactory vf;
                        SceneNode2DPtr n = vf.CreateView(viewXml);
                        ViewComponentPtr vPtr = boost::static_pointer_cast<ViewComponent>(actor->_viewComponent);
                        vPtr = boost::make_shared<ViewComponent>();
                        vPtr->SetSceneNode2D(n);
                        vPtr->SetOwner(actor);
                        actor->_viewComponent = vPtr;
                    }
                    else if(string(comp->Value()) == string("Transform"))
                    {
                        float x     =   atof(comp->Attribute("x"));
                        float y     =   atof(comp->Attribute("y"));
                        float angle =   atof(comp->Attribute("angle"));
                        
                        actor->_transformComponent = boost::make_shared<TransformComponent>();
                        
                        TransformComponentPtr tcPtr = boost::static_pointer_cast<TransformComponent>(actor->_transformComponent);
                        
                        tcPtr->x        =   x;
                        tcPtr->y        =   y;
                        tcPtr->angle    =   angle;
                        
                        tcPtr->SetOwner(actor);
                        
                    }
                    else if(string(comp->Value()) == string("Physics"))
                    {
                        actor->_physicsComponent = boost::make_shared<PhysicsComponent>();
                        PhysicsComponentPtr pcPtr = boost::static_pointer_cast<PhysicsComponent>(actor->_physicsComponent);
                        
                        pcPtr->SetOwner(actor);
                    }
                    
                    comp = comp->NextSiblingElement();
                }
            }
            e = e->NextSiblingElement();
        }
        
        return actor;
    }

}