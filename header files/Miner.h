//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_MINER_H
#define CLASH_ROYALE_MINER_H


#include "Card.h"

class Miner : public Card{

    Q_OBJECT

public:

    Miner(QPixmap, QTimer *);
    ~Miner();

private:

    int crownTowerDamage;
};


#endif //CLASH_ROYALE_MINER_H
