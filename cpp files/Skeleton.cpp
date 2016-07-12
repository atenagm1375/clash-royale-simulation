//
// Created by atenagm on 7/5/16.
//

#include <header files/Skeleton.h>

Skeleton::Skeleton(QPixmap pic, QTimer *timer) :
        Card(spc::Type::TROOP, spc::Target::Ground, 1, 51, 51, 1, 2, spc::Speed::Fast, 0, 3, 1, timer)
{
    this->setPixmap(pic);
}

Skeleton::~Skeleton() { }