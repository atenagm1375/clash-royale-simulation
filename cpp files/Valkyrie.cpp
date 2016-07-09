//
// Created by atenagm on 6/30/16.
//

#include <header files/Valkyrie.h>

Valkyrie::Valkyrie(QPixmap pic, QTimer *timer)
        : Card(spc::Type::TROOP, spc::Target::Ground, 1.5, 1170, 159, 1, 2, spc::Speed::Medium, 4, 1, 1, timer)
{
    this->setPixmap(pic);
}

Valkyrie::~Valkyrie() { }