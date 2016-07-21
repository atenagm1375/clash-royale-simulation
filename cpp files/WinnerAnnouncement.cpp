//
// Created by atenagm on 7/21/16.
//

#include <header files/WinnerAnnouncement.h>

WinnerAnnouncement::WinnerAnnouncement(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);

    QPalette palet(palette());
    QPixmap p("sources/gameOver.jpg");
    palet.setBrush(QPalette::Background, QBrush(Qt::white, p.scaled(1200, 700)));
    this->setAutoFillBackground(true);
    this->setPalette(palet);

    message = new QLabel(this);
    message->setFont(QFont("serif", 40, QFont::Bold));
    message->setGeometry(300, 100, 600, 50);
    message->setAlignment(Qt::AlignCenter);
    message->setStyleSheet("QLabel { color : cyan; }");

    quit = new QPushButton("QUIT", this);
    quit->setFont(QFont("serif", 25, QFont::Bold));
    quit->setGeometry(750, 600, 300, 40);

    continueB = new QPushButton("CONTINUE", this);
    continueB->setFont(QFont("serif", 25, QFont::Bold));
    continueB->setGeometry(150, 600, 300, 40);
}

WinnerAnnouncement::~WinnerAnnouncement() { }