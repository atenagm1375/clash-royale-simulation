//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_RAGE_H
#define CLASH_ROYALE_RAGE_H


#include "Card.h"

class Rage : public Card{

    Q_OBJECT

public:

    Rage(QPixmap, QTimer *);
    ~Rage();
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:

    double duration;
};


#endif //CLASH_ROYALE_RAGE_H
