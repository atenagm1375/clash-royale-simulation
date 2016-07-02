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

class map2 : public QGraphicsView{

    Q_OBJECT
    friend class MainWindow;

public:

    map2(QWidget * = 0);
    ~map2();

private:

    QGraphicsScene scene;
    QGraphicsPixmapItem *grass;
    QGraphicsPixmapItem *stone;
    QGraphicsPixmapItem *river;
    QGraphicsPixmapItem *bridge[4];
    QLabel *enemyScore;
    QLabel *myScore;
    QPushButton *pause;
    QLabel *card[4];
    QLabel *timeLabel;
    QProgressBar *elixir;
};


#endif //CLASH_ROYALE_MAP2_H
