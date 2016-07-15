//
// Created by atenagm on 6/30/16.
//

#include <header files/RoyalGiant.h>

RoyalGiant::RoyalGiant(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::Building, 1.5, 1200, 78, 6.5, 6.5, spc::Speed::Slow, 6, 1, 1, timer)
{
    this->setPixmap(pic);
}

RoyalGiant::~RoyalGiant() { }

void RoyalGiant::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 10;
    spc::cardNo = 10;
}