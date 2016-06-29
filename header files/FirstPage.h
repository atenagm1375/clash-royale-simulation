//
// Created by atenagm on 6/25/16.
//

#ifndef CLASH_ROYALE_FIRSTPAGE_H
#define CLASH_ROYALE_FIRSTPAGE_H


#include <QObject>
#include <QPushButton>

class FirstPage : public QWidget {

    Q_OBJECT
    friend class MainWindow;

public:

    FirstPage(QWidget * = 0);
    ~FirstPage();

private:

    QPushButton *start;
    QPushButton *exit;
    QPushButton *setting;
};


#endif //CLASH_ROYALE_FIRSTPAGE_H
