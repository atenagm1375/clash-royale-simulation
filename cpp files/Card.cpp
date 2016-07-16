//
// Created by atenagm on 6/30/16.
//

#include <iostream>
#include "header files/Card.h"

int spc::cardNo;
Card::Card(int tp, int trgt, double hs, int hp, int d, double r, double tr, int spd, int cost, int c, double dt, QTimer *timer)
        : Object(tp, trgt, hs, hp, d, r, tr, timer)
{
    speed = spd;
    elixirCost = cost;
    count = c;
    deployTime = dt;
    spc::cardNo = 0;
    isMoving = false;
    shouldStop = false;
}

Card::~Card() { }

void Card::initialization(QList<Object *> *objs)
{
    objects = objs;

    if(speed == spc::Speed::NONE)
        speedValue = 0;
    else if(speed == spc::Speed::Slow)
        speedValue = 1;
    else if(speed == spc::Speed::Medium)
        speedValue = 4;
    else if(speed == spc::Speed::Fast)
        speedValue = 7;
    else
        speedValue = 10;
}

void Card::move(double x, double y)
{
    if(isMoving){
        moveTimer->stop();
        delete moveTimer;
    }

    x1 = this->pos().x();
    y1 = this->pos().y();
    x2 = x;
    y2 = y;

    if(x1 == x2){
        m = 0;
        dx = 0;
        dy = speedValue * (y2 > y1 ? 0.75 : -0.75);
    }
    else if(y1 == y2){
        m = 0;
        dx = speedValue * (x2 > x1 ? 0.75 : -0.75);
        dy = 0;
    }
    else{
        m = (y2 - y1) / (x2 - x1);
        dx = fabs(speedValue * cos(atan(m))) * (x2 > x1 ? 1 : -1);
        dy = fabs(speedValue * sin(atan(m))) * (y2 > y1 ? 1 : -1);
    }

    moveTimer = new QTimer();
    moveTimer->start(30);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(changePosition()));
}

void Card::changePosition()
{
    if(!shouldStop){
        if((this->pos().x() - x1) * (this->pos().x() - x2) <= 0 &&
                    (this->pos().y() - y1) * (this->pos().y() - y2) <= 0)
            this->moveBy(dx, dy);
        else{
            isMoving = false;
            moveTimer->stop();
            delete moveTimer;
        }
    }
}