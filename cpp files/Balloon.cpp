//
// Created by atenagm on 6/30/16.
//

#include <header files/Balloon.h>

Balloon::Balloon(QPixmap pic, QTimer *timer)
        : Card(spc::Type::AIRTROOP, spc::Target::Building, 3, 1050, 600, 1, 2, spc::Speed::Medium, 5, 1, 1, timer)
{
    this->setPixmap(pic);
    deathDamage = 100;
}

Balloon::~Balloon() { }

void Balloon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 3;
}