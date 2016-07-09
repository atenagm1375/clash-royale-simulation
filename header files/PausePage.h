//
// Created by atenagm on 7/1/16.
//

#ifndef CLASH_ROYALE_PAUSEPAGE_H
#define CLASH_ROYALE_PAUSEPAGE_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qprogressbar.h>

class PausePage : QWidget{

    Q_OBJECT
    friend class MainWindow;

public:

    PausePage(QWidget * = 0);
    ~PausePage();

private:

    QLabel *pauseLabel;
    QPushButton *quit;
    QPushButton *backToGame;
    QPushButton *setting;
};


#endif //CLASH_ROYALE_PAUSEPAGE_H
