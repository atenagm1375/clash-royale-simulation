//
// Created by atenagm on 6/30/16.
//

#include "header files/Card.h"

int spc::cardNo;
Card::Card(int tp, int trgt, double hs, int hp, int d, double r, double tr, int spd, int cost, int c, double dt, QTimer *timer)
        : Object(tp, trgt, hs, hp, d, r, tr, timer)
{
    speed = spd;
    elixirCost = cost;
    count = c;
    deployTime = dt;
    isSelected = false;
    spc::cardNo = 0;
    t1 = false;
    t2 = false;
    isMoving = false;
    stop = false;
    stop2 = false;
    isTerritory = false;
}

Card::~Card()
{
    if(t1){
        if(isMoving){
            mainMoveTimer->stop();
            delete mainMoveTimer;
        }
        attackTimer->stop();
        delete attackTimer;
        mainCheckTimer->stop();
        delete mainCheckTimer;
        for(int i = 0; i < fire.size(); i++){
            scene->removeItem(fire[i]);
            delete fire[i];
        }
        fire.clear();
    }
    if(t2){
        moveTimer->stop();
        delete moveTimer;
        checkTimer->stop();
        delete checkTimer;
    }
}

void Card::setValues(QList<Tower *> twr, QList<Object *> obj, QGraphicsScene *s, bool t)
{
    towers = twr;
    objects = obj;
    scene = s;
    myTeam = t;

    if(speed == spc::Speed::NONE)
        theSpeed = 0;
    else if(speed == spc::Speed::Slow)
        theSpeed = 2;
    else if(speed == spc::Speed::Medium)
        theSpeed = 4;
    else if(speed == spc::Speed::Fast)
        theSpeed = 6;
    else if(speed == spc::Speed::VeryFast)
        theSpeed = 8;

    mainCheckTimer = new QTimer();
    mainCheckTimer->start(20);
    connect(mainCheckTimer, SIGNAL(timeout()), this, SLOT(checkFire()));

    attackTimer = new QTimer();
    attackTimer->start(hitSpeed * 1000);
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(attackRange()));

    t1 = true;
}

void Card::move(double x, double y)
{
    if(isMoving){
        mainMoveTimer->stop();
        delete mainMoveTimer;
    }

    x1 = this->pos().x();
    x2 = x;
    y1 = this->pos().y();
    y2 = y;

    if(x1 == x2){
        slope = 0;
        dx = 0;
        dy = theSpeed * 3 / 4 * (y1 < y2 ? 1 : -1);
    }
    else if(y1 == y2){
        slope = 0;
        dy = 0;
        dx = theSpeed * 3 / 4 * (x1 < x2 ? 1 : -1);
    }
    else{
        slope = (y2 - y1) / (x2 - x1);
        dx = fabs(theSpeed * cos(atan(slope))) * (x1 < x2 ? 1 : -1);
        dy = fabs(theSpeed * sin(atan(slope))) * (y1 < y2 ? 1 : -1);
    }

    mainMoveTimer = new QTimer();
    mainMoveTimer->start(20);
    isMoving = true;
    connect(mainMoveTimer, SIGNAL(timeout()), this, SLOT(changePosition()));
}

void Card::shoot(double x, double y)
{
    Fire *fireBall = new Fire(pos().x(), pos().y(), x, y, spc::fireType::redFire);
    scene->addItem(fireBall);
    fireBall->shoot();
    fire.push_back(fireBall);
}

void Card::changePosition()
{
    if(!stop)
    if(!stop2){
        if((this->pos().x() - x1) * (this->pos().x() - x2) <= 0 &&
           (this->pos().y() - y1) * (this->pos().y() - y2) <= 0)
            this->setPos(x1 + dx, y1 + dy);
        else{
            isMoving = false;
            isTerritory = false;
            mainMoveTimer->stop();
            delete mainMoveTimer;
        }
    }
}

void Card::checkFire()
{
    for(int i = 0; i < fire.size(); i++)
        if(!fire[i]->isAlive){
            scene->removeItem(fire[i]);
            delete fire[i];
            fire.removeAt(i);
        }
}

void Card::attack(QGraphicsPixmapItem *enemy)
{
    if(dynamic_cast<Tower *>(enemy) != NULL)
        dynamic_cast<Tower *>(enemy)->damaged(this->damage);
    else
        dynamic_cast<Card *>(enemy)->damaged(this->damage);
}

void Card::damaged(double d)
{
    if(this->hitPoints > 0)
        this->hitPoints -= d;
    else
        killed();
}

void Card::killed()
{
    isAlive = false;
    this->setPixmap(QPixmap("sources/blood.png").scaled(20, 20));
    second = 0;
    killedTimer = new QTimer();
    killedTimer->start(250);
    connect(killedTimer, SIGNAL(timeout()), this, SLOT(checkKilled()));
}

void Card::checkKilled()
{
    second++;
    if(second == 2){
        killedTimer->stop();
        delete killedTimer;
        this->hitPoints = 0;
    }
}

void Card::attackRange()
{
    if(isAlive){
        if(this->target == spc::Target::AirGround){
            for(int i = 0; i < objects.size(); i++)
                if(!objects[i]->myTeam && objects[i]->isAlive && isInRange(objects[i])){
                    attack(objects[i]);
                    stop = true;
                    return;
                }
            for(int i = 0; i < towers.size(); i++)
                if(!towers[i]->myTeam && towers[i]->isAlive && isInRange(towers[i])){
                    attack(towers[i]);
                    stop = true;
                    return;
                }
            stop = false;
        }
        else if(this->target == spc::Target::Ground){
            for(int i = 0; i < objects.size(); i++)
                if(objects[i]->type == spc::Type::GROUNDTROOP || objects[i]->type == spc::Type::BUILDING
                        && !objects[i]->myTeam && objects[i]->isAlive && isInRange(objects[i])){
                    attack(objects[i]);
                    stop = true;
                    return;
                }
            for(int i = 0; i < towers.size(); i++)
                if(!towers[i]->myTeam && towers[i]->isAlive && isInRange(towers[i])){
                    attack(towers[i]);
                    stop = true;
                    return;
                }
            stop = false;
        }
        else if(this->target == spc::Target::Building){
            for(int i = 0; i < objects.size(); i++)
                if(objects[i]->type == spc::Type::BUILDING && !objects[i]->myTeam &&
                        objects[i]->isAlive && isInRange(objects[i])){
                    attack(objects[i]);
                    stop = true;
                    return;
                }
            for(int i = 0; i < towers.size(); i++)
                if(!towers[i]->myTeam && towers[i]->isAlive && isInRange(towers[i])){
                    attack(towers[i]);
                    stop = true;
                    return;
                }
            stop = false;
        }
    }
}

bool Card::isInRange(QGraphicsPixmapItem *enemy)
{
    double a1 = this->pos().x() + this->boundingRect().center().x();
    double a2 = enemy->pos().x() + enemy->boundingRect().center().x();
    double b1 = this->pos().y() + this->boundingRect().center().y();
    double b2 = enemy->pos().y() + enemy->boundingRect().center().y();

    return (a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1) <= range * range;
}

bool Card::isInTerritory(QGraphicsPixmapItem *enemy)
{
    double a1 = this->pos().x() + this->boundingRect().center().x();
    double a2 = enemy->pos().x() + enemy->boundingRect().center().x();
    double b1 = this->pos().y() + this->boundingRect().center().y();
    double b2 = enemy->pos().y() + enemy->boundingRect().center().y();

    return (a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1) <= territory * territory;
}

void Card::start()
{
    moveTimer = new QTimer();
    moveTimer->start(15);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(goAhead()));

    checkTimer = new QTimer();
    checkTimer->start(15);
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(check()));
}

void Card::goAhead()
{
    if(!isMoving){
        if(this->type == spc::Type::GROUNDTROOP){
            if(this->pos().y() > 400){
                if(myTeam && this->pos().x() < 600)
                    move(380, 400);
                else if(myTeam && this->pos().x() >= 600)
                    move(830, 400);
                else if(!myTeam && this->pos().x() < 600)
                    move(520, 600);
                else if(!myTeam && this->pos().x() >= 600)
                    move(670, 600);

            }
            else{
                if(myTeam && this->pos().x() < 600)
                    move(520, 75);
                else if(myTeam && this->pos().x() >= 600)
                    move(670, 75);
                else if(!myTeam && this->pos().x() < 600)
                    move(380, 300);
                else if(!myTeam && this->pos().x() >= 600)
                    move(830, 300);
            }
        }
        else if(this->type == spc::Type::AIRTROOP){
            if(this->pos().y() > 400){
                if(myTeam && this->pos().x() < 600)
                    move(390, 200);
                else if(myTeam && this->pos().x() >= 600)
                    move(840, 200);
                else if(!myTeam && this->pos().x() < 600)
                    move(520, 600);
                else if(!myTeam && this->pos().x() >= 600)
                    move(670, 600);
            }
            else{
                if(myTeam && this->pos().x() < 600)
                    move(520, 75);
                else if(myTeam && this->pos().x() >= 600)
                    move(670, 75);
                else if(!myTeam && this->pos().x() < 600)
                    move(390, 500);
                else if(!myTeam && this->pos().x() >= 600)
                    move(840, 500);
            }
        }
    }
    if(!isTerritory){
        if(this->target == spc::Target::Building){
            for(int i = 0; i < objects.size(); i++)
                if(!objects[i]->myTeam && objects[i]->type == spc::Type::BUILDING &&
                        objects[i]->isAlive && isInTerritory(objects[i])){
                    move(objects[i]->pos().x(), objects[i]->pos().y());
                    isTerritory = true;
                }
            for(int i = 0; i < towers.size(); i++)
                if(!towers[i]->myTeam && towers[i]->isAlive && isInTerritory(towers[i])){
                    move(towers[i]->pos().x(), towers[i]->pos().y());
                    isTerritory = true;
                }
        }
        else if(this->target == spc::Target::Ground){
            for(int i = 0; i < objects.size(); i++)
                if(!objects[i]->myTeam && objects[i]->type == spc::Type::BUILDING ||
                        objects[i]->type == spc::Type::GROUNDTROOP && objects[i]->isAlive
                        && isInTerritory(objects[i])){
                    move(objects[i]->pos().x(), objects[i]->pos().y());
                    isTerritory = true;
                }
            for(int i = 0; i < towers.size(); i++)
                if(!towers[i]->myTeam && towers[i]->isAlive && isInTerritory(towers[i])){
                    move(towers[i]->pos().x(), towers[i]->pos().y());
                    isTerritory = true;
                }
        }
        else if(this->target == spc::Target::AirGround){
            for(int i = 0; i < objects.size(); i++)
                if(!objects[i]->myTeam && objects[i]->type != spc::Type::SPELL &&
                        objects[i]->isAlive && isInTerritory(objects[i])){
                    move(objects[i]->pos().x(), objects[i]->pos().y());
                    isTerritory = true;
                }
            for(int i = 0; i < towers.size(); i++)
                if(!towers[i]->myTeam && towers[i]->isAlive && isInTerritory(towers[i])){
                    move(towers[i]->pos().x(), towers[i]->pos().y());
                    isTerritory = true;
                }
        }
    }
}

void Card::check()
{
    if(this->target == spc::Target::Building){
        for(int i = 0; i < objects.size(); i++)
            if(!objects[i]->myTeam && objects[i]->type == spc::Type::BUILDING && objects[i]->isAlive
                    && isInRange(objects[i])){
                stop = true;
                return;
            }
        for(int i = 0; i < towers.size(); i++)
            if(!towers[i]->myTeam && towers[i]->isAlive && isInRange(towers[i])){
                stop = true;
                return;
            }
        stop = false;
    }
    else if(this->target == spc::Target::Ground){
        for(int i = 0; i < objects.size(); i++)
            if(!objects[i]->myTeam && objects[i]->type == spc::Type::BUILDING ||
                    objects[i]->type == spc::Type::GROUNDTROOP && objects[i]->isAlive
                    && isInRange(objects[i])){
                stop = true;
                return;
            }
        for(int i = 0; i < towers.size(); i++)
            if(!towers[i]->myTeam && towers[i]->isAlive && isInRange(towers[i])){
                stop = true;
                return;
            }
        stop = false;
    }
    else if(this->target == spc::Target::AirGround){
        for(int i = 0; i < objects.size(); i++)
            if(!objects[i]->myTeam && objects[i]->type != spc::Type::SPELL && objects[i]->isAlive
                    && isInRange(objects[i])){
                stop = true;
                return;
            }
        for(int i = 0; i < towers.size(); i++)
            if(!towers[i]->myTeam && towers[i]->isAlive && isInRange(towers[i])){
                stop = true;
                return;
            }
        stop = false;
    }
}

void Card::pause()
{
    if(t1){
        if(isMoving)
            mainMoveTimer->stop();
        attackTimer->stop();
    }
    if(t2){
        moveTimer->stop();
        checkTimer->stop();
    }
}

void Card::resume()
{
    if(t1){
        if(isMoving)
            mainMoveTimer->start();
        attackTimer->start();
    }
    if(t2){
        moveTimer->start();
        checkTimer->start();
    }
}