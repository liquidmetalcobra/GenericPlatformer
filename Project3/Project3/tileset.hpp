//
//  tileset.hpp
//  GenericPlatformer
//
//  Created by Sasha Han on 11/24/16.
//
//
#pragma once
#ifndef tileset_hpp
#define tileset_hpp

#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#endif /* tileset_hpp */
class tileset
{
public:
    tileset(char * newname, int gid, int tw, int th,int tc, int c, char * imageName, int iw, int ih);
    ~tileset();
    
    void draw();
    int firstgid;
    
    char * name;
    int tilewidth;
    int tileheight;
    int tilecount;
    int columns;
    ALLEGRO_BITMAP *image;
    int imagewidth;
    int imageheight;

private:
    
    
};