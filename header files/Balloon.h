//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_BALLOON_H
#define CLASH_ROYALE_BALLOON_H


#include "Card.h"

class Balloon : public Card{

    Q_OBJECT

public:

    Balloon(QPixmap, QTimer *);
    ~Balloon();
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:

    int deathDamage;
};


#endif //CLASH_ROYALE_BALLOON_H
