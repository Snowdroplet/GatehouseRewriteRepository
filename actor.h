#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include "gamesystem.h"
#include "resource.h"

class Actor
{
protected:

    int xCell, yCell;
    float xPosition, yPosition;
    float destXPosition, destYPosition; // Where to move to?
    bool atDest;                        // Current xy matches destination xy.

    bool hasSprite;
    int spriteIndex;

    bool hasAnimation;
    int animationIndex;
    int animationFrame;
    int animationFrameMax;
    int animationUpdateTimer;
    int animationUpdatePeriod;


public:
    Actor();
    ~Actor();

    void Update();                  // Update state.
    void Drawing();                 // Drawing.

    void SnapToCell();              // Instantly align xy position (in pixels) to corresponding position (in cells).
    void SetXYCell(int x, int y);   // Instantly change position (xy and cell).
    void Move(int x, int y);        // Translate without animation, unrestrained by terrain rules.
    void Walk(int x, int y);        // Translate with animation, restrained by terrain rules.

    void SetSprite(int s);
    void SetAnimation(int a);


};

enum enumAnimationIndexes
{
    ANIM_NONE = -1,
    ANIM_IDLE = 0,
    ANIM_WALK = 2
};

enum enumSpriteIndexes
{
    SPRITE_NONE = -1,
    SPRITE_HERO_GUARDIAN = 0,
    SPRITE_HERO_SEEKER = 1,
    SPRITE_HERO_ADEPT = 2
};

#endif // ACTOR_H_INCLUDED
