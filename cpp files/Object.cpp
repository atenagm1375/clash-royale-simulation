//
// Created by atenagm on 7/3/16.
//

#include <header files/Object.h>

Object::Object() { }

Object::Object(int tp, int trgt, double hs, int hp, int d, double r, double tr, QTimer *timer)
{
    type = tp;
    target = trgt;
    hitSpeed = hs;
    hitPoints = hp;
    damage = d;
    range = r * 40;
    territory = tr * 40;
    isMyTeam = true;
    isAlive = true;
}

Object::~Object() { }