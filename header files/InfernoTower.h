//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_INFERNOTOWER_H
#define CLASH_ROYALE_INFERNOTOWER_H


#include "Card.h"

class InfernoTower : public Card{

    Q_OBJECT

public:

    InfernoTower(QPixmap, QTimer *);
    ~InfernoTower();
};


#endif //CLASH_ROYALE_INFERNOTOWER_H
