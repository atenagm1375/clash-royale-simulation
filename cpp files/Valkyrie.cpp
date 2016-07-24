//
// Created by atenagm on 6/30/16.
//

#include <header files/Valkyrie.h>

Valkyrie::Valkyrie(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::Ground, 1.5, 880, 120, 2, 6.5, spc::Speed::Medium, 4, 1, 1, timer)
{
    this->setPixmap(pic);
    id = 7;
}

Valkyrie::~Valkyrie() { }

void Valkyrie::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 7;
    spc::cardNo = 7;
}