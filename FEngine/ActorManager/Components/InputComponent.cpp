//
//  InputComponent.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 27/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "InputComponent.h"

#include <Box2D/Box2D.h>

#include <FastDelegate.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>

#include "../../StateManager/StateManager.h"
#include "../../EventDispatcher/EventDispatcher.h"
#include "../../EventDispatcher/DefaultEvents.h"
#include "../../ActorManager/Actor.h"


#include <iostream>

namespace FEngine
{
    InputComponent::InputComponent()
    {
        EventDispatcherPtr ed = StateManager::Get()->GetEventDispatcher();
        
        EventListenerDelegate touchDownDelegateFn   = fastdelegate::MakeDelegate(this, &InputComponent::TouchDownListener);
        EventListenerDelegate touchMovedDelegateFn  = fastdelegate::MakeDelegate(this, &InputComponent::TouchMovedListener);
        EventListenerDelegate touchUpDelegateFn     = fastdelegate::MakeDelegate(this, &InputComponent::TouchUpListener);
        
        ed->AddListener(EventTouchDown::eventID, touchDownDelegateFn);
        ed->AddListener(EventTouchMoved::eventID, touchMovedDelegateFn);
        ed->AddListener(EventTouchUp::eventID, touchUpDelegateFn);
    }
    
    InputComponent::~InputComponent()
    {
        EventDispatcherPtr ed = StateManager::Get()->GetEventDispatcher();
        
        EventListenerDelegate touchDownDelegateFn   = fastdelegate::MakeDelegate(this, &InputComponent::TouchDownListener);
        EventListenerDelegate touchMovedDelegateFn  = fastdelegate::MakeDelegate(this, &InputComponent::TouchMovedListener);
        EventListenerDelegate touchUpDelegateFn     = fastdelegate::MakeDelegate(this, &InputComponent::TouchUpListener);
        
        ed->RemoveListener(EventTouchDown::eventID, touchDownDelegateFn);
        ed->RemoveListener(EventTouchMoved::eventID, touchMovedDelegateFn);
        ed->RemoveListener(EventTouchUp::eventID, touchUpDelegateFn);

        
    }
    
    void InputComponent::Update (float dt)
    {
    
    }
    
    void InputComponent::TouchDownListener (EventPtr e)
    {
        boost::shared_ptr<FEngine::EventTouchDown> tdE = boost::static_pointer_cast<FEngine::EventTouchDown>(e);
        
    }
    
    void InputComponent::TouchMovedListener (EventPtr e)
    {
        boost::shared_ptr<FEngine::EventTouchMoved> tmE = boost::static_pointer_cast<FEngine::EventTouchMoved>(e);
        
    }
    
    void InputComponent::TouchUpListener (EventPtr e)
    {
    
    }
    
}