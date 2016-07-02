//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_MAP1_H
#define CLASH_ROYALE_MAP1_H


#include <QtWidgets/qgraphicsview.h>
#include <QGraphicsPixmapItem>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qprogressbar.h>

class map1 : public QGraphicsView{

    Q_OBJECT
    friend class MainWindow;

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
    QLabel *enemyScore;
    QLabel *myScore;
    QPushButton *pause;
    QLabel *card[4];
    QLabel *timeLabel;
    QProgressBar *elixir;
};


#endif //CLASH_ROYALE_MAP1_H
