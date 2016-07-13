//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_CARD_H
#define CLASH_ROYALE_CARD_H


#include <QtWidgets/qwidget.h>
#include <QTimer>
#include "Object.h"
#include "Specifications.h"
#include "Tower.h"
#include "Fire.h"
#include <QGraphicsScene>
#include <QList>

class Card : public Object{

    Q_OBJECT
    friend class map1;
    friend class map2;

public:

    //Card();
    Card(int, int, double, int, int, double, double, int, int, int, double, QTimer *);
    ~Card();
    bool isSelected;
    bool stop;
    bool stop2;
    bool isTerritory;
    int elixirCost;
    QTimer *moveTimer;
    QTimer *checkTimer;

    void setValues(QList<Tower *>, QList<Object *>, QGraphicsScene *, bool);
    bool isInRange(QGraphicsPixmapItem *);
    bool isInTerritory(QGraphicsPixmapItem *);
    void pause();
    void start();
    void resume();
    void attack(QGraphicsPixmapItem *);
    void damaged(double);

protected:

    int speed;
    int count;
    double deployTime;
    QGraphicsScene *scene;
    QList<Tower *> towers;
    QList<Object *> objects;
    QList<Fire *> fire;
    bool t1;
    bool t2;
    double x1;
    double x2;
    double y1;
    double y2;
    double dx;
    double dy;
    double slope;
    int theSpeed;
    bool isMoving;
    QTimer *mainMoveTimer;
    QTimer *mainCheckTimer;
    QTimer *killedTimer;
    QTimer *attackTimer;
    int second;

    void move(double, double);
    void shoot(double, double);
    void killed();

public slots:

    void checkFire();
    void attackRange();
    void changePosition();
    void checkKilled();
    void goAhead();
    void check();
};


#endif //CLASH_ROYALE_CARD_H
