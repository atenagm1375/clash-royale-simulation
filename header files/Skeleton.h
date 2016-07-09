//
// Created by atenagm on 7/5/16.
//

#ifndef CLASH_ROYALE_SKELETON_H
#define CLASH_ROYALE_SKELETON_H


#include <QtCore/qobjectdefs.h>
#include "Card.h"

class Skeleton : public Card
{

    Q_OBJECT

public:

    Skeleton(QPixmap, QTimer *);
    ~Skeleton();
};


#endif //CLASH_ROYALE_SKELETON_H
