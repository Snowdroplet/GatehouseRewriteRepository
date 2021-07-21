#include "actor.h"

Actor::Actor()
{
    isHero = false;

    hasSprite = false;
    hasAnimation = false;
}

Actor::~Actor()
{

}

void Actor::Update()
{
  if(hasAnimation)
  {
      animationUpdateTimer++;
      if(animationUpdateTimer >= animationUpdatePeriod)
      {
          animationFrame++;
          animationUpdateTimer = 0;
      }

      if(animationFrame >= animationFrameMax)
        animationFrame = 0;
  }


  if(!atDest)
  {
      if(xPosition < destXPosition)
        xPosition += 4;
      else if(xPosition > destXPosition)
        xPosition -= 4;

      if(yPosition < destYPosition)
        yPosition += 4;
      else if(yPosition > destYPosition)
        yPosition -= 4;


    if(std::abs(destXPosition - xPosition) <= 2 && std::abs(destYPosition - yPosition) <= 2)
    {
        SnapToCell();
        SetAnimation(ANIM_IDLE);
    }


      // snap to xy if sufficiently close or enough update ticks have passed.
  }

}

void Actor::Drawing()
{
    if(hasSprite)
    {
        if(isHero)
            al_draw_bitmap_region(gfxActorSheet,

                          (animationIndex+animationFrame) * TILE_WIDTH,
                          spriteIndex * TILE_HEIGHT,

                          TILE_WIDTH,
                          TILE_HEIGHT,

                          VIEWPORT_CELL_WIDTH/2 * TILE_WIDTH,
                          VIEWPORT_CELL_HEIGHT/2 * TILE_HEIGHT,
                          0);

        else
            al_draw_bitmap_region(gfxActorSheet,

                          (animationIndex+animationFrame) * TILE_WIDTH,
                          spriteIndex * TILE_HEIGHT,

                          TILE_WIDTH,
                          TILE_HEIGHT,

                          xPosition,
                          yPosition,
                          0);
    }
}

void Actor::SnapToCell()
{
    destXPosition = xPosition = xCell*TILE_WIDTH;
    destYPosition = yPosition = yCell*TILE_HEIGHT;

    atDest = true;
}

void Actor::SetXYCell(int x, int y)
{
    xCell = x;
    yCell = y;

    SnapToCell();
}

void Actor::Move(int x, int y)
{
    xCell+= x;
    yCell+= y;

    destXPosition = xCell*TILE_WIDTH;
    destYPosition = yCell*TILE_HEIGHT;

    atDest = false;

}

void Actor::Walk(int x, int y)
{
    Move(x,y);
    SetAnimation(ANIM_WALK);
}

void Actor::SetSprite(int s)
{
    spriteIndex = s;
    if(spriteIndex != ANIM_NONE)
    {
        hasSprite = true;
    }
    else // if animationIndex == ANIM_NONE
    {
        hasSprite = false;
    }
}

void Actor::SetAnimation(int a)
{
    animationIndex = a;
    animationFrame = 0;
    animationUpdateTimer = 0;

    if(animationIndex != ANIM_NONE)
    {
        hasAnimation = true;
    }
    else // if animationIndex == ANIM_NONE
    {
        hasAnimation = false;
    }

    if(animationIndex == ANIM_IDLE)
    {
        animationFrameMax = 2;
        animationUpdatePeriod = 40;
    }
    else if(animationIndex == ANIM_WALK)
    {
        animationFrameMax = 3;
        animationUpdatePeriod = 5;
    }

}

float Actor::GetXPosition()
{
    return xPosition;
}

float Actor::GetYPosition()
{
    return yPosition;
}

float Actor::GetXCell()
{
    return xCell;
}

float Actor::GetYCell()
{
    return yCell;
}

bool Actor::IsHero()
{
    return isHero;
}

#ifdef ACTOR_DEBUG
void Actor::Debug()
{
    std::cout << "-- Hero --" << std::endl;
    std::cout << "x Cell: " << xCell << " || y Cell: " << yCell << std::endl;
    std::cout << "x Pos: " << xPosition << " || y Pos: " << yPosition << std::endl;
}
#endif
