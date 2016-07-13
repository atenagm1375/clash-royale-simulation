//
// Created by atenagm on 7/2/16.
//

#include <header files/Tower.h>

Tower::Tower(int tp, int trgt, double hs, int hp, int d, double r, double tr, QPixmap *pic, QTimer *timer) :
            Object(tp, trgt, hs, hp, d, r, tr, timer)
{
    this->setPixmap(*pic);
    isKingTower = false;
}

void Tower::setValues(QList<Object *> obj, QGraphicsScene *s)
{
    objects = obj;
    scene = s;

    checkTimer = new QTimer();
    connect(checkTimer, SIGNAL(timeout()), this, SLOT(checkRange()));
    checkTimer->start(1000 * hitSpeed);

    fireTimer = new QTimer();
    fireTimer->start(20);
    connect(fireTimer, SIGNAL(timeout()), this, SLOT(checkFire()));
}

Tower::~Tower()
{
    fireTimer->stop();
    delete fireTimer;

    for(int i = 0; i < fire.size(); i++){
        scene->removeItem(fire[i]);
        delete fire[i];
    }

    checkTimer->stop();
    delete checkTimer;
}

void Tower::damaged(double d)
{
    if(this->hitPoints > 0)
        this->hitPoints -= d;
    else
        killed();
}

void Tower::killed()
{
    isAlive = false;
    second = 0;
    this->setPixmap(QPixmap("sources/blood.png").scaled(20, 20));

    killedTimer = new QTimer();
    killedTimer->start(250);
    connect(killedTimer, SIGNAL(timeout()), this, SLOT(checkKilled()));
}

void Tower::attack(QGraphicsPixmapItem *enemy)
{
    if(dynamic_cast<Object *>(enemy) != NULL)
        dynamic_cast<Object *>(enemy)->damaged(this->damage);
    shoot(enemy->pos().x() + enemy->boundingRect().center().x(),
          enemy->pos().y() + enemy->boundingRect().center().y());
}

void Tower::shoot(double x, double y)
{
    Fire *theFire;
    if(isKingTower)
        theFire = new Fire(this->pos().x(), this->pos().y(), x, y, spc::fireType::greenFire);
    else
        theFire = new Fire(this->pos().x(), this->pos().y(), x, y, spc::fireType::blueFire);

    scene->addItem(theFire);
    theFire->shoot();
    fire.push_back(theFire);
}

void Tower::checkRange()
{
    if(isAlive)
        for(int i = 0; i < objects.size(); i++)
            if(!objects[i]->myTeam && isInRange(objects[i]) && objects[i]->isAlive){
                attack(objects[i]);
                return;
            }
}

bool Tower::isInRange(QGraphicsPixmapItem *enemy)
{
    double a1 = this->pos().x() + this->boundingRect().center().x();
    double a2 = enemy->pos().x() + enemy->boundingRect().center().x();
    double b1 = this->pos().y() + this->boundingRect().center().y();
    double b2 = enemy->pos().y() + enemy->boundingRect().center().y();

    return (a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1) <= range * range;
}

void Tower::checkFire()
{
    for(int i = 0; i < fire.size(); i++)
        if(!fire[i]->isAlive){
            scene->removeItem(fire[i]);
            delete fire[i];
            fire.removeAt(i);
        }
}

void Tower::check()
{
    second++;
    if(second == 2){
        killedTimer->stop();
        delete killedTimer;
        this->hitPoints = 0;
    }
}