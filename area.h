#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED


#include "gamesystem.h"
#include "resource.h"

enum enumFloorType // Try to correspond with generator.h
{
    FLOOR_SKY = 0,
    FLOOR_EMPTY = 1,
    FLOOR_WALL = 2,
    FLOOR_DOOR = 3,
    FLOOR_VARIABLE = 4,
    FLOOR_BARS = 5

};

class Area
{
    int width;    // in cells.
    int height;

    int pxWidth;  // in pixels.
    int pxHeight;

    int cameraX; // Top left position of the camera in pixels.
    int cameraY;
    int cameraWidth;   // Number of cells to draw.
    int cameraHeight;



public:
    std::vector<int>floor;

    Area(int w, int h);
    ~Area();

    void DrawTiles();

    void CameraPosition();

    int GetWidth();
    int GetHeight();
};

#endif // AREA_H_INCLUDED
