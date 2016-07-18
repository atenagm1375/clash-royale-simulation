//
// Created by atenagm on 7/2/16.
//

#include <header files/Tower.h>

Tower::Tower(int tp, int trgt, double hs, int hp, int d, double r, double tr, QPixmap *pic, QTimer *timer) :
            Object(tp, trgt, hs, hp, d, r, tr, timer)
{
    this->setPixmap(*pic);
    isKingTower = false;
}

Tower::~Tower() { }