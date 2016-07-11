//
// Created by atenagm on 6/30/16.
//

#include <header files/Rage.h>

Rage::Rage(QPixmap pic, QTimer *timer)
        : Card(spc::Type::SPELL, spc::Target::Area, 0, 0, 0, 5, 5, spc::Speed::NONE, 3, 1, 0, timer)
{
    this->setPixmap(pic);
    duration = 9.5;
}

Rage::~Rage() { }

void Rage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 13;
}