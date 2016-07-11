//
// Created by atenagm on 6/30/16.
//

#include <header files/Zap.h>

Zap::Zap(QPixmap pic, QTimer *timer)
        : Card(spc::Type::SPELL, spc::Target::Ground, 0, 0, 106, 2.5, 2.5, spc::Speed::NONE, 2, 1, 0, timer)
{
    this->setPixmap(pic);
    crownTowerDamage = 43;
}

Zap::~Zap() { }

void Zap::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 12;
}