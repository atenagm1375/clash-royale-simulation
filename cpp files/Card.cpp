//
// Created by atenagm on 6/30/16.
//

#include <iostream>
#include "header files/Card.h"

Card::Card(int tp, int trgt, double hs, int hp, int d, double r, double tr, int spd, int cost, int c, double dt, QTimer *timer)
        : Object(tp, trgt, hs, hp, d, r, tr, timer)
{
    speed = spd;
    elixirCost = cost;
    count = c;
    deployTime = dt;
    isSelected = false;

    acceptedMouseButtons();
}

Card::~Card() { }

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->isSelected = true;
    this->pixmap().scaled(90, 90);
}