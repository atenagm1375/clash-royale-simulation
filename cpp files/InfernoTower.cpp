//
// Created by atenagm on 6/30/16.
//

#include <header files/InfernoTower.h>

InfernoTower::InfernoTower(QPixmap pic, QTimer *timer)
        : Card(spc::Type::BUILDING, spc::Target::AirGround, 0.4, 850, 20, 6.5, 6.5, spc::Speed::NONE, 5, 1, 1, timer)
{
    this->setPixmap(pic);
    id = 14;
}

InfernoTower::~InfernoTower() { }

void InfernoTower::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 14;
    spc::cardNo = 14;
}