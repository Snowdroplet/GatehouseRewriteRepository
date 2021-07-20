/**
To do:

**/

/**
Errors:

**/

/**
Controls:

**/


#define __USE_MINGW_ANSI_STDIO 0
#define BOOST_MPL_IGNORE_PARENTHESES_WARNING 0

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <set>

//#include <boost/filesystem.hpp>

#include "gamesystem.h"
#include "inputsystem.h"
#include "resource.h"
#include "allegrocustom.h"

#include "area.h"
#include "generator.h"
#include "actor.h"
#include "hero.h"


/// Main loop functions ##############################
void GameLogic();
void LoadingLogic();
void TitleLogic();

void GameDrawing();
void LoadingDrawing();
void TitleDrawing();

/// Objects and containers ###########################
Area area(48,48);

std::vector<Actor*>actors;
Hero*hero;

/// MAIN() ############################################

int main(int argc, char *argv[])
{
    srand(time(nullptr));

    //Replace fprintf with native dialogue later
    if(!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return false;
    }
    if(!al_install_keyboard())
    {
        fprintf(stderr, "failed to install keyboard!\n");
        return false;
    }
    if(!al_install_mouse())
    {
        fprintf(stderr, "failed to install mouse!\n");
        return false;
    }
    if(!al_init_image_addon())
        return false;
    if(!al_init_primitives_addon())
        return false;

    al_init_font_addon();

    if(!al_init_ttf_addon())
        return false;

    if(!PHYSFS_init(argv[0]))
        return false;

    if(!PHYSFS_mount("./gamedata.zip", "/", 1))
    {
        fprintf(stderr, "gamedata not found!\n");
        return false;
    }

    al_set_physfs_file_interface();

    AllegroCustomColours();

    FPStimer = al_create_timer(1.0/FPS);
    if(!FPStimer)
    {
        fprintf(stderr, "failed to create fpstimer!\n");
        return false;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(FPStimer);
        return false;
    }

    eventQueue = al_create_event_queue();
    if(!eventQueue)
    {
        fprintf(stderr, "failed to create event queue!\n");
        al_destroy_display(display);
        al_destroy_timer(FPStimer);
        return false;
    }

    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(FPStimer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_mouse_event_source());

    al_start_timer(FPStimer);

    LoadResources();

    hero = new Hero();
    hero->InitTemplate(HERO_TEMPLATE_GUARDIAN);
    hero->SetXYCell(12,12);

    actors.push_back(hero);

    Generator generator;
    generator.GenerateFloor(area.GetWidth(), area.GetHeight(), area.floor);

    while(!gameExit)
    {
        al_wait_for_event(eventQueue, &ev);

        Input();

        if(ev.type == ALLEGRO_EVENT_TIMER || gameExit == true)
        {
            if(mainPhase == MAIN_PHASE_GAME)
            {
                GameLogic();
                GameDrawing();
            }
            else if(mainPhase == MAIN_PHASE_LOADING)
            {
                LoadingLogic();
                LoadingDrawing();
            }
            else if(mainPhase == MAIN_PHASE_TITLE)
            {
                TitleLogic();
                TitleDrawing();
            }

            redraw = true;
        }
    }

    delete hero;

    UnloadResources();
    PHYSFS_deinit();

    al_destroy_timer(FPStimer);
    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);

    al_uninstall_mouse();
    al_uninstall_keyboard();

    return 0;
}

void GameLogic()
{
    static bool awaitingHeroAction = true;

    static int keyInputCD = 0;
    const int keyInputDelay = 10;

    if(keyInputCD > 0)
        keyInputCD --;

    if(awaitingHeroAction && keyInputCD == 0)
    {
        if(hero->Input())
        {
                //awaitingHeroAction = false;
                keyInputCD = keyInputDelay;
        }

    }

    for(std::vector<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it)
    {
        (*it)->Update();
    }
}

void LoadingLogic()
{

}

void TitleLogic()
{

}

void GameDrawing()
{
    if(redraw && al_is_event_queue_empty(eventQueue))
    {
        redraw = false;
        al_clear_to_color(al_map_rgb(0,0,0));


        area.DrawTiles();


        for(std::vector<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it)
        {
            (*it)->Drawing();
        }



        al_flip_display();
    }
}

void LoadingDrawing()
{

}

void TitleDrawing()
{

}

