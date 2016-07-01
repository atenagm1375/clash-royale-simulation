//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_MAP1_H
#define CLASH_ROYALE_MAP1_H


#include <QtWidgets/qgraphicsview.h>
#include <QGraphicsPixmapItem>

class map1 : public QGraphicsView{

    Q_OBJECT

public:

    map1(QWidget * = 0);
    ~map1();

private:

    QGraphicsScene scene;
    QGraphicsPixmapItem *grass;
    QGraphicsPixmapItem *stone;
    QGraphicsPixmapItem *river;
    QGraphicsPixmapItem *bridge1;
    QGraphicsPixmapItem *bridge2;
};


#endif //CLASH_ROYALE_MAP1_H
