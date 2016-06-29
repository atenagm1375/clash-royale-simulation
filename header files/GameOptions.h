//
// Created by atenagm on 6/26/16.
//

#ifndef CLASH_ROYALE_GAMEOPTIONS_H
#define CLASH_ROYALE_GAMEOPTIONS_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QButtonGroup>

class GameOptions : public QWidget{

    Q_OBJECT
    friend class MainWindow;

public:

    GameOptions(QWidget * = 0);
    ~GameOptions();

private:

    QLabel *nameLabel;
    QLineEdit *nameEditor;
    QLabel *gameMode;
    QRadioButton *vsComputer;
    QRadioButton *online;
    QPushButton *back;
    QPushButton *start;
    QLabel *picture;
    QLabel *picture2;
};


#endif //CLASH_ROYALE_GAMEOPTIONS_H
