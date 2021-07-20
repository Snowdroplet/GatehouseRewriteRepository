#ifndef GAMESYSTEM_H_INCLUDED
#define GAMESYSTEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_physfs.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <physfs.h>


const float PI = 3.141592;

const float FPS = 60;
const int SCREEN_W = 1024;
const int SCREEN_H = 768;

const int CELL_WIDTH = 32;
const int CELL_HEIGHT = 32;

enum enumMainPhases
{
    MAIN_PHASE_TITLE = 0,
    MAIN_PHASE_LOADING = 1,
    MAIN_PHASE_GAME = 2
};

extern bool gameExit;
extern int mainPhase;

extern bool redraw;

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *eventQueue;
extern ALLEGRO_TIMER *FPStimer;
extern ALLEGRO_EVENT ev;
extern ALLEGRO_MOUSE_STATE mouseState;


#endif // GAMESYSTEM_H_INCLUDED
