//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_CARD_H
#define CLASH_ROYALE_CARD_H


#include <QtWidgets/qwidget.h>
#include <QTimer>
#include "Object.h"
#include "Specifications.h"
#include "Fire.h"

class CardManagement;
class map1;

class Card : public Object{

    Q_OBJECT
    friend class CardManagement;
    friend class map1;

public:

    Card(int, int, double, int, int, double, double, int, int, int, double, QTimer *);
    ~Card();
    int id;
    void initialization(QList<Object *> *);

protected:

    int speed;
    int speedValue;
    int elixirCost;
    int count;
    double deployTime;
    QTimer *moveTimer;
    QList<Object *> *objects;
    QList<Fire *> fires;
    bool isMoving;
    bool shouldStop;
    bool canSee;
    double x1;
    double x2;
    double y1;
    double y2;
    double m;
    double dx;
    double dy;
    QTimer *timer;

    void move(double, double);
    bool isInTerritory(Object *);

public slots:

    void changePosition();
    void moveManagement();
    void moveControl();
};


#endif //CLASH_ROYALE_CARD_H
