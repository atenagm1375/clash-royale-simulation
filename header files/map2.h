//
// Created by atenagm on 7/1/16.
//

#ifndef CLASH_ROYALE_MAP2_H
#define CLASH_ROYALE_MAP2_H


#include <QtWidgets/qgraphicsview.h>
#include <QGraphicsPixmapItem>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qprogressbar.h>
#include <QTimer>
#include "Tower.h"
#include "CardManagement.h"

class map2 : public QGraphicsView{

    Q_OBJECT
    friend class MainWindow;

public:

    map2(QWidget * = 0);
    ~map2();

private:

    QGraphicsScene scene;
    CardManagement *cm;
    QGraphicsPixmapItem *stone;
    QGraphicsPixmapItem *river;
    QGraphicsPixmapItem *bridge[4];
    QLabel *enemyScore;
    QLabel *myScore;
    QPushButton *pause;
    QLabel *card[4];
    QLabel *timeLabel;
    QProgressBar *elixir;
    QTimer *elixirTimer;
    Tower *kingTower;
    Tower *kingTowerE;
    Tower *leftTower1;
    Tower *leftTower2;
    Tower *rightTower1;
    Tower *rightTower2;
    Tower *rightTowerE1;
    Tower *rightTowerE2;
    Tower *leftTowerE1;
    Tower *leftTowerE2;

public slots:

    void incrementElixir();
};


#endif //CLASH_ROYALE_MAP2_H
