//
// Created by atenagm on 7/5/16.
//

#ifndef CLASH_ROYALE_LAVAPUPS_H
#define CLASH_ROYALE_LAVAPUPS_H


#include "Card.h"

class LavaPups : public Card{

    Q_OBJECT

public:

    LavaPups(QPixmap, QTimer *);
    ~LavaPups();
};


#endif //CLASH_ROYALE_LAVAPUPS_H
