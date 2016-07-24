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

Tower::~Tower() { }

void Tower::initialization(QList<Object *> *objs, QGraphicsScene *s)
{
    objects = objs;
    scene = s;

    if(this->isMyTeam)
        hpBar->setDefaultTextColor(Qt::cyan);
    else
        hpBar->setDefaultTextColor(Qt::red);

    attackTimer = new QTimer();
    attackTimer->start(hitSpeed * 1000);
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(attackRange()));

    fireCheckTimer = new QTimer();
    fireCheckTimer->start(hitSpeed * 1000);
    connect(fireCheckTimer, SIGNAL(timeout()), this, SLOT(fireCheck()));
}

void Tower::attackRange()
{
    if(isAlive){
        for(int i = 0; i < objects->size(); i++)
            if(this->isMyTeam != objects->at(i)->isMyTeam && objects->at(i)->isAlive && isInRange(objects->at(i))){
                attack(objects->at(i));
                return;
            }
    }
}

void Tower::fireCheck()
{
    for(int i = 0; i < fires.size(); i++)
        if(!fires[i]->isAlive){
            scene->removeItem(fires[i]);
            delete fires[i];
            fires.removeAt(i);
        }
}

void Tower::attack(Object *obj)
{
    if(dynamic_cast<Card *>(obj) != NULL)
        dynamic_cast<Card *>(obj)->damaged(this->damage);

    shoot(obj->pos().x(), obj->pos().y());
}

void Tower::shoot(double x, double y)
{
    fires.push_back(new Fire(this->pos().x(),
                             this->pos().y(), x, y, spc::fireType::blueFire));
    scene->addItem(fires.back());
    fires.back()->shoot();
}

void Tower::damaged(double d)
{
    if(this->hitPoints > d) {
        this->hitPoints -= d;
        hpBar->setPlainText(QString::number(hitPoints));
    }
    else
        destroyTower();
}

void Tower::destroyTower()
{
    hpBar->hide();
    this->setPixmap(QPixmap("sources/blood.png").scaled(20, 20));
    this->isAlive = false;
    second = 0;

    bloodTimer = new QTimer();
    bloodTimer->start(1000);
    connect(bloodTimer, SIGNAL(timeout()), this, SLOT(vanish()));
}

void Tower::vanish()
{
    second++;
    if(second == 2){
        bloodTimer->stop();
        delete bloodTimer;
        this->hitPoints = 0;
    }
}

bool Tower::isInRange(Object *obj)
{
    double myX = this->pos().x();
    double myY = this->pos().y();
    double objX = obj->pos().x();
    double objY = obj->pos().y();

    return (myX - objX) * (myX - objX) + (myY - objY) * (myY - objY) <= range * range;
}