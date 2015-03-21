//
//  VertexDefinitions.h
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

namespace FEngine
{
    
    /**
     *      2 Positions     -   float
     */
    struct  Vertex2PF
    {
        float		x, y;
    };
    
    /**
     *      2 Positions     -   float
     *      2 UV coods      -   float
     */
    struct  Vertex2P2UVF
    {
        float		x, y;
        float		u, v;
    };

    
    /**
     *      2 Positions     -   float
     *      2 UV coods      -   float
     *      4 Colors (rgba) -   float
     */
    struct  Vertex2PF2UVF4CF
    {
        float		x, y;
        float		u, v;
        float		r, g, b, a;
    };
    
}