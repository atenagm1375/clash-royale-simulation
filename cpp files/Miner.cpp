//
// Created by atenagm on 6/30/16.
//

#include <header files/Miner.h>

Miner::Miner(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::Ground, 1.2, 1000, 160, 2, 6.5, spc::Speed::Fast, 3, 1, 1, timer)
{
    this->setPixmap(pic);
    crownTowerDamage = 64;
    id = 8;
}

Miner::~Miner() { }

void Miner::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 8;
    spc::cardNo = 8;
}