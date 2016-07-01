//
// Created by atenagm on 6/29/16.
//


#ifndef CLASH_ROYALE_SELECTCARD_H
#define CLASH_ROYALE_SELECTCARD_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qcheckbox.h>

class SelectCard : public QWidget{

    Q_OBJECT
    friend class MainWindow;

public:

    SelectCard(QWidget * = 0);
    ~SelectCard();

private:

    QLabel *label;
    QPushButton *back;
    QPushButton *go;
    QList<QCheckBox *> cards;
    QCheckBox *lavaHound;
    QCheckBox *iceWizard;
    QCheckBox *zap;
    QCheckBox *rage;
    QCheckBox *mirror;
    QCheckBox *miner;
    QCheckBox *darkPrince;
    QCheckBox *balloon;
    QCheckBox *royalGiant;
    QCheckBox *infernoTower;
    QCheckBox *usingFurnace;
    QCheckBox *minionHorde;
    QCheckBox *hogRider;
    QCheckBox *witch;
    QCheckBox *valkyrie;

    int countSelections;
};


#endif //CLASH_ROYALE_SELECTCARD_H
