//
// Created by atenagm on 6/30/16.
//

#include <header files/Witch.h>

Witch::Witch(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::AirGround, 0.7, 665, 55, 5.5, 5.5, spc::Speed::Medium, 5, 1, 1, timer)
{
    this->setPixmap(pic);
    skeleton = new Skeleton(QPixmap("sources/Skeletons.png"), timer);
}

Witch::~Witch() { }