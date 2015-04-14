//
//  String.h
//  FEngine
//
//  Created by Fakhir Shaheen on 14/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <string>
#include <sstream>

namespace FEngine
{
    namespace String
    {
        
        template < class T >
        std::string ToString(const T & number)
        {
            std::ostringstream stm ;
            stm << number ;
            return stm.str() ;
        }

    }
}