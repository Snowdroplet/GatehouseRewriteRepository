#include "area.h"

Area::Area(int cw, int ch, int camCw, int camCh)
{
    cellWidth = cw;
    cellHeight = ch;

    pxWidth = cellWidth*TILE_WIDTH;
    pxHeight = cellHeight*TILE_HEIGHT;

    for(int i = 0; i < cellHeight*cellWidth; i++)
    {
        floor.push_back(FLOOR_SKY);
    }

    viewportCellWidth = camCw;
    viewportCellHeight = camCh;

    viewportPxWidth = viewportCellWidth*TILE_WIDTH;
    viewportPxHeight = viewportCellHeight*TILE_HEIGHT;

    xDrawCutoff = viewportCellWidth/2;
    yDrawCutoff = viewportCellHeight/2;

}

Area::~Area()
{

}

void Area::DrawTiles(int cenXPos, int cenYPos)
{
    int cenXCell = cenXPos/TILE_WIDTH;
    int cenYCell = cenYPos/TILE_HEIGHT;

    int startXCell = cenXCell-xDrawCutoff;
    if(startXCell < 0)
        startXCell = 0;

    int startYCell = cenYCell-yDrawCutoff;
    if(startYCell < 0)
        startYCell = 0;

    int endXCell = cenXCell+xDrawCutoff;
    if(endXCell > cellWidth)
        endXCell = cellWidth;

    int endYCell = cenYCell+yDrawCutoff;
    if(endYCell > cellHeight)
        endYCell = cellHeight;

    for(int y = startYCell; y < endYCell; y++)
    {
        for(int x = startXCell; x < endXCell; x++)
        {

            int drawTile = floor[y*cellWidth+x];
            if(drawTile != FLOOR_SKY)
                al_draw_bitmap_region(gfxTileSheet,

                                  drawTile*TILE_WIDTH,
                                  0,

                                  TILE_WIDTH,
                                  TILE_HEIGHT,

                                  x*TILE_WIDTH + viewportPxWidth/2  - cenXPos,
                                  y*TILE_HEIGHT + viewportPxHeight/2 - cenYPos,
                                  0);
        }
    }

#ifdef AREA_DEBUG
    if(debugSignal)
    {
        debugSignal = false;

            std::cout << "-- area tile drawing --" << std::endl;
            std::cout << "cenXPos: " << cenXPos << " || cenYPos: " << cenYPos << std::endl;
            std::cout << "cenXCell: " << cenXCell << " || cenYCell: " << cenYCell << std::endl;
            std::cout << "startXCell: " << startXCell << " || startYCell: " << startYCell << std::endl;
            std::cout << "endXCell: " << endXCell << " || endYCell " << endYCell << std::endl;
    }
#endif // AREA_DEBUG

}

int Area::GetCellWidth()
{
    return cellWidth;
}

int Area::GetCellHeight()
{
    return cellHeight;
}

#ifdef AREA_DEBUG
void Area::Debug()
{
    debugSignal = true;

}
#endif // AREA_DEBUG
