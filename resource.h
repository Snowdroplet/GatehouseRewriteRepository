#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

/// Game asset constants

const int SS_TILE_SIZE = 32;
const int SS_COL_SIZE = 256;

extern ALLEGRO_BITMAP *gfxActorSheet;
extern ALLEGRO_BITMAP *gfxTileSheet;

void LoadResources();
void UnloadResources();


#endif // RESOURCE_H_INCLUDED
