//
// Created by atenagm on 6/30/16.
//

#include <header files/UsingFurnace.h>

UsingFurnace::UsingFurnace(QPixmap pic, QTimer *timer)
        : Card(spc::Type::BUILDING, spc::Target::AirGround, 0, 600, 0, 0, 6.5, spc::Speed::NONE, 4, 1, 1, timer)
{
    this->setPixmap(pic);
    fireSpirits = new FireSpirits(QPixmap("sources/fireSpirits.png"), timer);
    lifeTime = 50;
    spawnSpeed = 10;
}

UsingFurnace::~UsingFurnace() { }

void UsingFurnace::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected = true;
    spc::cardNo = 15;
}