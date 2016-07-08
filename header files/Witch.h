//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_WITCH_H
#define CLASH_ROYALE_WITCH_H


#include "Card.h"
#include "Skeleton.h"

class Witch : public Card{

    Q_OBJECT

public:

    Witch(QPixmap, QTimer *);
    ~Witch();

private:

    Skeleton *skeleton;
};


#endif //CLASH_ROYALE_WITCH_H
