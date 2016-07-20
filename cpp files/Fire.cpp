//
// Created by atenagm on 7/2/16.
//

#include <header files/Fire.h>

Fire::Fire(double x, double y, double xx, double yy, int type)
{
    isAlive = true;
    x1 = x;
    y1 = y;
    x2 = xx;
    y2 = yy;
    bulType = type;

    this->setPos(x1, y1);

    if(bulType == spc::fireType::blueFire){
        pic = new QPixmap("sources/blueFire.png");
        this->setPixmap(pic->scaled(10, 10));
    }
    else if(bulType == spc::fireType::greenFire){
        pic = new QPixmap("sources/greenFire.png");
        this->setPixmap(pic->scaled(10, 10));
    }
    else{
        pic = new QPixmap("sources/redFire.png");
        this->setPixmap(pic->scaled(10, 10));
    }

    if(x1 == x2){
        slope = 0;
        dx = 0;
        dy = y1 < y2 ? 3 : -3;
    }
    else if(y1 == y2){
        slope = 0;
        dy = 0;
        dx = x1 < x2 ? 3 : -3;
    }
    else{
        slope = (y2 - y1) / (x2 - x1);
        dx = fabs(4 * cos(atan(slope))) * (x1 < x2 ? 1 : -1);
        dy = fabs(4 * sin(atan(slope))) * (y1 < y2 ? 1 : -1);
    }

    timer = new QTimer();
}

Fire::~Fire() { }

void Fire::shoot()
{
    timer->start(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(changePosition()));
}

void Fire::changePosition()
{
    if((this->pos().x() - x1) * (this->pos().x() - x2) <= 0 &&
       (this->pos().y() - y1) * (this->pos().y() - y2) <= 0)
        this->moveBy(dx, dy);
    else{
        timer->stop();
        isAlive = false;
    }
}