//
// Created by atenagm on 6/30/16.
//

#include <header files/Balloon.h>
#include <header files/Tower.h>

Balloon::Balloon(QPixmap pic, QTimer *timer)
        : Card(spc::Type::AIRTROOP, spc::Target::Building, 3, 1050, 600, 2.5, 6.5, spc::Speed::Medium, 5, 1, 1, timer)
{
    this->setPixmap(pic);
    deathDamage = 100;
    id = 3;
    connect(this, SIGNAL(blast()), this, SLOT(bomb()));
}

Balloon::~Balloon() { }

void Balloon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    id = 3;
    spc::cardNo = 3;
}

void Balloon::bomb()
{
    this->setPixmap(QPixmap("sources/Bomb.png").scaled(60, 60));
    bombTimer = new QTimer();
    bombTimer->start(2000);
    connect(bombTimer, SIGNAL(timeout()), this, SLOT(explode()));
}

void Balloon::explode()
{
    for(int i = 0; i < objects->size(); i++){
        if(dynamic_cast<Tower *>(objects->at(i)) != NULL && this->isInRange(objects->at(i)))
            dynamic_cast<Tower *>(objects->at(i))->damaged(deathDamage);
        else if(dynamic_cast<Card *>(objects->at(i)) != NULL && this->isInRange(objects->at(i)))
            dynamic_cast<Card *>(objects->at(i))->damaged(deathDamage);
    }
    bombTimer->stop();
}