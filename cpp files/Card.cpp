//
// Created by atenagm on 6/30/16.
//

#include <iostream>
#include "header files/Card.h"
#include <header files/Tower.h>

int spc::cardNo;
Card::Card(int tp, int trgt, double hs, int hp, int d, double r, double tr, int spd, int cost, int c, double dt, QTimer *timer)
        : Object(tp, trgt, hs, hp, d, r, tr, timer)
{
    speed = spd;
    elixirCost = cost;
    count = c;
    deployTime = dt;
    spc::cardNo = 0;
    isMoving = false;
    shouldStop = false;
    canSee = false;
}

Card::~Card() { }

void Card::initialization(QList<Object *> *objs, QGraphicsScene *s)
{
    objects = objs;
    scene = s;

    if(speed == spc::Speed::NONE)
        speedValue = 0;
    else if(speed == spc::Speed::Slow)
        speedValue = 1;
    else if(speed == spc::Speed::Medium)
        speedValue = 4;
    else if(speed == spc::Speed::Fast)
        speedValue = 7;
    else
        speedValue = 10;

    fireCheckTimer = new QTimer();
    fireCheckTimer->start(hitSpeed * 1000);
    connect(fireCheckTimer, SIGNAL(timeout()), this, SLOT(fireCheck()));

    attackTimer = new QTimer();
    attackTimer->start(hitSpeed * 1000);
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(attackRange()));
}

void Card::move(double x, double y)
{
    if(isMoving){
        disconnect(moveTimer, SIGNAL(timeout()), this, SLOT(changePosition()));
        moveTimer->stop();
    }

    x1 = this->pos().x();
    y1 = this->pos().y();
    x2 = x;
    y2 = y;

    if(x1 == x2){
        m = 0;
        dx = 0;
        dy = speedValue * (y2 > y1 ? 0.75 : -0.75);
    }
    else if(y1 == y2){
        m = 0;
        dx = speedValue * (x2 > x1 ? 0.75 : -0.75);
        dy = 0;
    }
    else{
        m = (y2 - y1) / (x2 - x1);
        dx = fabs(speedValue * cos(atan(m))) * (x2 > x1 ? 1 : -1);
        dy = fabs(speedValue * sin(atan(m))) * (y2 > y1 ? 1 : -1);
    }

    moveTimer = new QTimer();
    moveTimer->start(30);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(changePosition()));
    isMoving = true;
}

void Card::changePosition()
{
    if(!shouldStop){
        if((this->pos().x() - x1) * (this->pos().x() - x2) <= 0 &&
                    (this->pos().y() - y1) * (this->pos().y() - y2) <= 0)
            this->moveBy(dx, dy);
        else{
            isMoving = false;
            moveTimer->stop();
            canSee = false;
        }
    }
}

void Card::moveManagement()
{
    if(!isMoving){
        if(this->isMyTeam){
            if(this->pos().y() + this->boundingRect().center().y() > 400) {
                if (this->pos().x() + this->boundingRect().center().x() <= 600)
                    move(357.5, 350);
                else
                    move(810, 350);
            }
            else
                move(x(), 200);
        }
    }
    if(!canSee){
        if(this->target == spc::Target::AirGround)
            for(int i = 0; i < objects->size(); i++) {
                if (objects->at(i)->isMyTeam != this->isMyTeam && objects->at(i)->type != spc::Type::SPELL &&
                    objects->at(i)->isAlive && this->isInTerritory(objects->at(i))) {
                    move(objects->at(i)->pos().x() + boundingRect().center().x(),
                         objects->at(i)->pos().y() + boundingRect().bottomRight().y());
                    canSee = true;
                }
            }
        else if(this->target == spc::Target::Ground)
            for(int i = 0; i < objects->size(); i++) {
                if (objects->at(i)->isMyTeam != this->isMyTeam && (objects->at(i)->type == spc::Type::BUILDING
                                                                   || objects->at(i)->type == spc::Type::GROUNDTROOP) &&
                    objects->at(i)->isAlive && this->isInTerritory(objects->at(i))) {
                    move(objects->at(i)->pos().x() + boundingRect().center().x(),
                         objects->at(i)->pos().y() + boundingRect().bottomRight().y());
                    canSee = true;
                }
            }
        else if(this->target == spc::Target::Building)
            for(int i = 0; i < objects->size(); i++)
                if(objects->at(i)->isMyTeam != this->isMyTeam && objects->at(i)->type == spc::Type::BUILDING &&
                   objects->at(i)->isAlive && this->isInTerritory(objects->at(i))){
                    move(objects->at(i)->pos().x() + boundingRect().center().x(),
                         objects->at(i)->pos().y() + boundingRect().bottomRight().y());
                    canSee = true;
                }
    }
}

bool Card::isInTerritory(Object *obj)
{
    double myX = this->pos().x() + this->boundingRect().center().x();
    double myY = this->pos().y() + this->boundingRect().center().y();
    double objX = obj->pos().x() + obj->boundingRect().center().x();
    double objY = obj->pos().y() + obj->boundingRect().center().y();

    return (myX - objX) * (myX - objX) + (myY - objY) * (myY - objY) <= territory * territory;
}

void Card::moveControl()
{
    timer = new QTimer();
    timer->start(deployTime * 1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveManagement()));

    checkTimer = new QTimer();
    checkTimer->start(deployTime * 1000);
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(attackRange()));
}

void Card::fireCheck()
{
    for(int i = 0; i < fires.size(); i++)
        if(!fires[i]->isAlive){
            scene->removeItem(fires[i]);
            delete fires[i];
            fires.removeAt(i);
        }
}

void Card::attackRange()
{
    if(isAlive){
        if(this->target == spc::Target::Building) {
            for (int i = 0; i < objects->size(); i++)
                if (this->isMyTeam != objects->at(i)->isMyTeam && objects->at(i)->isAlive &&
                    objects->at(i)->type == spc::Type::BUILDING && this->isInRange(objects->at(i))) {
                    attack(objects->at(i));
                    shouldStop = true;
                    return;
                }
            shouldStop = false;
        }
        else if(this->target == spc::Target::Ground){
            for(int i = 0; i < objects->size(); i++)
                if(this->isMyTeam != objects->at(i)->isMyTeam && objects->at(i)->isAlive &&
                        (objects->at(i)->type == spc::Type::BUILDING || objects->at(i)->type == spc::Type::GROUNDTROOP)
                        && this->isInRange(objects->at(i))){
                    attack(objects->at(i));
                    shouldStop = true;
                    return;
                }
            shouldStop = false;
        }
        else if(this->target == spc::Target::AirGround){
            for(int i = 0; i < objects->size(); i++)
                if(this->isMyTeam != objects->at(i)->isMyTeam && objects->at(i)->isAlive &&
                        objects->at(i)->type != spc::Type::SPELL && this->isInRange(objects->at(i))){
                    attack(objects->at(i));
                    shouldStop = true;
                    return;
                }
            shouldStop = false;
        }
    }
}

bool Card::isInRange(Object *obj)
{
    double myX = this->pos().x() + this->boundingRect().center().x();
    double myY = this->pos().y() + this->boundingRect().center().y();
    double objX = obj->pos().x() + obj->boundingRect().center().x();
    double objY = obj->pos().y() + obj->boundingRect().center().y();

    return (myX - objX) * (myX - objX) + (myY - objY) * (myY - objY) <= range * range;
}

void Card::attack(Object *obj)
{
    if(dynamic_cast<Tower *>(obj) != NULL)
        dynamic_cast<Tower *>(obj)->damaged(this->damage);
    else
        dynamic_cast<Card *>(obj)->damaged(this->damage);

    shoot(obj->pos().x() + obj->boundingRect().center().x(), obj->pos().y() + obj->boundingRect().center().y());
}

void Card::damaged(double d)
{
    if(this->hitPoints > d)
        this->hitPoints -= d;
    else
        killCard();
}

void Card::shoot(double x, double y)
{
    fires.push_back(new Fire(this->pos().x() + this->boundingRect().center().x(),
                             this->pos().y() + this->boundingRect().center().y(), x, y, spc::fireType::redFire));
    scene->addItem(fires.back());
    fires.back()->shoot();
}

void Card::killCard()
{
    this->setPixmap(QPixmap("sources/blood.png").scaled(40, 40));
    this->isAlive = false;
    second = 0;

    bloodTimer = new QTimer();
    bloodTimer->start(1000);
    connect(bloodTimer, SIGNAL(timeout()), this, SLOT(vanish()));
}

void Card::vanish()
{
    second++;
    if(second == 2){
        bloodTimer->stop();
        delete bloodTimer;
        this->hitPoints = 0;
    }
}