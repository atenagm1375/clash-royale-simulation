//
// Created by atenagm on 7/1/16.
//

#include <header files/PausePage.h>
#include <QtGui/qpainter.h>

PausePage::PausePage(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);

    QPalette palet(palette());
    QPixmap p("sources/blue1.jpg");
    palet.setBrush(QPalette::Background, QBrush(Qt::white, p.scaled(1200, 700)));
    this->setAutoFillBackground(true);
    this->setPalette(palet);

    pauseLabel = new QLabel("P A U S E", this);
    pauseLabel->setFont(QFont("serif", 50, QFont::Bold));
    pauseLabel->setGeometry(410, 300, 400, 100);
    pauseLabel->setStyleSheet("QLabel {color:cyan;}");

    quit = new QPushButton("QUIT", this);
    quit->setFont(QFont("serif", 25, QFont::Bold));
    quit->setGeometry(1000, 20, 150, 40);

    setting = new QPushButton("SETTINGS", this);
    setting->setGeometry(50, 20, 200, 40);
    setting->setFont(QFont("serif", 25, QFont::Bold));

    backToGame = new QPushButton("BACK TO GAME", this);
    backToGame->setFont(QFont("serif", 25, QFont::Bold));
    backToGame->setGeometry(400, 600, 400, 50);
}

PausePage::~PausePage() { }