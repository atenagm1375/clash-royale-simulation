//
// Created by atenagm on 6/30/16.
//

#include <header files/HogRider.h>

HogRider::HogRider(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::Building, 1.5, 800, 150, 2, 6.5, spc::Speed::VeryFast, 4, 1, 1, timer)
{
    this->setPixmap(pic);
    id = 5;
}

HogRider::~HogRider() { }

void HogRider::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 5;
    spc::cardNo = 5;
}