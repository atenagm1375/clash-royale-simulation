//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_MINIONHORDE_H
#define CLASH_ROYALE_MINIONHORDE_H


#include "Card.h"

class MinionHorde : public Card{

    Q_OBJECT

public:

    MinionHorde(QPixmap, QTimer *);
    ~MinionHorde();
};


#endif //CLASH_ROYALE_MINIONHORDE_H
