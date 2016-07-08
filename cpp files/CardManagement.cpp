//
// Created by atenagm on 7/5/16.
//

#include <header files/CardManagement.h>
//#include <iostream>
//#include <header files/Window.h>

CardManagement::CardManagement(QGraphicsScene *s) : scene(s)
{
    setPixmap(QPixmap("sources/grass1.jpg").scaled(800, 700));
    acceptedMouseButtons();
}

CardManagement::~CardManagement() { }

void CardManagement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Window w;
    myCardDeck.at(0)->setPos(event->pos().x() - myCardDeck.at(0)->boundingRect().center().x() + 200,
                          event->pos().y() - myCardDeck.at(0)->boundingRect().center().y());
    scene->addItem((QGraphicsItem *) myCardDeck.at(0));
}