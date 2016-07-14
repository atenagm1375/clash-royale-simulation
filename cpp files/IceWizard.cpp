//
// Created by atenagm on 6/30/16.
//

#include <header files/IceWizard.h>

IceWizard::IceWizard(QPixmap pic, QTimer *timer)
        : Card(spc::Type::GROUNDTROOP, spc::Target::AirGround, 1.2, 700, 63, 6, 6, spc::Speed::Medium, 3, 1, 1, timer)
{
    this->setPixmap(pic);
}

IceWizard::~IceWizard() { }

void IceWizard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 2;
}