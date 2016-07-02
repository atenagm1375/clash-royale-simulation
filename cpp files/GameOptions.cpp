//
// Created by atenagm on 6/26/16.
//

#include "header files/GameOptions.h"

GameOptions::GameOptions(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);

    QPalette palet(palette());
    QPixmap p("sources/blue1.jpg");
    palet.setBrush(QPalette::Background, QBrush(Qt::white, p.scaled(1200, 700)));
    this->setAutoFillBackground(true);
    this->setPalette(palet);

    nameLabel = new QLabel("NAME :", this);
    nameLabel->setFont(QFont("serif", 25, QFont::Bold));
    nameLabel->setStyleSheet("QLabel { color : cyan; }");
    nameLabel->setGeometry(150, 100, 150, 40);

    nameEditor = new QLineEdit("PLAYER", this);
    nameEditor->setFont(QFont("serif", 20));
    nameEditor->setGeometry(450, 100, 500, 40);
    nameEditor->setMaxLength(20);

    gameMode = new QLabel("GAME MODE :", this);
    gameMode->setFont(QFont("serif", 25, QFont::Bold));
    gameMode->setStyleSheet("QLabel { color : cyan; }");
    gameMode->setGeometry(150, 250, 300, 40);

    vsComputer = new QRadioButton("VS. COMPUTER", this);
    vsComputer->setFont(QFont("serif", 20, QFont::Bold));
    vsComputer->setGeometry(450, 250, 300, 40);
    vsComputer->setAutoExclusive(true);
    vsComputer->setChecked(true);

    online = new QRadioButton("ONLINE", this);
    online->setFont(QFont("serif", 20, QFont::Bold));
    online->setGeometry(750, 250, 250, 40);
    online->setAutoExclusive(true);
    online->setChecked(false);

    QButtonGroup *bg = new QButtonGroup;
    bg->addButton(vsComputer);
    bg->addButton(online);

    back = new QPushButton("BACK", this);
    back->setFont(QFont("serif", 25, QFont::Bold));
    back->setGeometry(1000, 20, 150, 40);

    start = new QPushButton("START", this);
    start->setFont(QFont("serif", 25, QFont::Bold));
    start->setGeometry(500, 600, 200, 60);

    picture = new QLabel(this);
    picture->setPixmap(QPixmap("sources/king.png"));
    picture->setGeometry(800, 300, 400, 400);
    picture->setAttribute(Qt::WA_TranslucentBackground);

    picture1 = new QLabel(this);
    picture1->setPixmap(QPixmap("sources/Clash_Royale_Logo.png").scaled(500, 200));
    picture1->setGeometry(350, 350, 500, 200);
    picture1->setAttribute(Qt::WA_TranslucentBackground);

    picture2 = new QLabel(this);
    picture2->setPixmap(QPixmap("sources/Blue_Prince_Charge.png").scaled(300, 450));
    picture2->setGeometry(50, 250, 300, 450);
    picture2->setAttribute(Qt::WA_TranslucentBackground);
}

GameOptions::~GameOptions() { }