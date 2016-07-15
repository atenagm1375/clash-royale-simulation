//
// Created by atenagm on 6/30/16.
//

#include <header files/Rage.h>

Rage::Rage(QPixmap pic, QTimer *timer)
        : Card(spc::Type::SPELL, spc::Target::AirGround, 0, 0, 0, 5, 5, spc::Speed::NONE, 3, 1, 0, timer)
{
    this->setPixmap(pic);
    duration = 8;
}

Rage::~Rage() { }

void Rage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 13;
    spc::cardNo = 13;
}