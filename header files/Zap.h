//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_ZAP_H
#define CLASH_ROYALE_ZAP_H


#include "Card.h"

class Zap : public Card{

    Q_OBJECT

public:

    Zap(QPixmap, QTimer *);
    ~Zap();

private:

    int crownTowerDamage;
};


#endif //CLASH_ROYALE_ZAP_H
