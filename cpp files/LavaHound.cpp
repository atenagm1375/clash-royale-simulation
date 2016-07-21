//
// Created by atenagm on 6/30/16.
//

#include "header files/LavaHound.h"

LavaHound::LavaHound(QPixmap pic, QTimer *timer)
        : Card(spc::Type::AIRTROOP, spc::Target::Building, 1.3, 3000, 45, 2, 6.5, spc::Speed::Slow, 7, 1, 1, timer)
{
    this->setPixmap(pic);
    lavaPups = new LavaPups(QPixmap("sources/firePups.png"), timer);
    id = 1;
}

LavaHound::~LavaHound() { }

void LavaHound::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 1;
    spc::cardNo = 1;
}