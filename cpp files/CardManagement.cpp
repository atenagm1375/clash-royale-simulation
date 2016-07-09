//
// Created by atenagm on 7/5/16.
//

#include <header files/CardManagement.h>
#include <iostream>
//#include <iostream>

CardManagement::CardManagement(QGraphicsScene *s) : scene(s)
{
    setPixmap(QPixmap("sources/grass1.jpg").scaled(800, 700));
    acceptedMouseButtons();
}

CardManagement::~CardManagement() { }

void CardManagement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int i = 0;
    bool t = true;
    for( ; t && i < 4; i++)
        if(myCardDeck[i]->isSelected)
            t = false;
    i--;
    if(!t) {
        myCardDeck[i]->isSelected = false;
        myCardDeck[4]->setPos(myCardDeck[i]->pos());
        scene->removeItem(myCardDeck.at(i));
        scene->addItem(myCardDeck[4]);
        myCardDeck.at(i)->setPos(event->pos().x() - myCardDeck.at(i)->boundingRect().center().x() + 200,
                                 event->pos().y() - myCardDeck.at(i)->boundingRect().center().y());
        scene->addItem((QGraphicsItem *) myCardDeck.at(i));

        myCardDeck.push_back(myCardDeck[i]);
        myCardDeck.swap(i, 4);
        myCardDeck.removeAt(4);
    }
}