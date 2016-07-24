//
// Created by atenagm on 7/21/16.
//

#ifndef CLASH_ROYALE_WINNERANNOUNCEMENT_H
#define CLASH_ROYALE_WINNERANNOUNCEMENT_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>

class WinnerAnnouncement : public QWidget {

    Q_OBJECT
    friend class MainWindow;

public:

    WinnerAnnouncement(QWidget * = 0);
    ~WinnerAnnouncement();

private:

    QLabel *message;
    QPushButton *quit;
    QPushButton *continueB;
};


#endif //CLASH_ROYALE_WINNERANNOUNCEMENT_H
