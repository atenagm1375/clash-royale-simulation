//
// Created by atenagm on 6/30/16.
//

#include <header files/Miner.h>

Miner::Miner(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::Ground, 1.2, 1000, 160, 1, 2, spc::Speed::Fast, 3, 1, 1, timer)
{
    this->setPixmap(pic);
    crownTowerDamage = 64;
}

Miner::~Miner() { }

void Miner::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 8;
}