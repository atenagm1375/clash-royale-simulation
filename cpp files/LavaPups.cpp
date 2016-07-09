//
// Created by atenagm on 7/5/16.
//

#include <header files/LavaPups.h>

LavaPups::LavaPups(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::All, 0, 198, 49, 1, 1, spc::Speed::Medium, 0, 6, 0, timer)
{
    this->setPixmap(pic);
}

LavaPups::~LavaPups() { }