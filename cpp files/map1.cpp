//
// Created by atenagm on 6/30/1

#include <header files/map1.h>

map1::map1(::map1::QWidget *parent) : QGraphicsView(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);
    this->setSceneRect(0, 0, 1200, 700);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAlignment(Qt::AlignCenter);

    scene.setSceneRect(0, 0, 1200, 700);
    scene.setBackgroundBrush(Qt::darkMagenta);
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
}

map1::~map1() { }