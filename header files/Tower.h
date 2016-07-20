//
// Created by atenagm on 7/2/16.
//

#ifndef CLASH_ROYALE_TOWER_H
#define CLASH_ROYALE_TOWER_H


#include "Object.h"
#include "Fire.h"
#include <QGraphicsScene>
#include "Card.h"

class Tower : public Object{

    Q_OBJECT
    friend class Card;

public:

    Tower(int, int, double, int, int, double, double, QPixmap *, QTimer *);
    ~Tower();
    void initialization(QList<Object *> *, QGraphicsScene *);

    bool isKingTower;

protected:

    QGraphicsScene *scene;
    QList<Object *> *objects;
    QList<Fire *> fires;
    QTimer *attackTimer;
    QTimer *bloodTimer;
    QTimer *fireCheckTimer;
    int second;
    void damaged(double);
    void attack(Object *);
    void shoot(double, double);
    void destroyTower();
    bool isInRange(Object *);

public slots:

    void attackRange();
    void fireCheck();
    void vanish();
};


#endif //CLASH_ROYALE_TOWER_H
