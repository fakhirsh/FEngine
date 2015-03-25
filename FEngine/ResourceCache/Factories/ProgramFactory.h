//
//  ProgramFactory.h
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../../PointerDefs.h"

#include <string>

namespace FEngine
{
    class ProgramFactory
    {
    public:
        ProgramFactory();
        ~ProgramFactory();
        
        ProgramPtr CreateProgram(const std::string & name);
        
    };
}