//
// Created by atenagm on 6/30/16.
//

#include <header files/RoyalGiant.h>

RoyalGiant::RoyalGiant(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::Building, 1.5, 1596, 103, 6.5, 6.5, spc::Speed::Slow, 6, 1, 1, timer)
{
    this->setPixmap(pic);
}

RoyalGiant::~RoyalGiant() { }

void RoyalGiant::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 10;
}