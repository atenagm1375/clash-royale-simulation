//
// Created by atenagm on 6/30/16.
//

#include <header files/Witch.h>

Witch::Witch(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::AirGround, 0.7, 500, 42, 5.5, 5.5, spc::Speed::Medium, 5, 1, 1, timer)
{
    this->setPixmap(pic);
    skeleton = new Skeleton(QPixmap("sources/Skeletons.png"), timer);
    id = 9;
}

Witch::~Witch() { }

void Witch::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 9;
    spc::cardNo = 9;
}