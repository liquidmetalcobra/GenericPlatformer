
#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "map.h"
#include "tinyxml/tinyxml.h"
#include "Camera.hpp"
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    bool redraw = true;
    bool doexit = false;
    bool key[4] = { false, false, false, false };
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    

	if (!al_init_image_addon()) {

		return 0;
	}

	map m = map((char *)"tileset/example.tmx");
    Camera c = Camera();
	
	al_clear_to_color(al_map_rgb(100, 0, 0));
    
    timer = al_create_timer(1.0 / FPS);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    //al_draw_bitmap(bmp, 0, 0, 0);
     al_start_timer(timer);
    while(!doexit)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        
        if(ev.type == ALLEGRO_EVENT_TIMER) {
            
            if(key[KEY_UP] && c.y > 0) {
                
                c.y--;
            }
            
            if(key[KEY_DOWN] && c.y < m.height - SCREEN_H/(2*m.tileHeight)) {
                c.y++;
            }
            
            if(key[KEY_LEFT] && c.x > 0 ) {
                c.x--;
            }
            
            if(key[KEY_RIGHT] && c.x < m.width-SCREEN_W/(2*m.tileHeight)) {
                c.x++;
            }
          
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = true;
                    break;
                    
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = true;
                    break;
                    
                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = true;
                    break;
                    
                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = true;
                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            printf("HI");
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = false;
                    break;
                    
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = false;
                    break;
                    
                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = false;
                    break;
                    
                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = false;
                    break;
                    
                case ALLEGRO_KEY_ESCAPE:
                    doexit = true;
                    break;
            }
        }
        
        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            
            al_clear_to_color(al_map_rgb(0,0,0));
            m.draw(c.x,c.y);
            
            //al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
            
            al_flip_display();
        }
    }
    
    
    


	al_destroy_display(display);

	return 0;
}