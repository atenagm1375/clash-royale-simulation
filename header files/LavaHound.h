//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_LAVAHOUND_H
#define CLASH_ROYALE_LAVAHOUND_H


#include "Card.h"
#include "LavaPups.h"

class LavaHound : public Card{

    Q_OBJECT

public:

    LavaHound(QPixmap, QTimer *);
    ~LavaHound();
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:

    LavaPups *lavaPups;
};


#endif //CLASH_ROYALE_LAVAHOUND_H
