//
// Created by atenagm on 7/5/16.
//

#ifndef CLASH_ROYALE_CARDMANAGEMENT_H
#define CLASH_ROYALE_CARDMANAGEMENT_H


#include <QtCore/qobject.h>
#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsscene.h>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QtWidgets/qprogressbar.h>
#include <QGraphicsScene>
#include "Card.h"
#include "Tower.h"

class Card;
class map1;

class CardManagement : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT
    friend class MainWindow;

public:

    CardManagement(QGraphicsScene *);
    ~CardManagement();
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    QList<Card *> myCardDeck;
    QList<Card *> allCards;

protected:

    QGraphicsScene *scene;
    QTimer *timer;
    QProgressBar *elixir;
    QTimer *elixirTimer;

public slots:

    void incrementElixir();
};


#endif //CLASH_ROYALE_CARDMANAGEMENT_H
