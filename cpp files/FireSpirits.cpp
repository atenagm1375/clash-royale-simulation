//
// Created by atenagm on 7/4/16.
//

#include <header files/FireSpirits.h>

FireSpirits::FireSpirits(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::AirGround, 0, 52, 96, 2, 2, spc::Speed::NONE, 0, 3, 1, timer)
{
    this->setPixmap(pic);
}

FireSpirits::~FireSpirits() { }