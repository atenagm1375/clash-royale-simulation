//
// Created by atenagm on 6/25/16.
//

#ifndef CLASH_ROYALE_SETTINGS_H
#define CLASH_ROYALE_SETTINGS_H


#include <QtCore/qobjectdefs.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qslider.h>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qpushbutton.h>
#include <QButtonGroup>

class Settings : QWidget{

    Q_OBJECT
    friend class MainWindow;

public:

    Settings(QWidget * = 0);
    ~Settings();

private:

    QLabel *settingLabel;
    QPushButton *back;
    QLabel *volumeLabel;
    QSlider *volume;
    QCheckBox *mute;
    QLabel *music;
    QRadioButton *music1;
    QRadioButton *music2;
};


#endif //CLASH_ROYALE_SETTINGS_H
