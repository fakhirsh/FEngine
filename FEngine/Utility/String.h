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
        
        void PrependZeros(std::string & str, int totalDigits);
        
        
        // Why didn't I just declate the following function here and define it in another CPP file?
        //    Because I don't know how to do it, it has comples function signature... :D
        
        template < class T >
        std::string ToString(const T & number)
        {
            std::ostringstream stm ;
            stm << number ;
            return stm.str() ;
        }
        
    }
}