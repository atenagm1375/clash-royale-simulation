//
// Created by atenagm on 7/1/16.
//

#include <header files/map2.h>
#include <QScrollBar>
#include <header files/Specifications.h>

map2::map2(QWidget *parent) : QGraphicsView(parent)
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
    cm->setPixmap(QPixmap("sources/grass1.jpg").scaled(800, 700));
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
    for(int i = 0; i < 4; i++)
        bridge[i] = new QGraphicsPixmapItem();
    for(int i = 0; i < 4; i++)
        bridge[i]->setPixmap(bridgePxmp.scaled(60, 100));
    bridge[0]->setPos(275, 300);
    bridge[1]->setPos(400, 300);
    bridge[2]->setPos(730, 300);
    bridge[3]->setPos(855, 300);
    for(int i = 0; i < 4; i++)
        scene.addItem(bridge[i]);

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
    card[0]->setGeometry(20, 200, 80, 100);
    card[1]->setGeometry(20, 310, 80, 100);
    card[2]->setGeometry(20, 420, 80, 100);
    card[3]->setGeometry(20, 530, 80, 100);
    for(int i = 0; i < 4; i++)
        scene.addWidget(card[i]);

    timeLabel = new QLabel();
    timeLabel->setGeometry(1000, 450, 200, 50);
    scene.addWidget(timeLabel);

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
    scene.addWidget(elixir);

    elixirTimer = new QTimer();
    connect(elixirTimer, SIGNAL(timeout()), this, SLOT(incrementElixir()));
    elixirTimer->start(5000);

    QPixmap *px = new QPixmap(QPixmap("sources/myTower.png").scaled(150, 150));
    kingTower = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px, elixirTimer);
    kingTower->setPos(520, 550);
    scene.addItem(kingTower);

    QPixmap *px1 = new QPixmap(QPixmap("sources/mainTower.png").scaled(150, 150));
    kingTowerE = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px1, elixirTimer);
    kingTowerE->setPos(520, 0);
    scene.addItem(kingTowerE);

    QPixmap *px2 = new QPixmap(QPixmap("sources/arenaTower.png").scaled(100, 100));
    leftTower1 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px2, elixirTimer);
    leftTower1->setPos(270, 500);
    scene.addItem(leftTower1);

    leftTower2 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px2, elixirTimer);
    leftTower2->setPos(390, 500);
    scene.addItem(leftTower2);

    rightTower1 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px2, elixirTimer);
    rightTower1->setPos(710, 500);
    scene.addItem(rightTower1);

    rightTower2 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px2, elixirTimer);
    rightTower2->setPos(840, 500);
    scene.addItem(rightTower2);

    QPixmap *px3 = new QPixmap(QPixmap("sources/arenaTowerE.png").scaled(100, 100));
    leftTowerE1 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px3, elixirTimer);
    leftTowerE1->setPos(270, 100);
    scene.addItem(leftTowerE1);

    leftTowerE2 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px3, elixirTimer);
    leftTowerE2->setPos(390, 100);
    scene.addItem(leftTowerE2);

    rightTowerE1 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px3, elixirTimer);
    rightTowerE1->setPos(710, 100);
    scene.addItem(rightTowerE1);

    rightTowerE2 = new Tower(spc::Type::BUILDING , spc::Target::AirGround, 1.5, 4000, 100, 400, 450, px3, elixirTimer);
    rightTowerE2->setPos(840, 100);
    scene.addItem(rightTowerE2);

    this->verticalScrollBar()->blockSignals(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->horizontalScrollBar()->blockSignals(true);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->update();
    this->show();
}

map2::~map2() { }

void map2::incrementElixir()
{
    elixir->setValue(elixir->value() + 1);
}