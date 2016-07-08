//
// Created by atenagm on 6/30/16.
//

#include "header files/MinionHorde.h"

MinionHorde::MinionHorde(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::AirGround, 1, 119, 53, 2.5, 3, spc::Speed::Fast, 5, 6, 1, timer)
{
    this->setPixmap(pic);
}

MinionHorde::~MinionHorde() { }