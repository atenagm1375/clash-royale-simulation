//
// Created by atenagm on 6/30/16.
//

#include <header files/Zap.h>

Zap::Zap(QPixmap pic, QTimer *timer)
        : Card(spc::Type::SPELL, spc::Target::Ground, 0, 0, 80, 2.5, 0, spc::Speed::NONE, 2, 1, 0, timer)
{
    this->setPixmap(pic);
    crownTowerDamage = 32;
    id = 12;
}

Zap::~Zap() { }

void Zap::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 12;
    spc::cardNo = 12;
}