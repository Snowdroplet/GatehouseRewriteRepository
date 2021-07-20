#include "resource.h"

/// Declaration
ALLEGRO_BITMAP *gfxActorSheet = nullptr;
ALLEGRO_BITMAP *gfxTileSheet = nullptr;

/// Constants



void LoadResources()
{
    gfxActorSheet = al_load_bitmap("gfxActorSheet32.png");
    gfxTileSheet = al_load_bitmap("gfxTileSheet32.png");

}

void UnloadResources()
{
    al_destroy_bitmap(gfxActorSheet);
    al_destroy_bitmap(gfxTileSheet);

}
