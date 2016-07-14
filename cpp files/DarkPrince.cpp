//
// Created by atenagm on 6/30/16.
//

#include <header files/DarkPrince.h>

DarkPrince::DarkPrince(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::Ground, 1.5, 700, 270, 1, 2, spc::Speed::Medium, 4, 1, 1, timer)
{
    this->setPixmap(pic);
    shieldHitPoint = 200;
    areaDamage = 135;
}

DarkPrince::~DarkPrince() { }

void DarkPrince::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 4;
}