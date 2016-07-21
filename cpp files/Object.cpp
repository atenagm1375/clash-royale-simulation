//
// Created by atenagm on 7/3/16.
//

#include <header files/Object.h>
#include <QFont>

Object::Object() { }

Object::Object(int tp, int trgt, double hs, int hp, int d, double r, double tr, QTimer *timer)
{
    type = tp;
    target = trgt;
    hitSpeed = hs;
    hitPoints = hp;
    damage = d;
    range = r * 40;
    territory = tr * 50;
    isMyTeam = true;
    isAlive = true;

    hpBar = new QGraphicsTextItem(QString::number(hitPoints), this);
    hpBar->setPos(this->pos());
    hpBar->setRotation(1.5);
    hpBar->setFont(QFont("serif", 20));
    hpBar->setDefaultTextColor(Qt::yellow);
}

Object::~Object() { }