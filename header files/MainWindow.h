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

static int gameModeCode = 0;
static bool gamePaused = false;

class MainWindow : public QMainWindow{

    Q_OBJECT

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

public slots:

    void settingPage();
    void goBack();
    void mute();
    void changeVolume(int);
    void setMusic();
    void optionPage();
    void setGameMode();
    void cardSelection();
    void count(int);
    void playGame();
    void pauseGame();
    void quitGame();
    void unPause();
};


#endif //CLASH_ROYALE_MAINWINDOW_H
