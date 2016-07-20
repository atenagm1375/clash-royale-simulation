//
// Created by atenagm on 6/25/16.
//

#include <QtCore/qfileinfo.h>
#include "header files/MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);

    timer = new QTimer();

    lavaHound = new LavaHound(QPixmap("sources/1.png"), timer);
    iceWizard = new IceWizard(QPixmap("sources/4.png"), timer);
    balloon = new Balloon(QPixmap("sources/2.png"), timer);
    darkPrince = new DarkPrince(QPixmap("sources/5.png"), timer);
    hogRider = new HogRider(QPixmap("sources/10.png"), timer);
    minionHorde = new MinionHorde(QPixmap("sources/3.png"), timer);
    valkyrie = new Valkyrie(QPixmap("sources/7.png"), timer);
    miner = new Miner(QPixmap("sources/6.png"), timer);
    witch = new Witch(QPixmap("sources/8.png"), timer);
    royalGiant = new RoyalGiant(QPixmap("sources/9.png"), timer);
    mirror = new Mirror(QPixmap("sources/11.png"), timer);
    zap = new Zap(QPixmap("sources/12.png"), timer);
    rage = new Rage(QPixmap("sources/13.png"), timer);
    infernoTower = new InfernoTower(QPixmap("sources/15.png"), timer);
    furnace = new UsingFurnace(QPixmap("sources/14.png"), timer);

    QstackW = new QStackedWidget(this);
    setCentralWidget(QstackW);

    makeFirstPage();
    QstackW->setCurrentWidget(firstPage);
    makeSettings();
    makeMusic();
    makeMap();
    makeGameOptions();
    makeCardSelection();
    makePause();

    connect(firstPage->exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(firstPage->setting, SIGNAL(clicked()), this, SLOT(settingPage()));
    connect(firstPage->start, SIGNAL(clicked()), this, SLOT(optionPage()));

    connect(settings->back, SIGNAL(clicked()), this, SLOT(goBack()));
    connect(settings->mute, SIGNAL(clicked()), this, SLOT(mute()));
    connect(settings->volume, SIGNAL(valueChanged(int)), this, SLOT(changeVolume(int)));
    connect(settings->music1, SIGNAL(clicked()), this, SLOT(setMusic()));
    connect(settings->music2, SIGNAL(clicked()), this, SLOT(setMusic()));

    connect(gameOptions->back, SIGNAL(clicked()), this, SLOT(goBack()));
    connect(gameOptions->vsComputer, SIGNAL(clicked()), this, SLOT(setGameMode()));
    connect(gameOptions->online, SIGNAL(clicked()), this, SLOT(setGameMode()));
    connect(gameOptions->start, SIGNAL(clicked()), this, SLOT(cardSelection()));

    connect(m1->pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(m2->pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
}

MainWindow::~MainWindow() { }

void MainWindow::makeFirstPage()
{
    firstPage = new FirstPage(QstackW);
    QstackW->addWidget(firstPage);
}

void MainWindow::makeSettings()
{
    settings = new Settings(QstackW);
    QstackW->addWidget(settings);
}

void MainWindow::makeMusic()
{
    playlist1 = new QMediaPlaylist(this);
    playlist1->addMedia(QUrl::fromLocalFile(QFileInfo("sources/a.mp3").absoluteFilePath()));
    playlist1->setPlaybackMode(QMediaPlaylist::Loop);

    playlist2 = new QMediaPlaylist(this);
    playlist2->addMedia(QUrl::fromLocalFile(QFileInfo("sources/b.mp3").absoluteFilePath()));
    playlist2->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer(this);
    if(settings->music1->isChecked())
        music->setPlaylist(playlist1);
    if(settings->music2->isChecked())
        music->setPlaylist(playlist2);
    if(settings->mute->isChecked()){
        settings->volume->setValue(0);
        music->setMuted(true);
    }
    else {
        music->setMuted(false);
        settings->mute->setChecked(false);
        music->setVolume(settings->volume->value());
    }
    music->play();
}

void MainWindow::makeGameOptions()
{
    gameOptions = new GameOptions(QstackW);
    QstackW->addWidget(gameOptions);
}

void MainWindow::makeCardSelection()
{
    selectCard = new SelectCard(QstackW);
    QstackW->addWidget(selectCard);

    connect(selectCard->back, SIGNAL(clicked()), this, SLOT(goBack()));
    connect(selectCard->lavaHound, SIGNAL(stateChanged(int)), this, SLOT(lavaHoundChanged(int)));
    connect(selectCard->iceWizard, SIGNAL(stateChanged(int)), this, SLOT(iceWizardChanged(int)));
    connect(selectCard->balloon, SIGNAL(stateChanged(int)), this, SLOT(balloonChanged(int)));
    connect(selectCard->darkPrince, SIGNAL(stateChanged(int)), this, SLOT(darkPrinceChanged(int)));
    connect(selectCard->hogRider, SIGNAL(stateChanged(int)), this, SLOT(hogRiderChanged(int)));
    connect(selectCard->minionHorde, SIGNAL(stateChanged(int)), this, SLOT(minionHordeChanged(int)));
    connect(selectCard->valkyrie, SIGNAL(stateChanged(int)), this, SLOT(valkyrieChanged(int)));
    connect(selectCard->miner, SIGNAL(stateChanged(int)), this, SLOT(minerChanged(int)));
    connect(selectCard->witch, SIGNAL(stateChanged(int)), this, SLOT(witchChanged(int)));
    connect(selectCard->royalGiant, SIGNAL(stateChanged(int)), this, SLOT(royaleGiantChanged(int)));
    connect(selectCard->mirror, SIGNAL(stateChanged(int)), this, SLOT(mirrorChanged(int)));
    connect(selectCard->zap, SIGNAL(stateChanged(int)), this, SLOT(zapChanged(int)));
    connect(selectCard->rage, SIGNAL(stateChanged(int)), this, SLOT(rageChanged(int)));
    connect(selectCard->infernoTower, SIGNAL(stateChanged(int)), this, SLOT(infernoTowerChanged(int)));
    connect(selectCard->usingFurnace, SIGNAL(stateChanged(int)), this, SLOT(furnaceChanged(int)));
    connect(selectCard->go, SIGNAL(clicked()), this, SLOT(playGame()));
}

void MainWindow::makeMap()
{
    m1 = new map1(QstackW);
    QstackW->addWidget(m1);

    m1->cm->allCards = {lavaHound, iceWizard, balloon, darkPrince, hogRider, minionHorde, valkyrie, miner,
                        witch, royalGiant, mirror, zap, rage, infernoTower, furnace};

    m2 = new map2(QstackW);
    QstackW->addWidget(m2);

    m2->cm->allCards = {lavaHound, iceWizard, balloon, darkPrince, hogRider, minionHorde, valkyrie, miner,
                        witch, royalGiant, mirror, zap, rage, infernoTower, furnace};

    m1->cm->myCardDeck.push_back(lavaHound);
    m1->cm->myCardDeck.push_back(iceWizard);
    m1->cm->myCardDeck.push_back(balloon);
    m1->cm->myCardDeck.push_back(darkPrince);
    m1->cm->myCardDeck.push_back(hogRider);
    m1->cm->myCardDeck.push_back(minionHorde);
    m1->cm->myCardDeck.push_back(zap);
    m1->cm->myCardDeck.push_back(infernoTower);

    m2->cm->myCardDeck.push_back(lavaHound);
    m2->cm->myCardDeck.push_back(iceWizard);
    m2->cm->myCardDeck.push_back(balloon);
    m2->cm->myCardDeck.push_back(darkPrince);
    m2->cm->myCardDeck.push_back(hogRider);
    m2->cm->myCardDeck.push_back(minionHorde);
    m2->cm->myCardDeck.push_back(zap);
    m2->cm->myCardDeck.push_back(infernoTower);
}

void MainWindow::makePause()
{
    pause = new PausePage(QstackW);
    QstackW->addWidget(pause);

    connect(pause->setting, SIGNAL(clicked()), this, SLOT(settingPage()));
    connect(pause->quit, SIGNAL(clicked()), this, SLOT(quitGame()));
    connect(pause->backToGame, SIGNAL(clicked()), this, SLOT(unPause()));
}

void MainWindow::settingPage()
{
    QstackW->setCurrentWidget(settings);
}

void MainWindow::goBack()
{
    if(QstackW->currentWidget() == selectCard)
        QstackW->setCurrentWidget(gameOptions);
    else if(QstackW->currentWidget() == settings && gamePaused)
        QstackW->setCurrentWidget(pause);
    else
        QstackW->setCurrentWidget(firstPage);
}

void MainWindow::mute()
{
    if(settings->mute->isChecked()){
        settings->volume->setDisabled(true);
        music->setMuted(true);
    }
    else {
        settings->volume->setEnabled(true);
        music->setMuted(false);
        settings->mute->setChecked(false);
        music->setVolume(settings->volume->value());
    }
}

void MainWindow::changeVolume(int val)
{
    settings->mute->setChecked(false);
    music->setMuted(false);
    music->setVolume(val);
}

void MainWindow::setMusic()
{
    if(settings->music1->isChecked())
        music->setPlaylist(playlist1);
    if(settings->music2->isChecked())
        music->setPlaylist(playlist2);
    music->play();
}

void MainWindow::optionPage()
{
    QstackW->setCurrentWidget(gameOptions);
}

void MainWindow::setGameMode()
{
    if(gameOptions->vsComputer->isChecked())
        gameModeCode = 0;
    else
        gameModeCode = 1;
}

void MainWindow::cardSelection()
{
    QstackW->setCurrentWidget(selectCard);
}

void MainWindow::lavaHoundChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(lavaHound) : m2->cm->myCardDeck.append(lavaHound);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(lavaHound) : m2->cm->myCardDeck.removeOne(lavaHound);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::iceWizardChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(iceWizard) : m2->cm->myCardDeck.append(iceWizard);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(iceWizard) : m2->cm->myCardDeck.removeOne(iceWizard);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::balloonChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(balloon) : m2->cm->myCardDeck.append(balloon);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(balloon) : m2->cm->myCardDeck.removeOne(balloon);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::darkPrinceChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(darkPrince) : m2->cm->myCardDeck.append(darkPrince);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(darkPrince) : m2->cm->myCardDeck.removeOne(darkPrince);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::hogRiderChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(hogRider) : m2->cm->myCardDeck.append(hogRider);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(hogRider) : m2->cm->myCardDeck.removeOne(hogRider);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::minionHordeChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(minionHorde) : m2->cm->myCardDeck.append(minionHorde);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(minionHorde) : m2->cm->myCardDeck.removeOne(minionHorde);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::valkyrieChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(valkyrie) : m2->cm->myCardDeck.append(valkyrie);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(valkyrie) : m2->cm->myCardDeck.removeOne(valkyrie);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::minerChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(miner) : m2->cm->myCardDeck.append(miner);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(miner) : m2->cm->myCardDeck.removeOne(miner);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::witchChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(witch) : m2->cm->myCardDeck.append(witch);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(witch) : m2->cm->myCardDeck.removeOne(witch);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::royaleGiantChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(royalGiant) : m2->cm->myCardDeck.append(royalGiant);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(royalGiant) : m2->cm->myCardDeck.removeOne(royalGiant);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::mirrorChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(mirror) : m2->cm->myCardDeck.append(mirror);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(mirror) : m2->cm->myCardDeck.removeOne(mirror);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::zapChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(zap) : m2->cm->myCardDeck.append(zap);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(zap) : m2->cm->myCardDeck.removeOne(zap);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::rageChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(rage) : m2->cm->myCardDeck.append(rage);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(rage) : m2->cm->myCardDeck.removeOne(rage);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::infernoTowerChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(infernoTower) : m2->cm->myCardDeck.append(infernoTower);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(infernoTower) : m2->cm->myCardDeck.removeOne(infernoTower);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::furnaceChanged(int state)
{
    if(state == Qt::Checked) {
        selectCard->countSelections++;
        gameModeCode == 0 ? m1->cm->myCardDeck.append(furnace) : m2->cm->myCardDeck.append(furnace);
    }
    else if(state == Qt::Unchecked) {
        selectCard->countSelections--;
        gameModeCode == 0 ? m1->cm->myCardDeck.removeOne(furnace) : m2->cm->myCardDeck.removeOne(furnace);
    }
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::playGame()
{
    gamePaused = false;
    if(gameModeCode == 0) {
        m1->arrangeCardDeck();
        m1->gameTimer->start(1000);
        m1->cm->elixirTimer->start(4000);
        QstackW->setCurrentWidget(m1);
    }
    else
        QstackW->setCurrentWidget(m2);
}

void MainWindow::pauseGame()
{
    gamePaused = true;
    QstackW->setCurrentWidget(pause);
    if(gameModeCode == 0){
        m1->gameTimer->stop();
        m1->cm->elixirTimer->stop();
    }
}

void MainWindow::quitGame()
{
    delete m1;
    delete m2;
    QstackW->setCurrentWidget(gameOptions);
}

void MainWindow::unPause()
{
    gamePaused = false;
    if(gameModeCode == 0) {
        QstackW->setCurrentWidget(m1);
        m1->gameTimer->start();
        m1->cm->elixirTimer->start();
    }
    else
        QstackW->setCurrentWidget(m2);
}