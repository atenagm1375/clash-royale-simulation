//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_ROYALGIANT_H
#define CLASH_ROYALE_ROYALGIANT_H


#include "Card.h"

class RoyalGiant : public Card{

    Q_OBJECT

public:

    RoyalGiant(QPixmap, QTimer *);
    ~RoyalGiant();
};


#endif //CLASH_ROYALE_ROYALGIANT_H
