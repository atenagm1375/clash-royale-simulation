//
// Created by atenagm on 6/30/16.
//

#include <header files/DarkPrince.h>

DarkPrince::DarkPrince(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::Ground, 1.5, 700, 270, 1, 3.5, spc::Speed::Medium, 4, 1, 1, timer)
{
    this->setPixmap(pic);
    shieldHitPoint = 200;
    areaDamage = 135;
    id = 4;
}

DarkPrince::~DarkPrince() { }

void DarkPrince::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 4;
    spc::cardNo = 4;
}