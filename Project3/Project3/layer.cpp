//
//  layer.cpp
//  GenericPlatformer
//
//  Created by Sasha Han on 11/24/16.
//
//

#include "layer.hpp"
layer::layer(char * n,int h,int w, std::vector<std::vector<int>>*g)
{
    layername = n;
    height = h;
    width = w;
    gids = g;
    
    
    
}
layer::~layer()
{
    
}
void layer::draw(std::vector<tileset> ts,int x, int y)
{
    
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
        {
     
            int g = gids->at(i).at(j);
            //g = 1;
            
            if (g == 0)
                continue;
            std::vector<tileset>::iterator it;
     
            for (it = ts.begin(); it < ts.end(); it++ )
                if (g < it->firstgid + it->tilecount)
                    break;
            int gidCount = g-it->firstgid;
            
            al_draw_scaled_bitmap(it->image, gidCount%it->columns * it->tilewidth, (gidCount/it->columns)*it->tileheight+1, it->tilewidth, it->tileheight,it->tilewidth*2*(j-x), it->tileheight*2*(i-y) , it->tilewidth*2, it->tileheight*2, 0);
            //al_draw_bitmap_region(it->image, , , 0);
        }
}