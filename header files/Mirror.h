//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_MIRROR_H
#define CLASH_ROYALE_MIRROR_H


#include "Card.h"

class Mirror : public Card{

    Q_OBJECT

public:

    Mirror(QPixmap, QTimer *);
    ~Mirror();
};


#endif //CLASH_ROYALE_MIRROR_H
