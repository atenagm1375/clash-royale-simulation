//
// Created by atenagm on 6/30/1

#include <header files/map1.h>
#include <QScrollBar>

map1::map1(::map1::QWidget *parent) : QGraphicsView(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);
    this->setSceneRect(0, 0, 1200, 700);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAlignment(Qt::AlignCenter);

    scene.setSceneRect(0, 0, 1200, 700);
    QImage img("sources/background2.jpg");
    QPixmap pic;
    pic.convertFromImage(img.scaled(1200, 700));
    scene.setBackgroundBrush(pic);
    this->setScene(&scene);

    QImage grassImg("sources/grass1.jpg");
    QPixmap grassPxmp;
    grassPxmp.convertFromImage(grassImg.scaled(800, 700));
    grass = new QGraphicsPixmapItem();
    grass->setPixmap(grassPxmp);
    grass->setPos(200, 0);
    scene.addItem(grass);

    QImage stoneImg("sources/stone.jpg");
    QPixmap stonePxmp;
    stonePxmp.convertFromImage(stoneImg.scaled(800, 80));
    stone = new QGraphicsPixmapItem();
    stone->setPixmap(stonePxmp);
    stone->setPos(200, 310);
    scene.addItem(stone);

    QImage riverImg("sources/river-hi.png");
    QPixmap riverPxmp;
    riverPxmp.convertFromImage(riverImg.scaled(800, 60));
    river = new QGraphicsPixmapItem();
    river->setPixmap(riverPxmp);
    river->setPos(200, 320);
    scene.addItem(river);

    QImage bridgeImg("sources/wooden_plank_bridge7.png");
    QPixmap bridgePxmp;
    bridgePxmp.convertFromImage(bridgeImg.scaled(60, 100));
    bridge1 = new QGraphicsPixmapItem();
    bridge1->setPixmap(bridgePxmp);
    bridge1->setPos(350, 300);
    scene.addItem(bridge1);

    bridge2 = new QGraphicsPixmapItem();
    bridge2->setPixmap(bridgePxmp);
    bridge2->setPos(800, 300);
    scene.addItem(bridge2);

    enemyScore = new QLabel("0");
    enemyScore->setFont(QFont("serif", 25, QFont::Bold));
    enemyScore->setGeometry(50, 100, 25, 50);
    enemyScore->setStyleSheet("QLabel { background : red; }");
    scene.addWidget(enemyScore);

    myScore = new QLabel("0");
    myScore->setFont(QFont("serif", 25, QFont::Bold));
    myScore->setGeometry(1100, 100, 25, 50);
    myScore->setStyleSheet("QLabel { background : cyan; }");
    scene.addWidget(myScore);

    pause = new QPushButton("PAUSE");
    pause->setFont(QFont("serif", 25, QFont::Bold));
    pause->setGeometry(1000, 325, 200, 50);
    scene.addWidget(pause);

    for(int i = 0; i < 4; i++)
        card[i] = new QLabel();
    card[0]->setGeometry(1000, 450, 100, 50);
    card[1]->setGeometry(1100, 450, 100, 50);
    card[2]->setGeometry(1000, 550, 100, 50);
    card[3]->setGeometry(1100, 550, 100, 50);
    for(int i = 0; i < 4; i++)
        scene.addWidget(card[i]);

    QImage im("sources/king.png");
    QPixmap px;
    px.convertFromImage(im.scaled(200, 250));
    QGraphicsPixmapItem *king = new QGraphicsPixmapItem();
    king->setPixmap(px);
    king->setPos(0, 450);
    scene.addItem(king);

    this->verticalScrollBar()->blockSignals(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->horizontalScrollBar()->blockSignals(true);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->update();
    this->show();
}

map1::~map1() { }