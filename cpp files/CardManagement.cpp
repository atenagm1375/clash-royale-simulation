//
// Created by atenagm on 7/5/16.
//

#include <header files/CardManagement.h>
#include <header files/LavaHound.h>
#include <header files/IceWizard.h>
#include <header files/Balloon.h>
#include <header files/DarkPrince.h>
#include <header files/HogRider.h>
#include <header files/MinionHorde.h>
#include <header files/Valkyrie.h>
#include <header files/Miner.h>
#include <header files/Witch.h>
#include <header files/RoyalGiant.h>
#include <header files/Mirror.h>
#include <header files/Zap.h>
#include <header files/Rage.h>
#include <header files/InfernoTower.h>
#include <header files/UsingFurnace.h>
#include <iostream>

CardManagement::CardManagement(QGraphicsScene *s) : scene(s)
{
    setPixmap(QPixmap("sources/grass1.jpg").scaled(800, 700));
    timer = new QTimer();
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

        if(event->pos().y() > 400)
            myCardDeck.at(i)->setPos(event->pos().x() - myCardDeck.at(i)->boundingRect().center().x() + 200,
                                     event->pos().y() - myCardDeck.at(i)->boundingRect().center().y());
        else
            myCardDeck.at(i)->setPos(event->pos().x() - myCardDeck.at(i)->boundingRect().center().x() + 200,
                                     400 - myCardDeck.at(i)->boundingRect().center().y());
        myCardDeck[i]->pixmap().scaled(20, 20);
        scene->addItem(myCardDeck.at(i));

        //std::cout << spc::cardNo << std::endl;
        if(spc::cardNo == 1)
            myCardDeck.push_back(new LavaHound(QPixmap("1.png"), timer));
        else if(spc::cardNo == 2)
            myCardDeck.push_back(new IceWizard(QPixmap("4.png"), timer));
        else if(spc::cardNo == 3)
            myCardDeck.push_back(new Balloon(QPixmap("2.png"), timer));
        else if(spc::cardNo == 4)
            myCardDeck.push_back(new DarkPrince(QPixmap("5.png"), timer));
        else if(spc::cardNo == 5)
            myCardDeck.push_back(new HogRider(QPixmap("10.png"), timer));
        else if(spc::cardNo == 6)
            myCardDeck.push_back(new MinionHorde(QPixmap("3.png"), timer));
        else if(spc::cardNo == 7)
            myCardDeck.push_back(new Valkyrie(QPixmap("7.png"), timer));
        else if(spc::cardNo == 8)
            myCardDeck.push_back(new Miner(QPixmap("6.png"), timer));
        else if(spc::cardNo == 9)
            myCardDeck.push_back(new Witch(QPixmap("8.png"), timer));
        else if(spc::cardNo == 10)
            myCardDeck.push_back(new RoyalGiant(QPixmap("9.png"), timer));
        else if(spc::cardNo == 11)
            myCardDeck.push_back(new Mirror(QPixmap("11.png"), timer));
        else if(spc::cardNo == 12)
            myCardDeck.push_back(new Zap(QPixmap("12.png"), timer));
        else if(spc::cardNo == 13)
            myCardDeck.push_back(new Rage(QPixmap("13.png"), timer));
        else if(spc::cardNo == 14)
            myCardDeck.push_back(new InfernoTower(QPixmap("15.png"), timer));
        else if(spc::cardNo == 15)
            myCardDeck.push_back(new UsingFurnace(QPixmap("14.png"), timer));
        //scene->addItem(myCardDeck.at(8));

        myCardDeck.swap(i, 4);
        myCardDeck.removeAt(4);
        //std::cout << myCardDeck.size() << std::endl;
    }
}