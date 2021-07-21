#include "hero.h"

Hero::Hero()
{
    isHero = true;
}

Hero::~Hero()
{

}

void Hero::InitTemplate(int t)
{
    SetAnimation(ANIM_IDLE);

    switch(t)
    {
    case HERO_TEMPLATE_GUARDIAN:
        SetSprite(SPRITE_HERO_GUARDIAN);
        break;
    case HERO_TEMPLATE_SEEKER:
        SetSprite(SPRITE_HERO_SEEKER);
        break;
    case HERO_TEMPLATE_ADEPT:
        SetSprite(SPRITE_HERO_ADEPT);
        break;
    default:
        SetSprite(SPRITE_HERO_GUARDIAN);
        break;
    }
}

bool Hero::Input()
{
    if(keyInput[KEY_PAD_8])
    {
        Walk(0,-1);
        return true;
    }
    if(keyInput[KEY_PAD_4])
    {
        Walk(-1,0);
        return true;
    }
    if(keyInput[KEY_PAD_6])
    {
        Walk(1,0);
        return true;
    }
    if(keyInput[KEY_PAD_2])
    {
        Walk(0,1);
        return true;
    }
    if(keyInput[KEY_PAD_7])
    {
        Walk(-1,-1);
        return true;
    }
    if(keyInput[KEY_PAD_9])
    {
        Walk(1,-1);
        return true;
    }
    if(keyInput[KEY_PAD_1])
    {
        Walk(-1,1);
        return true;
    }
    if(keyInput[KEY_PAD_3])
    {
        Walk(1,1);
        return true;
    }


    return false;
}
