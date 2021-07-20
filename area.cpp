#include "area.h"

Area::Area(int w, int h)
{
    width = w;
    height = h;

    pxWidth = width*CELL_WIDTH;
    pxHeight = height*CELL_HEIGHT;

    cameraWidth = 24;
    cameraHeight = 24;

    for(int i = 0; i < height*width; i++)
    {
        floor.push_back(FLOOR_SKY);
    }
}

Area::~Area()
{

}

void Area::DrawTiles()
{
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            al_draw_bitmap_region(gfxTileSheet,

                                  floor[y*width+x]*CELL_WIDTH,
                                  0,

                                  CELL_WIDTH,
                                  CELL_HEIGHT,

                                  x*CELL_WIDTH,
                                  y*CELL_HEIGHT,
                                  0);
        }
    }
}

int Area::GetWidth()
{
    return width;
}

int Area::GetHeight()
{
    return height;
}
