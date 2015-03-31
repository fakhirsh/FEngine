//
//  InputComponent.h
//  FEngine
//
//  Created by Fakhir Shaheen on 27/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../ActorComponent.h"

namespace FEngine
{
    class InputComponent : public ActorComponent
    {
    public:
        InputComponent();
        virtual ~InputComponent();
        
        virtual void    Update              (float dt);
        
        void            TouchDownListener   (EventPtr e);
        void            TouchMovedListener  (EventPtr e);
        void            TouchUpListener     (EventPtr e);
        
    private:
        
    };
}