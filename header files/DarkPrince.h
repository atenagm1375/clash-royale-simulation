//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_DARKPRINCE_H
#define CLASH_ROYALE_DARKPRINCE_H


#include "Card.h"

class DarkPrince : public Card{

    Q_OBJECT

public:

    DarkPrince(QPixmap, QTimer *);
    ~DarkPrince();

private:

    int shieldHitPoint;
    int areaDamage;
};


#endif //CLASH_ROYALE_DARKPRINCE_H
