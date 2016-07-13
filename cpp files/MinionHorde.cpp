//
// Created by atenagm on 6/30/16.
//

#include "header files/MinionHorde.h"

MinionHorde::MinionHorde(QPixmap pic, QTimer *timer)
        : Card(spc::Type::AIRTROOP, spc::Target::AirGround, 1, 90, 40, 2.5, 3, spc::Speed::Fast, 5, 6, 1, timer)
{
    this->setPixmap(pic);
}

MinionHorde::~MinionHorde() { }

void MinionHorde::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 6;
}