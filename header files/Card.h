//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_CARD_H
#define CLASH_ROYALE_CARD_H


#include <QtWidgets/qwidget.h>
#include <QTimer>
#include "Object.h"
#include "Specifications.h"

class Card : public Object{

    Q_OBJECT

public:

    //Card();
    Card(int, int, double, int, int, double, double, int, int, int, double, QTimer *);
    ~Card();
    //void mousePressEvent(QGraphicsSceneMouseEvent *);
    bool isSelected;

protected:

    int speed;
    int elixirCost;
    int count;
    double deployTime;
};


#endif //CLASH_ROYALE_CARD_H
