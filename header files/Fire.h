//
// Created by atenagm on 7/2/16.
//

#ifndef CLASH_ROYALE_FIRE_H
#define CLASH_ROYALE_FIRE_H


#include <QtCore/qobject.h>
#include <QtWidgets/qgraphicsitem.h>
#include "Specifications.h"
#include <QTimer>

class Fire : public QObject, public QGraphicsPixmapItem{

Q_OBJECT
    friend class Tower;
    friend class Card;

public:

    Fire(double, double, double, double, int);
    ~Fire();
    void shoot();

private:

    int bulType;
    double x1;
    double x2;
    double dx;
    double y1;
    double y2;
    double dy;
    double slope;
    bool isAlive;
    QTimer *timer;
    QPixmap *pic;

public slots:

    void changePosition();
};


#endif //CLASH_ROYALE_FIRE_H