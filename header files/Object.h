//
// Created by atenagm on 7/3/16.
//

#ifndef CLASH_ROYALE_OBJECT_H
#define CLASH_ROYALE_OBJECT_H


#include <QtWidgets/qgraphicsitem.h>

class Object : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:

    Object(int, int, double, int, int, double, int, QTimer *);
    ~Object();

private:

    int type;
    int target;
    double hitSpeed;
    int hitPoints;
    int damage;
    double range;
    int territory;
};


#endif //CLASH_ROYALE_OBJECT_H
