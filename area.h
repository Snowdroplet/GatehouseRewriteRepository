#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED


#include "gamesystem.h"
#include "resource.h"

class Area
{
    int cellWidth;    // in cells.
    int cellHeight;

    int pxWidth;      // in pixels.
    int pxHeight;

    int viewportCellWidth;
    int viewportCellHeight;

    int viewportPxWidth;
    int viewportPxHeight;

    int xDrawCutoff;  // Number of tiles from viewport center to draw.
    int yDrawCutoff;

public:
    std::vector<int>floor;

    Area(int cw, int ch, int camCw, int camCh);
    ~Area();

    void DrawTiles(int cenXPos, int cenYPos);

    int GetCellWidth();
    int GetCellHeight();

#ifdef AREA_DEBUG
    bool debugSignal = false;
    void Debug();
#endif
};

enum enumFloorType // Try to correspond with generator.h
{
    FLOOR_SKY = 0,
    FLOOR_EMPTY = 1,
    FLOOR_WALL = 2,
    FLOOR_DOOR = 3,
    FLOOR_VARIABLE = 4,
    FLOOR_BARS = 5

};

#endif // AREA_H_INCLUDED
