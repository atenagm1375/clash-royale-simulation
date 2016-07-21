//
// Created by atenagm on 6/30/16.
//

#include <header files/Balloon.h>

Balloon::Balloon(QPixmap pic, QTimer *timer)
        : Card(spc::Type::AIRTROOP, spc::Target::Building, 3, 1050, 600, 1, 3.5, spc::Speed::Medium, 5, 1, 1, timer)
{
    this->setPixmap(pic);
    deathDamage = 100;
    id = 3;
}

Balloon::~Balloon() { }

void Balloon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 3;
    spc::cardNo = 3;
}