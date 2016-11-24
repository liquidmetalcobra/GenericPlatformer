//
//  tileset.cpp
//  GenericPlatformer
//
//  Created by Sasha Han on 11/24/16.
//
//

#include "tileset.hpp"

tileset::tileset(char * newname, int gid, int tw, int th, int tc,int c, char * imageName, int iw, int ih)
{
    name = newname;
    firstgid = gid;
    tilewidth = tw;
    tileheight = th;
    columns = c;
    std::string finalName = "tileset/";
    finalName+=imageName;
    image = al_load_bitmap(finalName.c_str());
    imagewidth = iw;
    imageheight = ih;
    tilecount = tc;
    
    
    
}
tileset::~tileset()
{
    
}
void tileset::draw()
{
    al_draw_bitmap(image, 0, 0, 0);
}