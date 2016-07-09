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
#include "Card.h"

class MainWindow;

class CardManagement : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:

    CardManagement(QGraphicsScene *);
    ~CardManagement();
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    QList<Card *> myCardDeck;

private:

    QGraphicsScene *scene;
};


#endif //CLASH_ROYALE_CARDMANAGEMENT_H
