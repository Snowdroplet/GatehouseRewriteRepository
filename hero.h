#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <iostream>

#include "actor.h"
#include "inputsystem.h"

enum enumHeroTemplates
{
    HERO_TEMPLATE_GUARDIAN = 0,
    HERO_TEMPLATE_SEEKER = 1,
    HERO_TEMPLATE_ADEPT = 2
};

class Hero: public Actor
{

public:
    Hero();
    ~Hero();

    void InitTemplate(int t);

    bool Input();

};


#endif // HERO_H_INCLUDED
