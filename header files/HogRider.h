//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_HOGRIDER_H
#define CLASH_ROYALE_HOGRIDER_H


#include "Card.h"

class HogRider : public Card{

    Q_OBJECT

public:

    HogRider(QPixmap, QTimer *);
    ~HogRider();
};


#endif //CLASH_ROYALE_HOGRIDER_H
