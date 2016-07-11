//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_VALKYRIE_H
#define CLASH_ROYALE_VALKYRIE_H


#include "Card.h"

class Valkyrie : public Card{

    Q_OBJECT

public:

    Valkyrie(QPixmap, QTimer *);
    ~Valkyrie();
    void mousePressEvent(QGraphicsSceneMouseEvent *);

};


#endif //CLASH_ROYALE_VALKYRIE_H
