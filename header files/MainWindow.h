//
// Created by atenagm on 6/25/16.
//

#ifndef CLASH_ROYALE_MAINWINDOW_H
#define CLASH_ROYALE_MAINWINDOW_H


#include <QObject>
#include <QtWidgets>
#include <QtMultimedia/qmediaplayer.h>
#include <QtWidgets/qstackedwidget.h>
#include <QtWidgets/qmainwindow.h>
#include <QMediaPlaylist>
#include "FirstPage.h"
#include "Settings.h"
#include "GameOptions.h"
#include "SelectCard.h"
#include "map1.h"
#include "map2.h"
#include "PausePage.h"
#include "Card.h"
#include "LavaHound.h"
#include "IceWizard.h"
#include "Balloon.h"
#include "DarkPrince.h"
#include "HogRider.h"
#include "MinionHorde.h"
#include "Valkyrie.h"
#include "Miner.h"
#include "Witch.h"
#include "RoyalGiant.h"
#include "Mirror.h"
#include "Zap.h"
#include "Rage.h"
#include "InfernoTower.h"
#include "UsingFurnace.h"

static int gameModeCode = 0;
static bool gamePaused = false;


class MainWindow : public QMainWindow{

    Q_OBJECT
    friend class CardManagement;

public:

    MainWindow(QWidget * = 0);
    ~MainWindow();
    void makeFirstPage();
    void makeSettings();
    void makeMusic();
    void makeGameOptions();
    void makeCardSelection();
    void makeMap();
    void makePause();

private:

    QStackedWidget *QstackW;
    FirstPage *firstPage;
    Settings *settings;
    QMediaPlayer *music;
    QMediaPlaylist *playlist1;
    QMediaPlaylist *playlist2;
    GameOptions *gameOptions;
    SelectCard *selectCard;
    map1 *m1;
    map2 *m2;
    PausePage *pause;
    QTimer *timer;
    LavaHound *lavaHound;
    IceWizard *iceWizard;
    Balloon *balloon;
    DarkPrince *darkPrince;
    HogRider *hogRider;
    MinionHorde *minionHorde;
    Valkyrie *valkyrie;
    Miner *miner;
    Witch *witch;
    RoyalGiant *royalGiant;
    Mirror *mirror;
    Zap *zap;
    Rage *rage;
    InfernoTower *infernoTower;
    UsingFurnace *furnace;

public slots:

    void settingPage();
    void goBack();
    void mute();
    void changeVolume(int);
    void setMusic();
    void optionPage();
    void setGameMode();
    void cardSelection();
    //void count(int);
    void lavaHoundChanged(int);
    void iceWizardChanged(int);
    void balloonChanged(int);
    void darkPrinceChanged(int);
    void hogRiderChanged(int);
    void minionHordeChanged(int);
    void valkyrieChanged(int);
    void minerChanged(int);
    void witchChanged(int);
    void royaleGiantChanged(int);
    void mirrorChanged(int);
    void zapChanged(int);
    void rageChanged(int);
    void infernoTowerChanged(int);
    void furnaceChanged(int);
    void playGame();
    void pauseGame();
    void quitGame();
    void unPause();
};


#endif //CLASH_ROYALE_MAINWINDOW_H
