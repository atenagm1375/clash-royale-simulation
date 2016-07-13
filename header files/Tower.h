//
// Created by atenagm on 7/2/16.
//

#ifndef CLASH_ROYALE_TOWER_H
#define CLASH_ROYALE_TOWER_H


#include "Object.h"
#include "Fire.h"
#include <QGraphicsScene>
#include <QTimer>
#include "Card.h"
#include <QList>

class Tower : public Object{

    Q_OBJECT
    friend class Card;
    friend class map1;
    friend class map2;

public:

    Tower(int, int, double, int, int, double, double, QPixmap *, QTimer *);
    ~Tower();
    void damaged(double);
    void setValues(QList<Object *>, QGraphicsScene *);

private:

    bool isKingTower;
    int second;
    QTimer *killedTimer;
    QTimer *checkTimer;
    QTimer *fireTimer;
    QList<Object *> objects;
    QGraphicsScene *scene;
    QList<Fire *> fire;

    void attack(QGraphicsPixmapItem *);
    void killed();
    void shoot(double, double);
    bool isInRange(QGraphicsPixmapItem *);

public slots:

    void check();
    void checkRange();
    void checkFire();
};


#endif //CLASH_ROYALE_TOWER_H
