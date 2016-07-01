//
// Created by atenagm on 6/25/16.
//

#include "header files/FirstPage.h"

FirstPage::FirstPage(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);

    QPalette palet(palette());
    QImage img("sources/clashroyale.jpg");
    QPixmap p;
    p.convertFromImage(img.scaled(1200, 700));
    palet.setBrush(QPalette::Background, QBrush(Qt::white, p));
    this->setAutoFillBackground(true);
    this->setPalette(palet);

    start = new QPushButton("LET'S PLAY!", this);
    exit = new QPushButton("EXIT", this);
    setting = new QPushButton("Settings", this);

    start->setGeometry(400, 600, 400, 60);
    start->setFont(QFont("serif", 30, QFont::Bold));

    exit->setGeometry(1000, 20, 150, 40);
    exit->setFont(QFont("serif", 25, QFont::Bold));

    setting->setGeometry(50, 20, 200, 40);
    setting->setFont(QFont("serif", 25, QFont::Bold));
}

FirstPage::~FirstPage() { }