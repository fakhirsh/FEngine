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

#include "../../../../GameLogic/Components/PlayerAnimation.h"
#include "../../../../GameLogic/Components/PlayerInput.h"

#include "../../ActorManager/Actor.h"
#include "../../ActorManager/ActorManager.h"
#include "../../ActorManager/Components/PhysicsComponent.h"
#include "../../ActorManager/Components/TransformComponent.h"
#include "../../ActorManager/Components/ViewComponent.h"
//#include "../../ActorManager/Components/InputComponent.h"

#include "../../EventDispatcher/EventDispatcher.h"
#include "../../EventDispatcher/DefaultEvents.h"
#include "../../StateManager/StateManager.h"

#include "../../2D/SpriteNode.h"

#include "../../Utility/Math.h"
#include "../../ResourceCache/IOManager.h"
#include "../../System/App.h"

#include "View2DFactory.h"
#include "PhysicsFactory.h"


extern FEngine::App * gApp;

namespace FEngine
{
    using namespace tinyxml2;
    using namespace std;
    
    ActorFactory::ActorFactory()
    {
        EventListenerDelegate setDbgNodeDelegateFn   = fastdelegate::MakeDelegate(this, &ActorFactory::SetDebugNodeListener);
        EventDispatcherPtr ed = StateManager::Get()->GetEventDispatcher();
        ed->AddListener(EventSetDebugNode::eventID, setDbgNodeDelegateFn);
    }
    
    ActorFactory::~ActorFactory()
    {
        EventListenerDelegate setDbgNodeDelegateFn   = fastdelegate::MakeDelegate(this, &ActorFactory::SetDebugNodeListener);
        EventDispatcherPtr ed = StateManager::Get()->GetEventDispatcher();
        ed->RemoveListener(EventSetDebugNode::eventID, setDbgNodeDelegateFn);
    }
        
    ActorPtr ActorFactory::CreateActor(std::string xmlFilePath)
    {
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
            std::cout << "ERROR -> Failed to parse actor XML file: " << xmlFilePath << std::endl;
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
                        vPtr->_sceneNode2D = n;
                        vPtr->SetOwner(actor);
                        
                        SceneNode2DPtr root =   StateManager::Get()->GetRootSceneNode2D();
                        root->AddChild(n);
                        
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
                        PhysicsFactory pf;
                        actor->_physicsComponent = pf.CreatePhysicsComponent(comp->Attribute("xmlFile"));
                        PhysicsComponentPtr pcPtr = boost::static_pointer_cast<PhysicsComponent>(actor->_physicsComponent);
                        
                        pcPtr->SetOwner(actor);
                    }
                    else if(string(comp->Value()) == string("Input"))
                    {
                        actor->_inputComponent = boost::make_shared<PlayerInput>();
                        boost::shared_ptr<PlayerInput> icPtr = boost::static_pointer_cast<PlayerInput>(actor->_inputComponent);
                        
                        icPtr->SetOwner(actor);
                    }
                    else if(string(comp->Value()) == string("Animation"))
                    {
                        actor->_animationComponent = boost::make_shared<PlayerAnimation>();
                        boost::shared_ptr<PlayerAnimation> paPtr = boost::static_pointer_cast<PlayerAnimation>(actor->_animationComponent);
                        
                        paPtr->SetOwner(actor);
                    }
                    else if(string(comp->Value()) == string("AI"))
                    {
                        
                    }
                    
                    comp = comp->NextSiblingElement();
                }
            }
            e = e->NextSiblingElement();
        }
        
        return actor;
    }

    void ActorFactory::SetDebugNodeListener(EventPtr e)
    {
        boost::shared_ptr<EventSetDebugNode> sdnEvent = boost::static_pointer_cast<EventSetDebugNode>(e);
        
        //ViewComponentPtr vcPtr = boost::static_pointer_cast<ViewComponent>(actor->GetViewComponent());
        //vcPtr->SetDebugNode2D(sdnEvent->_debugNode);
        
        //vcPtr->GetSceneNode2D()->AddChild(sdnEvent->_debugNode);
    }
    
}