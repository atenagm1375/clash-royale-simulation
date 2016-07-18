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
#include <QtCore/qtimer.h>
#include "Tower.h"
#include "CardManagement.h"

class map1 : public QGraphicsView{

    Q_OBJECT
    friend class MainWindow;
    friend class CardManagement;

public:

    map1(QWidget * = 0);
    ~map1();
    void arrangeCardDeck();

private:

    bool isFinished;
    int second;
    bool isExtraTime;
    QGraphicsScene scene;
    CardManagement *cm;
    QGraphicsPixmapItem *stone;
    QGraphicsPixmapItem *river;
    QGraphicsPixmapItem *bridge1;
    QGraphicsPixmapItem *bridge2;
    QLabel *enemyScore;
    QLabel *myScore;
    QPushButton *pause;
    QLabel *card[4];
    QLabel *timeLabel;
    QTimer *gameTimer;
    QTimer *timer;
    Tower *kingTower;
    Tower *kingTowerE;
    Tower *leftArenaTower;
    Tower *rightArenaTower;
    Tower *rightArenaTowerE;
    Tower *leftArenaTowerE;
    void setTime();

public slots:

    void timeManagement();
    void go(int);

    signals:

    void moveCall();
};


#endif //CLASH_ROYALE_MAP1_H
