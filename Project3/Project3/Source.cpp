
#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "map.h"
#include "tinyxml/tinyxml.h"
int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(800, 800);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	if (!al_init_image_addon()) {

		return 0;
	}

	map m = map((char *)"tileset/example.tmx");

	
	al_clear_to_color(al_map_rgb(100, 0, 0));

    ALLEGRO_BITMAP *bmp = al_load_bitmap("tileset/tree2-final.png");
    //al_draw_bitmap(bmp, 0, 0, 0);
    m.draw();
    
	al_flip_display();

	al_rest(100.0);

	al_destroy_display(display);

	return 0;
}