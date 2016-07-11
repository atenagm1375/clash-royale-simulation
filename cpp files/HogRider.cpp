//
// Created by atenagm on 6/30/16.
//

#include <header files/HogRider.h>

HogRider::HogRider(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::Building, 1.5, 1064, 199, 1, 2, spc::Speed::VeryFast, 4, 1, 1, timer)
{
    this->setPixmap(pic);
}

HogRider::~HogRider() { }

void HogRider::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 5;
}