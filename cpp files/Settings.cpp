//
// Created by atenagm on 6/25/16.
//

#include "header files/Settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1200, 630);
    this->setGeometry(20, 20, 1200, 630);

    QPalette pal(palette());
    QRadialGradient gradient(600, 315, 400);
    gradient.setColorAt(0, Qt::blue);
    gradient.setColorAt(1, Qt::darkBlue);
    pal.setBrush(QPalette::Background, gradient);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    settingLabel = new QLabel("SETTINGS", this);
    settingLabel->setGeometry(450, 20, 400, 60);
    settingLabel->setFont(QFont("serif", 30, QFont::ExtraBold));
    settingLabel->setStyleSheet("QLabel { color : cyan; }");

    back = new QPushButton("BACK", this);
    back->setGeometry(1000, 20, 150, 40);
    back->setFont(QFont("serif", 25, QFont::Bold));

    volumeLabel = new QLabel("VOLUME", this);
    volumeLabel->setFont(QFont("serif", 25, QFont::Bold));
    volumeLabel->setGeometry(500, 450, 200, 40);
    volumeLabel->setStyleSheet("QLabel { color : white; }");

    volume = new QSlider(Qt::Horizontal, this);
    volume->setGeometry(20, 500, 1000, 50);
    volume->setTickPosition(QSlider::TicksBothSides);
    volume->setSliderPosition(50);
    volume->setTracking(true);

    mute = new QCheckBox("MUTE", this);
    mute->setGeometry(1040, 500, 150, 50);
    mute->setFont(QFont("serif", 20, QFont::Bold));

    music = new QLabel("MUSIC", this);
    music->setGeometry(100, 275, 200, 40);
    music->setFont(QFont("serif", 25, QFont::Bold));
    music->setStyleSheet("QLabel { color : darkMagenta; }");

    music1 = new QRadioButton("music No.1", this);
    music2 = new QRadioButton("music No.2", this);
    music1->setAutoExclusive(true);
    music2->setAutoExclusive(true);
    music1->setFont(QFont("serif", 20));
    music2->setFont(QFont("serif", 20));
    music1->setChecked(true);
    music2->setChecked(false);

    QButtonGroup *bg = new QButtonGroup;
    bg->addButton(music1);
    bg->addButton(music2);
    music1->setGeometry(400, 275, 400, 40);
    music2->setGeometry(800, 275, 400, 40);
}

Settings::~Settings() { }