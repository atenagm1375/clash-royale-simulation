//
// Created by atenagm on 6/30/16.
//

#include <header files/IceWizard.h>

IceWizard::IceWizard(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::AirGround, 1.2, 847, 76, 6, 6, spc::Speed::Medium, 3, 1, 1, timer)
{
    this->setPixmap(pic);
}

IceWizard::~IceWizard() { }