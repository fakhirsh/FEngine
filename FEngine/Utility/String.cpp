//
//  String.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 14/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "String.h"

namespace FEngine
{
    namespace String
    {
        
        void PrependZeros(std::string & str, int totalDigits)
        {
            int zerosToPrepend = totalDigits - str.length();
            
            for(int i = 0; i < zerosToPrepend; i++)
            {
                str = std::string("0") + str;
            }
        }
        
    }
}