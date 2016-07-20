//
// Created by atenagm on 6/30/1

#include <header files/map1.h>
#include <QScrollBar>
#include "header files/Specifications.h"


map1::map1(::map1::QWidget *parent) : QGraphicsView(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);
    this->setSceneRect(0, 0, 1200, 700);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAlignment(Qt::AlignCenter);

    scene.setSceneRect(0, 0, 1200, 700);
    QPixmap pic("sources/background2.jpg");
    scene.setBackgroundBrush(pic.scaled(1200, 700));
    this->setScene(&scene);

    cm = new CardManagement(&scene);
    cm->setPos(200, 0);
    scene.addItem(cm);

    QPixmap stonePxmp("sources/379 copy.jpg");
    stone = new QGraphicsPixmapItem();
    stone->setPixmap(stonePxmp.scaled(800, 80));
    stone->setPos(200, 310);
    scene.addItem(stone);

    QPixmap riverPxmp("sources/river-hi.png");
    river = new QGraphicsPixmapItem();
    river->setPixmap(riverPxmp.scaled(800, 60));
    river->setPos(200, 320);
    scene.addItem(river);

    QPixmap bridgePxmp("sources/wooden_plank_bridge7.png");
    bridge1 = new QGraphicsPixmapItem();
    bridge1->setPixmap(bridgePxmp.scaled(60, 100));
    bridge1->setPos(350, 300);
    scene.addItem(bridge1);

    bridge2 = new QGraphicsPixmapItem();
    bridge2->setPixmap(bridgePxmp.scaled(60, 100));
    bridge2->setPos(800, 300);
    scene.addItem(bridge2);

    enemyScoreValue = 0;
    enemyScore = new QLabel();
    enemyScore->setFont(QFont("serif", 25, QFont::Bold));
    enemyScore->setGeometry(50, 100, 25, 50);
    enemyScore->setStyleSheet("QLabel { background : red; }");
    enemyScore->setNum(enemyScoreValue);
    scene.addWidget(enemyScore);

    myScoreValue = 0;
    myScore = new QLabel();
    myScore->setFont(QFont("serif", 25, QFont::Bold));
    myScore->setGeometry(1100, 100, 25, 50);
    myScore->setStyleSheet("QLabel { background : cyan; }");
    myScore->setNum(myScoreValue);
    scene.addWidget(myScore);

    pause = new QPushButton("PAUSE");
    pause->setFont(QFont("serif", 25, QFont::Bold));
    pause->setGeometry(1000, 325, 200, 50);
    scene.addWidget(pause);

    for(int i = 0; i < 4; i++)
        card[i] = new QLabel();
    card[0]->setGeometry(20, 200, 80, 100);
    card[1]->setGeometry(20, 310, 80, 100);
    card[2]->setGeometry(20, 420, 80, 100);
    card[3]->setGeometry(20, 530, 80, 100);
    for(int i = 0; i < 4; i++) {
        card[i]->setStyleSheet("QLabel { background : #DE6641; }");
        scene.addWidget(card[i]);
    }

    timeLabel = new QLabel();
    timeLabel->setGeometry(1000, 450, 200, 50);
    scene.addWidget(timeLabel);

    isFinished = false;
    second = 180;
    isExtraTime = false;
    setTime();
    gameTimer = new QTimer();
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(timeManagement()));

    QPixmap *px = new QPixmap(QPixmap("sources/myTower.png").scaled(150, 150));
    kingTower = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 90, 7, 7, px, timer);
    kingTower->isMyTeam = true;
    kingTower->isKingTower = true;
    kingTower->initialization(cm->objects, &scene);
    kingTower->setPos(520, 550);
    scene.addItem(kingTower);

    QPixmap *px1 = new QPixmap(QPixmap("sources/mainTower.png").scaled(150, 150));
    kingTowerE = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 90, 7, 7, px1, timer);
    kingTowerE->isMyTeam = false;
    kingTowerE->isKingTower = true;
    kingTowerE->initialization(cm->objects, &scene);
    kingTowerE->setPos(520, 0);
    scene.addItem(kingTowerE);

    QPixmap *px2 = new QPixmap(QPixmap("sources/arenaTower.png").scaled(100, 100));
    leftArenaTower = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px2, timer);
    leftArenaTower->isMyTeam = true;
    leftArenaTower->initialization(cm->objects, &scene);
    leftArenaTower->setPos(340, 500);
    scene.addItem(leftArenaTower);

    rightArenaTower = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px2, timer);
    rightArenaTower->isMyTeam = true;
    rightArenaTower->initialization(cm->objects, &scene);
    rightArenaTower->setPos(790, 500);
    scene.addItem(rightArenaTower);

    QPixmap *px3 = new QPixmap(QPixmap("sources/arenaTowerE.png").scaled(100, 100));
    leftArenaTowerE = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px3, timer);
    leftArenaTowerE->isMyTeam = false;
    leftArenaTowerE->initialization(cm->objects, &scene);
    leftArenaTowerE->setPos(340, 100);
    scene.addItem(leftArenaTowerE);

    rightArenaTowerE = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 2000, 60, 7.5, 7.5, px3, timer);
    rightArenaTowerE->isMyTeam = false;
    rightArenaTowerE->initialization(cm->objects, &scene);
    rightArenaTowerE->setPos(790, 100);
    scene.addItem(rightArenaTowerE);

    cm->objects->push_back(kingTower);
    cm->objects->push_back(kingTowerE);
    cm->objects->push_back(leftArenaTower);
    cm->objects->push_back(rightArenaTower);
    cm->objects->push_back(leftArenaTowerE);
    cm->objects->push_back(rightArenaTowerE);

    this->verticalScrollBar()->blockSignals(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->horizontalScrollBar()->blockSignals(true);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(cm, SIGNAL(moveForward(int)), this, SLOT(go(int)));

    this->update();
    this->show();
}

map1::~map1() { }

void map1::arrangeCardDeck()
{
    for(int i = 0; i < 4; i++) {
        cm->myCardDeck.at(i)->setPos(card[i]->pos().x(), card[i]->pos().y() + 10);
        scene.addItem(cm->myCardDeck[i]);
    }
}

void map1::timeManagement()
{
    if(!isFinished){
        second--;
        setTime();
        for(int i = 0; i < cm->objects->size(); i++)
            if(!cm->objects->at(i)->isAlive){
                if(dynamic_cast<Tower *>(cm->objects->at(i)) != NULL &&
                        dynamic_cast<Tower *>(cm->objects->at(i))->isKingTower){
                    if(cm->objects->at(i)->isMyTeam){
                        enemyScoreValue += 2;
                        enemyScore->setNum(enemyScoreValue);
                    }
                    else{
                        myScoreValue += 2;
                        myScore->setNum(myScoreValue);
                    }
                }
                else if(dynamic_cast<Tower *>(cm->objects->at(i)) != NULL){
                    if(cm->objects->at(i)->isMyTeam){
                        enemyScoreValue++;
                        enemyScore->setNum(enemyScoreValue);
                    }
                    else {
                        myScoreValue++;
                        myScore->setNum(myScoreValue);
                    }
                }
                delete cm->objects->at(i);
                cm->objects->removeAt(i);
            }
        if(second == 0){
            if(!isExtraTime && myScore->text() == enemyScore->text()) {
                second = 60;
                isExtraTime = true;
            }
            else {
                isFinished = true;
                gameTimer->stop();
                cm->elixirTimer->stop();
            }
        }
    }
}

void map1::setTime()
{
    int min = second / 60;
    int sec = second % 60;
    QString m;
    m.setNum(min);
    QString s;
    s.setNum(sec);
    if(sec < 10)
        s = "0" + s;
    timeLabel->setText(m + " : " + s);
    timeLabel->setFont(QFont("serif", 30));
    timeLabel->setAlignment(Qt::AlignCenter);
}

void map1::go(int i)
{
    for(int j = 0; j < cm->myCardDeck[i]->count; j++) {
        cm->allCards[cm->allCards.size() - 1 - j]->initialization(cm->objects, &scene);
        connect(this, SIGNAL(moveCall()), cm->allCards[cm->allCards.size() - 1 - j], SLOT(moveControl()));
        emit moveCall();
    }
}