//
// Created by atenagm on 7/7/16.
//

#ifndef CLASH_ROYALE_WINDOW_H
#define CLASH_ROYALE_WINDOW_H


#include "Card.h"
#include "MainWindow.h"
#include <QVector>

class Window {

public:

    Window();
    ~Window();
    MainWindow mainWindow;
    QVector<Card *> myCardDeck;
};


#endif //CLASH_ROYALE_WINDOW_H
