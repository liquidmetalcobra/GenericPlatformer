//
//  layer.hpp
//  GenericPlatformer
//
//  Created by Sasha Han on 11/24/16.
//
//
#pragma once
#include <vector>
#include <iostream>
#include "tileset.hpp"
#include <stdio.h>


class layer
{
public:
    layer(char * n,int h,int w, std::vector<std::vector<int>> *g);
    ~layer();
    
    
    void draw(std::vector<tileset> ts);
    
private:
    
    int height;
    int width;
    std::vector<std::vector<int>> *gids;
    char * layername;
};