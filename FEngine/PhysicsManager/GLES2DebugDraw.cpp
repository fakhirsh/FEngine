//
//  GLES2DebugDraw.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 01/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "GLES2DebugDraw.h"

#include "../Common.h"

#include "../ResourceCache/Factories/ProgramFactory.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>

#include <iostream>

namespace FEngine
{
    GLES2DebugDraw::GLES2DebugDraw()
    {
        ProgramFactory pf;
        _program = pf.CreateProgram("SimpleVertex2D");
    }
    
    GLES2DebugDraw::~GLES2DebugDraw()
    {
    
    }
    
    void GLES2DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
    {
        /*
        glColor4f(color.r, color.g, color.b,1);
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
         */
        
        std::cout << "GLES2DebugDraw::DrawPolygon()" << std::endl;
        
    }
    
    void GLES2DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
    {
        /*
        glVertexPointer(2, GL_FLOAT, 0, vertices);
        
        glColor4f(color.r, color.g, color.b,0.5f);
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
        
        glColor4f(color.r, color.g, color.b,1);
        glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
         */
    }
    
    void GLES2DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
    {
        /*
        const float32 k_segments = 16.0f;
        int vertexCount=16;
        const float32 k_increment = 2.0f * b2_pi / k_segments;
        float32 theta = 0.0f;
        
        GLfloat				glVertices[vertexCount*2];
        for (int32 i = 0; i < k_segments; ++i)
        {
            b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
            glVertices[i*2]=v.x;
            glVertices[i*2+1]=v.y;
            theta += k_increment;
        }
        
        glColor4f(color.r, color.g, color.b,1);
        glVertexPointer(2, GL_FLOAT, 0, glVertices);
        
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
         */
    }
    
    void GLES2DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
    {
        /*
        const float32 k_segments = 16.0f;
        int vertexCount=16;
        const float32 k_increment = 2.0f * b2_pi / k_segments;
        float32 theta = 0.0f;
        
        GLfloat				glVertices[vertexCount*2];
        for (int32 i = 0; i < k_segments; ++i)
        {
            b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
            glVertices[i*2]=v.x;
            glVertices[i*2+1]=v.y;
            theta += k_increment;
        }
        
        glColor4f(color.r, color.g, color.b,0.5f);
        glVertexPointer(2, GL_FLOAT, 0, glVertices);
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
        glColor4f(color.r, color.g, color.b,1);
        glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
        
        // Draw the axis line
        DrawSegment(center,center+radius*axis,color);
         */
    }
    
    void GLES2DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
    {
        /*
        glColor4f(color.r, color.g, color.b,1);
        GLfloat				glVertices[] = {
            p1.x,p1.y,p2.x,p2.y
        };
        glVertexPointer(2, GL_FLOAT, 0, glVertices);
        glDrawArrays(GL_LINES, 0, 2);
         */
    }
    
    void GLES2DebugDraw::DrawTransform(const b2Transform& xf)
    {
        /*
        b2Vec2 p1 = xf.position, p2;
        const float32 k_axisScale = 0.4f;
        
        p2 = p1 + k_axisScale * xf.R.col1;
        DrawSegment(p1,p2,b2Color(1,0,0));
        
        p2 = p1 + k_axisScale * xf.R.col2;
        DrawSegment(p1,p2,b2Color(0,1,0));
         */
    }
    
    void GLES2DebugDraw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
    {
        /*
        glColor4f(color.r, color.g, color.b,1);
        glPointSize(size);
        GLfloat				glVertices[] = {
            p.x,p.y
        };
        glVertexPointer(2, GL_FLOAT, 0, glVertices);
        glDrawArrays(GL_POINTS, 0, 1);
        glPointSize(1.0f);
         */
    }
    
    void GLES2DebugDraw::DrawString(int x, int y, const char *string, ...)
    {
        
        /* Unsupported as yet. Could replace with bitmap font renderer at a later date */
    }
    
    void GLES2DebugDraw::DrawAABB(b2AABB* aabb, const b2Color& c)
    {
        /*
        glColor4f(c.r, c.g, c.b,1);
        
        GLfloat				glVertices[] = {
            aabb->lowerBound.x, aabb->lowerBound.y,
            aabb->upperBound.x, aabb->lowerBound.y,
            aabb->upperBound.x, aabb->upperBound.y,
            aabb->lowerBound.x, aabb->upperBound.y
        };
        glVertexPointer(2, GL_FLOAT, 0, glVertices);
        glDrawArrays(GL_LINE_LOOP, 0, 8);
        */
    }
}