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
    QPixmap pic("sources/background2.jpg");
    scene.setBackgroundBrush(pic.scaled(1200, 700));
    this->setScene(&scene);

    QPixmap grassPxmp("sources/grass1.jpg");
    grass = new QGraphicsPixmapItem();
    grass->setPixmap(grassPxmp.scaled(800, 700));
    grass->setPos(200, 0);
    scene.addItem(grass);

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

    this->verticalScrollBar()->blockSignals(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->horizontalScrollBar()->blockSignals(true);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->update();
    this->show();
}

map1::~map1() { }

void map1::incrementElixir()
{
    elixir->setValue(elixir->value() + 1);
}