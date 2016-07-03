//
// Created by atenagm on 6/25/16.
//

#include <QtCore/qfileinfo.h>
#include "header files/MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1200, 700);
    this->setGeometry(20, 20, 1200, 700);

    QstackW = new QStackedWidget(this);
    setCentralWidget(QstackW);

    makeFirstPage();
    QstackW->setCurrentWidget(firstPage);
    makeSettings();
    makeMusic();
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

    connect(selectCard->back, SIGNAL(clicked()), this, SLOT(goBack()));
    connect(selectCard->lavaHound, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->iceWizard, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->balloon, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->darkPrince, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->hogRider, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->minionHorde, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->valkyrie, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->miner, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->witch, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->royalGiant, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->mirror, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->zap, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->rage, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->infernoTower, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->usingFurnace, SIGNAL(stateChanged(int)), this, SLOT(count(int)));
    connect(selectCard->go, SIGNAL(clicked()), this, SLOT(playGame()));

    connect(pause->setting, SIGNAL(clicked()), this, SLOT(settingPage()));
    connect(pause->quit, SIGNAL(clicked()), this, SLOT(quitGame()));
    connect(pause->backToGame, SIGNAL(clicked()), this, SLOT(playGame()));
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
}

void MainWindow::makeMap()
{
    m1 = new map1(QstackW);
    QstackW->addWidget(m1);

    m2 = new map2(QstackW);
    QstackW->addWidget(m2);

    connect(m1->pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(m2->pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
}

void MainWindow::makePause()
{
    pause = new PausePage(QstackW);
    QstackW->addWidget(pause);
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

void MainWindow::count(int state)
{
    if(state == Qt::Checked)
        selectCard->countSelections++;
    if(state == Qt::Unchecked)
        selectCard->countSelections--;
    if(selectCard->countSelections != 8)
        selectCard->go->setDisabled(true);
    else
        selectCard->go->setEnabled(true);
}

void MainWindow::playGame()
{
    gamePaused = false;
    makeMap();
    if(gameModeCode == 0)
        QstackW->setCurrentWidget(m1);
    else
        QstackW->setCurrentWidget(m2);
}

void MainWindow::pauseGame()
{
    gamePaused = true;
    QstackW->setCurrentWidget(pause);
}

void MainWindow::quitGame()
{
    delete m1;
    delete m2;
    QstackW->setCurrentWidget(gameOptions);
}