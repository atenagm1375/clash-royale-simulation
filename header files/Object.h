//
// Created by atenagm on 7/3/16.
//

#ifndef CLASH_ROYALE_OBJECT_H
#define CLASH_ROYALE_OBJECT_H


#include <QtWidgets/qgraphicsitem.h>

class Object : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT
    friend class map1;

public:

    Object();
    Object(int, int, double, int, int, double, double, QTimer *);
    ~Object();

protected:

    int type;
    int target;
    double hitSpeed;
    int hitPoints;
    int damage;
    double range;
    double territory;
    bool isMyTeam;
};


#endif //CLASH_ROYALE_OBJECT_H
