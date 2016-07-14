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
    this->setPixmap(QPixmap("sources/grass1.jpg").scaled(800, 700));
    this->setPos(200, 0);
    scene->addItem(this);
    timer = new QTimer();
    acceptedMouseButtons();

    elixir = new QProgressBar();
    elixir->setOrientation(Qt::Orientation::Vertical);
    elixir->setTextDirection(QProgressBar::BottomToTop);
    elixir->setMinimum(0);
    elixir->setMaximum(10);
    elixir->setFormat("%v");
    elixir->setValue(5);
    elixir->setStyleSheet("::chunk {"
                                  "background-color: "
                                  "qlineargradient(x0: 0, x2: 1, "
                                  "stop: 0 red, stop: 0.3 red, "
                                  "stop: 0.3 magenta, "
                                  "stop: 0.7 cyan"
                                  ")}");
    elixir->setGeometry(160, 200, 40, 430);
    scene->addWidget(elixir);

    elixirTimer = new QTimer();
    connect(elixirTimer, SIGNAL(timeout()), this, SLOT(incrementElixir()));
    //elixirTimer->start(4500);

    QPixmap *px = new QPixmap(QPixmap("sources/myTower.png").scaled(150, 150));
    kingTower = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 90, 7, 7, px, timer);
    kingTower->setPos(520, 550);
    scene->addItem(kingTower);

    QPixmap *px1 = new QPixmap(QPixmap("sources/mainTower.png").scaled(150, 150));
    kingTowerE = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 90, 7, 7, px1, timer);
    kingTowerE->setPos(520, 0);
    scene->addItem(kingTowerE);

    QPixmap *px2 = new QPixmap(QPixmap("sources/arenaTower.png").scaled(100, 100));
    leftArenaTower = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px2, timer);
    leftArenaTower->setPos(340, 500);
    scene->addItem(leftArenaTower);

    rightArenaTower = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px2, timer);
    rightArenaTower->setPos(790, 500);
    scene->addItem(rightArenaTower);

    QPixmap *px3 = new QPixmap(QPixmap("sources/arenaTowerE.png").scaled(100, 100));
    leftArenaTowerE = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px3, timer);
    leftArenaTowerE->setPos(340, 100);
    scene->addItem(leftArenaTowerE);

    rightArenaTowerE = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px3, timer);
    rightArenaTowerE->setPos(790, 100);
    scene->addItem(rightArenaTowerE);
}

CardManagement::~CardManagement() { }

void CardManagement::incrementElixir()
{
    elixir->setValue(elixir->value() + 1);
}

void CardManagement::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    bool canBePlaced = false;
    int i = 0;
    for (i = 0; i < 4; i++)
        if (myCardDeck[i]->isSelected)
            break;
    if (spc::cardNo == 1) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new LavaHound(QPixmap("1.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 2) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new IceWizard(QPixmap("4.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 3) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new Balloon(QPixmap("2.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 4) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new DarkPrince(QPixmap("5.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 5) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new HogRider(QPixmap("10.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 6) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new MinionHorde(QPixmap("3.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 7) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new Valkyrie(QPixmap("7.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 8) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new Miner(QPixmap("6.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 9) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new Witch(QPixmap("8.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 10) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new RoyalGiant(QPixmap("9.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 11) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new Mirror(QPixmap("11.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 12) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new Zap(QPixmap("12.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 13) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new Rage(QPixmap("13.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 14) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new InfernoTower(QPixmap("15.png"), timer));
            canBePlaced = true;
        }
    }
    else if (spc::cardNo == 15) {
        if (myCardDeck[i]->elixirCost <= elixir->value()) {
            elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
            myCardDeck.push_back(new UsingFurnace(QPixmap("14.png"), timer));
            canBePlaced = true;
        }
    }

    if(!canBePlaced)
        myCardDeck[i]->isSelected = false;
    if(myCardDeck[i]->isSelected && canBePlaced){
        myCardDeck[i]->isSelected = false;
        myCardDeck[4]->setPos(myCardDeck[i]->pos());
        scene->removeItem(myCardDeck[i]);
        scene->addItem(myCardDeck[4]);
        myCardDeck[i]->setPos(event->pos().x() - myCardDeck.at(i)->boundingRect().center().x() + 200,
                              event->pos().y() - myCardDeck.at(i)->boundingRect().center().y());
        scene->addItem(myCardDeck[i]);
        myCardDeck.swap(i, 4);
        myCardDeck.removeAt(4);
    }
}