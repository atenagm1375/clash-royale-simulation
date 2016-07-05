//
// Created by atenagm on 7/3/16.
//

#include <header files/Object.h>

Object::Object(int tp, int trgt, double hs, int hp, int d, double r, double tr, QTimer *timer)
{
    type = tp;
    target = trgt;
    hitSpeed = hs;
    hitPoints = hp;
    damage = d;
    range = r;
    territory = tr;
}

Object::~Object() { }