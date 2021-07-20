#include "gamesystem.h"

bool gameExit = false;
int mainPhase = MAIN_PHASE_GAME;

bool redraw = false;

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *eventQueue;
ALLEGRO_TIMER *FPStimer;
ALLEGRO_EVENT ev;
ALLEGRO_MOUSE_STATE mouseState;

