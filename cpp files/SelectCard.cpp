//
// Created by atenagm on 6/29/16.
//

#include <header files/SelectCard.h>
#include <QtGui/qpainter.h>

SelectCard::SelectCard(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);

    QPalette pal(palette());
    QRadialGradient gradient(600, 315, 400);
    gradient.setColorAt(0, Qt::blue);
    gradient.setColorAt(1, Qt::darkBlue);
    pal.setBrush(QPalette::Background, gradient);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    back = new QPushButton("BACK", this);
    back->setGeometry(1000, 20, 150, 40);
    back->setFont(QFont("serif", 25, QFont::Bold));

    label = new QLabel("SELECT YOUR CARDS :", this);
    label->setFont(QFont("serif", 25, QFont::Bold));
    label->setGeometry(350, 50, 600, 50);

    lavaHound = new QCheckBox("Lava Hound", this);
    lavaHound->setFont(QFont("serif", 16));
    lavaHound->setGeometry(50, 100, 200, 100);
    lavaHound->setChecked(true);
    QLabel *pic1 = new QLabel(this);
    pic1->setPixmap(QPixmap("sources/1.png"));
    pic1->setGeometry(250, 100, 100, 100);
    pic1->setAttribute(Qt::WA_TranslucentBackground);

    iceWizard = new QCheckBox("Ice Wizard", this);
    iceWizard->setFont(QFont("serif", 16));
    iceWizard->setGeometry(50, 200, 200, 100);
    iceWizard->setChecked(true);
    QLabel *pic2 = new QLabel(this);
    pic2->setPixmap(QPixmap("sources/4.png"));
    pic2->setGeometry(250, 200, 100, 100);
    pic2->setAttribute(Qt::WA_TranslucentBackground);

    balloon = new QCheckBox("Balloon", this);
    balloon->setFont(QFont("serif", 16));
    balloon->setGeometry(50, 300, 200, 100);
    balloon->setChecked(true);
    QLabel *pic3 = new QLabel(this);
    pic3->setPixmap(QPixmap("sources/2.png"));
    pic3->setGeometry(250, 300, 100, 100);
    pic3->setAttribute(Qt::WA_TranslucentBackground);

    darkPrince = new QCheckBox("Dark Prince", this);
    darkPrince->setFont(QFont("serif", 16));
    darkPrince->setGeometry(50, 400, 200, 100);
    darkPrince->setChecked(true);
    QLabel *pic4 = new QLabel(this);
    pic4->setPixmap(QPixmap("sources/5.png"));
    pic4->setGeometry(250, 400, 100, 100);
    pic4->setAttribute(Qt::WA_TranslucentBackground);

    hogRider = new QCheckBox("Hog Rider", this);
    hogRider->setFont(QFont("serif", 16));
    hogRider->setGeometry(50, 500, 200, 100);
    hogRider->setChecked(true);
    QLabel *pic5 = new QLabel(this);
    pic5->setPixmap(QPixmap("sources/10.png"));
    pic5->setGeometry(250, 500, 100, 100);
    pic5->setAttribute(Qt::WA_TranslucentBackground);

    minionHorde = new QCheckBox("Minion Horde", this);
    minionHorde->setFont(QFont("serif", 16));
    minionHorde->setGeometry(400, 100, 200, 100);
    minionHorde->setChecked(true);
    QLabel *pic6 = new QLabel(this);
    pic6->setPixmap(QPixmap("sources/3.png"));
    pic6->setGeometry(600, 100, 100, 100);
    pic6->setAttribute(Qt::WA_TranslucentBackground);

    valkyrie = new QCheckBox("Valkyrie", this);
    valkyrie->setFont(QFont("serif", 16));
    valkyrie->setGeometry(400, 200, 200, 100);
    valkyrie->setChecked(false);
    QLabel *pic7 = new QLabel(this);
    pic7->setPixmap(QPixmap("sources/7.png"));
    pic7->setGeometry(600, 200, 100, 100);
    pic7->setAttribute(Qt::WA_TranslucentBackground);

    miner = new QCheckBox("Miner", this);
    miner->setFont(QFont("serif", 16));
    miner->setGeometry(400, 300, 200, 100);
    miner->setChecked(false);
    QLabel *pic8 = new QLabel(this);
    pic8->setPixmap(QPixmap("sources/6.png"));
    pic8->setGeometry(600, 300, 100, 100);
    pic8->setAttribute(Qt::WA_TranslucentBackground);

    witch = new QCheckBox("Witch", this);
    witch->setFont(QFont("serif", 16));
    witch->setGeometry(400, 400, 200, 100);
    witch->setChecked(false);
    QLabel *pic9 = new QLabel(this);
    pic9->setPixmap(QPixmap("sources/8.png"));
    pic9->setGeometry(600, 400, 100, 100);
    pic9->setAttribute(Qt::WA_TranslucentBackground);

    royalGiant = new QCheckBox("Royal Giant", this);
    royalGiant->setFont(QFont("serif", 16));
    royalGiant->setGeometry(400, 500, 200, 100);
    royalGiant->setChecked(false);
    QLabel *pic10 = new QLabel(this);
    pic10->setPixmap(QPixmap("sources/9.png"));
    pic10->setGeometry(600, 500, 100, 100);
    pic10->setAttribute(Qt::WA_TranslucentBackground);

    mirror = new QCheckBox("Mirror", this);
    mirror->setFont(QFont("serif", 16));
    mirror->setGeometry(750, 100, 200, 100);
    mirror->setChecked(false);
    QLabel *pic11 = new QLabel(this);
    pic11->setPixmap(QPixmap("sources/11.png"));
    pic11->setGeometry(950, 100, 100, 100);
    pic11->setAttribute(Qt::WA_TranslucentBackground);

    zap = new QCheckBox("Zap", this);
    zap->setFont(QFont("serif", 16));
    zap->setGeometry(750, 200, 200, 100);
    zap->setChecked(true);
    QLabel *pic12 = new QLabel(this);
    pic12->setPixmap(QPixmap("sources/12.png"));
    pic12->setGeometry(950, 200, 100, 100);
    pic12->setAttribute(Qt::WA_TranslucentBackground);

    rage = new QCheckBox("Rage", this);
    rage->setFont(QFont("serif", 16));
    rage->setGeometry(750, 300, 200, 100);
    rage->setChecked(false);
    QLabel *pic13 = new QLabel(this);
    pic13->setPixmap(QPixmap("sources/13.png"));
    pic13->setGeometry(950, 300, 100, 100);
    pic13->setAttribute(Qt::WA_TranslucentBackground);

    infernoTower = new QCheckBox("Inferno Tower", this);
    infernoTower->setFont(QFont("serif", 16));
    infernoTower->setGeometry(750, 400, 200, 100);
    infernoTower->setChecked(true);
    QLabel *pic14 = new QLabel(this);
    pic14->setPixmap(QPixmap("sources/15.png"));
    pic14->setGeometry(950, 400, 100, 100);
    pic14->setAttribute(Qt::WA_TranslucentBackground);

    usingFurnace = new QCheckBox("Using Furnace", this);
    usingFurnace->setFont(QFont("serif", 16));
    usingFurnace->setGeometry(750, 500, 200, 100);
    usingFurnace->setChecked(false);
    QLabel *pic15 = new QLabel(this);
    pic15->setPixmap(QPixmap("sources/14.png"));
    pic15->setGeometry(950, 500, 100, 100);
    pic15->setAttribute(Qt::WA_TranslucentBackground);

    cards.append(lavaHound);
    cards.append(iceWizard);
    cards.append(balloon);
    cards.append(darkPrince);
    cards.append(hogRider);
    cards.append(minionHorde);
    cards.append(valkyrie);
    cards.append(miner);
    cards.append(witch);
    cards.append(royalGiant);
    cards.append(mirror);
    cards.append(zap);
    cards.append(rage);
    cards.append(infernoTower);
    cards.append(usingFurnace);

    go = new QPushButton("GO!", this);
    go->setFont(QFont("serif", 25, QFont::Bold));
    go->setGeometry(400, 630, 400, 60);

    countSelections = 8;
}

SelectCard::~SelectCard() { }