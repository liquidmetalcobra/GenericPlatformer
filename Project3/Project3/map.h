#pragma once
#include <iostream>
#include "tinyxml/tinyxml.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <vector>
#include "tileset.hpp"
#include "layer.hpp"
class map
{
public:
	map(char * mapName);
	~map();

    void draw();


private:
	void parseMap(char * mapName);
    
	char * orientation;
	char * renderorder;
	int width;
	int height;
	int tileWidth;
	int tileHeight;
	int nextObjectID;
    std::vector<tileset> tilesets;
    std::vector<layer> layers;
};

