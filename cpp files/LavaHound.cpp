//
// Created by atenagm on 6/30/16.
//

#include "header files/LavaHound.h"

LavaHound::LavaHound(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::Building, 1.3, 3300, 54, 2, 3, spc::Speed::Slow, 7, 1, 1, timer)
{
    this->setPixmap(pic);
    lavaPups = new LavaPups(QPixmap("sources/firePups.png"), timer);
}

LavaHound::~LavaHound() { }

void LavaHound::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 1;
}