//
// Created by atenagm on 6/30/16.
//

#include <header files/Mirror.h>

Mirror::Mirror(QPixmap pic, QTimer *timer)
        : Card(spc::Type::SPELL, spc::Target::what, 0, 0, 0, 0, 0, spc::Speed::NONE, 0, 0, 0, timer)
{
    this->setPixmap(pic);
}

Mirror::~Mirror() { }

void Mirror::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 11;
}