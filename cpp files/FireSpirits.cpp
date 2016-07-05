//
// Created by atenagm on 7/4/16.
//

#include <header files/FireSpirits.h>

FireSpirits::FireSpirits(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::AirGround, 0, 43, 80, 2, 2, spc::Speed::NONE, 2, 3, 1, timer)
{
    this->setPixmap(pic);
}

FireSpirits::~FireSpirits() { }