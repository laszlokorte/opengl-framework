//
//  mesh.cpp
//  OpenGLFramework
//
//  Created by Laszlo Korte on 07.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#include "./mesh.h"

namespace lkogl {
    namespace geometry {
        
        Mesh::Mesh(const std::vector<Vertex> verts, const std::vector<Triangle> tris) :
           vertices(verts), triangles(tris)
        {}
        
        namespace primitives {
            const float oneThird = 1.0/3.0;
            const float twoThird = 2.0/3.0;
            
            Mesh makeCube() {
                std::vector<Vertex> vertices = {
                    // Front
                    {{ 1,-1, 1}, {0,0,1}, {0,1,0, 1}, {0.0,twoThird}},
                    {{ 1, 1, 1}, {0,0,1}, {0,1,0, 1}, {0.0,oneThird}},
                    {{-1, 1, 1}, {0,0,1}, {0,1,0, 1}, {0.25,oneThird}},
                    {{-1,-1, 1}, {0,0,1}, {0,1,0, 1}, {0.25,twoThird}},
                    
                    // Back
                    {{-1,-1, -1}, {0,0,-1}, {0,1,0, 1}, {0.5,twoThird}},
                    {{-1, 1, -1}, {0,0,-1}, {0,1,0, 1}, {0.5,oneThird}},
                    {{ 1, 1, -1}, {0,0,-1}, {0,1,0, 1}, {0.75,oneThird}},
                    {{ 1,-1, -1}, {0,0,-1}, {0,1,0, 1}, {0.75,twoThird}},
                    
                    // Left
                    {{-1,-1, 1}, {-1,0,0}, {0,1,0, 1}, {0.25,twoThird}},
                    {{-1, 1, 1}, {-1,0,0}, {0,1,0, 1}, {0.25,oneThird}},
                    {{-1, 1, -1}, {-1,0,0}, {0,1,0, 1}, {0.5,oneThird}},
                    {{-1,-1, -1}, {-1,0,0}, {0,1,0, 1}, {0.5,twoThird}},
                    
                    // Right
                    {{ 1,-1, -1}, {1,0,0}, {0,1,0, 1}, {0.75,twoThird}},
                    {{ 1, 1, -1}, {1,0,0}, {0,1,0, 1}, {0.75,oneThird}},
                    {{ 1, 1, 1}, {1,0,0}, {0,1,0, 1}, {1,oneThird}},
                    {{ 1,-1, 1}, {1,0,0}, {0,1,0, 1}, {1,twoThird}},
                    
                    // Top
                    {{ 1, 1, -1}, {0,1,0}, {1,0,0, 1}, {0.5,0}},
                    {{-1, 1, -1}, {0,1,0}, {1,0,0, 1}, {0.5,oneThird}},
                    {{-1, 1, 1}, {0,1,0}, {1,0,0, 1}, {0.25,oneThird}},
                    {{ 1, 1, 1}, {0,1,0}, {1,0,0, 1}, {0.25,0}},
                    
                    // Bottom
                    {{-1,-1,  1}, {0,-1,0}, {1,0,0, 1}, {0.25,twoThird}},
                    {{-1,-1, -1}, {0,-1,0}, {1,0,0, 1}, {0.5,twoThird}},
                    {{ 1,-1, -1}, {0,-1,0}, {1,0,0, 1}, {0.5,1}},
                    {{ 1,-1,  1}, {0,-1,0}, {1,0,0, 1}, {0.25,1}},
                };
                
                std::vector<Triangle> triangles = {
                    // Front
                    {0, 1, 2},
                    {2, 3, 0},
                    // Back
                    {4, 5, 6},
                    {6, 7, 4},
                    // Left
                    {8, 9, 10},
                    {10, 11, 8},
                    // Right
                    {12, 13, 14},
                    {14, 15, 12},
                    // Top
                    {16, 17, 18},
                    {18, 19, 16},
                    // Bottom
                    {20, 21, 22},
                    {22, 23, 20},
                };
                
                return Mesh(vertices, triangles);
            }

            Mesh makeSquare() {
                std::vector<Vertex> vertices = {
                    // Front
                    {{ 1,-1, 0}, {0,0,1}, {1,0,0, 1}, {1,1}},
                    {{ 1, 1, 0}, {0,0,1}, {1,0,0, 1}, {1,0}},
                    {{-1, 1, 0}, {0,0,1}, {1,0,0, 1}, {0,0}},
                    {{-1,-1, 0}, {0,0,1}, {1,0,0, 1}, {0,1}},
                   
                };
                
                std::vector<Triangle> triangles = {
                    // Front
                    {0, 1, 2},
                    {2, 3, 0}
                };
                
                return Mesh(vertices, triangles);
            }

            
            Mesh makePyramid() {
                std::vector<Vertex> vertices = {
                    // Base
                    {{ 1,-1, 1}, {0,-1,0}, {1,0,0, -1}, {0.66,0.66}},
                    {{-1,-1, 1}, {0,-1,0}, {1,0,0, 1}, {0.33,0.66}},
                    {{-1,-1, -1}, {0,-1,0}, {1,0,0, 1}, {0.33,0.33}},
                    {{ 1,-1, -1}, {0,-1,0}, {1,0,0, -1}, {0.66,0.33}},
                    
                    // Tip
                    {{ 1,-1, 1}, {0,1,1}, {1,0,0, 1}, {0.33,0.33}},
                    {{-1,-1, 1}, {0,1,1}, {1,0,0, -1}, {0.66,0.33}},
                    {{0, 1, 0}, {0,1,1}, {1,0,0, 1}, {0.5,0}},
                    
                    {{-1,-1, 1}, {-1,1,0}, {0,0,1, -1}, {0.66,0.33}},
                    {{-1,-1, -1}, {-1,1,0}, {0,0,1, -1}, {0.66,0.66}},
                    {{0, 1, 0}, {-1,1,0}, {0,0,1, 1}, {1,0.5}},
                    
                    {{-1,-1, -1}, {0,1,-1}, {1,0,0, 1}, {0.33,0.66}},
                    {{ 1,-1, -1}, {0,1,-1}, {1,0,0, -1}, {0.66,0.66}},
                    {{0, 1, 0}, {0,1,-1}, {1,0,0, 1}, {0.5,1}},
                    
                    {{ 1,-1, 1}, {1,1,0}, {0,0,1, 1}, {0.33,0.66}},
                    {{ 1,-1, -1}, {1,1,0}, {0,0,1, 1}, {0.33,0.33}},
                    {{0, 1, 0}, {1,1,0}, {0,0,1, 1}, {0,0.5}},
                };
                
                std::vector<Triangle> triangles = {
                    // Floor
                    {0, 1, 2},
                    {2, 3, 0},
                    
                    //Sides
                    {5, 4, 6},
                    {8, 7, 9},
                    {11, 10, 12},
                    {13, 14, 15},
                };
                
                return Mesh(vertices, triangles);
            }

        }
    }
}
