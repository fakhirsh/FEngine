//
//  ActorFactory.h
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "../../PointerDefs.h"

#include <string>

namespace FEngine
{
    class ActorFactory
    {
    public:
        ActorFactory();
        ~ActorFactory();
        
        ActorPtr CreateActor(std::string xmlFilePath);
        
    };
}