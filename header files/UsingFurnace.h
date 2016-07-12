//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_USINGFURNACE_H
#define CLASH_ROYALE_USINGFURNACE_H


#include "Card.h"
#include "FireSpirits.h"

class UsingFurnace : public Card{

    Q_OBJECT

public:

    UsingFurnace(QPixmap, QTimer *);
    ~UsingFurnace();
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:

    FireSpirits *fireSpirits;
    int spawnSpeed;
    int lifeTime;
};


#endif //CLASH_ROYALE_USINGFURNACE_H
