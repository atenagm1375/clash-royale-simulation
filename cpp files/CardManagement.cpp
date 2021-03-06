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
    //this->setPos(200, 0);
    //scene->addItem(this);
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

    objects = new QList<Object *>();
}

CardManagement::~CardManagement()
{
    allCards.clear();
    myCardDeck.clear();
    objects->clear();
    delete objects;
    delete elixir;
    elixirTimer->stop();
    delete elixirTimer;
}

void CardManagement::incrementElixir()
{
    elixir->setValue(elixir->value() + 1);
}

void CardManagement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    bool canBePlaced = false;
    int i = getIndex(canBePlaced);

    if(canBePlaced){
        myCardDeck[4]->setPos(myCardDeck[i]->pos());
        scene->removeItem(myCardDeck[i]);
        scene->addItem(myCardDeck[4]);
        if(myCardDeck[i]->id == 11) {
            myCardDeck.swap(i, 7);
            spc::cardNo = myCardDeck[i]->id;
            getIndex(canBePlaced);
        }
        if(myCardDeck[i]->id == 6){
            for(int j = 0; j < myCardDeck[i]->count; j++){
                MinionHorde *m = new MinionHorde(QPixmap("sources/3.png"), timer);
                m->setPos(event->pos().x() - myCardDeck.at(i)->boundingRect().center().x() + 200 + 6 * (j - 3),
                          event->pos().y() - myCardDeck.at(i)->boundingRect().center().y() + 6 * (3 - j));
                m->setScale(0.6);
                scene->addItem(m);
                objects->push_back(m);
                allCards.push_back(m);
            }
        }
        else {
            myCardDeck[i]->setPos(event->pos().x() - myCardDeck.at(i)->boundingRect().center().x() + 200,
                                  event->pos().y() - myCardDeck.at(i)->boundingRect().center().y());
            myCardDeck[i]->setScale(0.6);
            scene->addItem(myCardDeck[i]);
            objects->push_back(myCardDeck[i]);
            allCards.push_back(myCardDeck[i]);
        }
        emit moveForward(i);
        myCardDeck.swap(i, 4);
        myCardDeck.removeAt(4);
    }
}
int CardManagement::getIndex(bool &canBePlaced)
{
    int i = 0;
    for( ; i < 4; i++) {
        if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 1) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new LavaHound(QPixmap("sources/1.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 2) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new IceWizard(QPixmap("sources/4.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 3) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new Balloon(QPixmap("sources/2.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 4) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new DarkPrince(QPixmap("sources/5.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 5) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new HogRider(QPixmap("sources/10.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 6) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new MinionHorde(QPixmap("sources/3.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 7) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new Valkyrie(QPixmap("sources/7.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 8) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new Miner(QPixmap("sources/6.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 9) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new Witch(QPixmap("sources/8.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 10) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new RoyalGiant(QPixmap("sources/9.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 11) {
            if (myCardDeck.back()->elixirCost + 1 <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck.back()->elixirCost - 1);
                //myCardDeck.push_back(new Mirror(QPixmap("sources/11.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 12) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new Zap(QPixmap("sources/12.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 13) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new Rage(QPixmap("sources/13.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 14) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new InfernoTower(QPixmap("sources/15.png"), timer));
                canBePlaced = true;
            }
            break;
        }
        else if (myCardDeck[i]->id == spc::cardNo && spc::cardNo == 15) {
            if (myCardDeck[i]->elixirCost <= elixir->value()) {
                elixir->setValue(elixir->value() - myCardDeck[i]->elixirCost);
                myCardDeck.push_back(new UsingFurnace(QPixmap("sources/14.png"), timer));
                canBePlaced = true;
            }
            break;
        }
    }
    return i;
}