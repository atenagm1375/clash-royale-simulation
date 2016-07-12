//
// Created by atenagm on 6/30/16.
//

#ifndef CLASH_ROYALE_ICEWIZARD_H
#define CLASH_ROYALE_ICEWIZARD_H


#include "Card.h"

class IceWizard : public Card{

    Q_OBJECT

public:

    IceWizard(QPixmap, QTimer *);
    ~IceWizard();
    void mousePressEvent(QGraphicsSceneMouseEvent *);

};


#endif //CLASH_ROYALE_ICEWIZARD_H
