//
// Created by atenagm on 7/2/16.
//

#ifndef CLASH_ROYALE_TOWER_H
#define CLASH_ROYALE_TOWER_H


#include "Object.h"

class Tower : public Object{

    Q_OBJECT

public:

    Tower(int, int, double, int, int, double, double, QPixmap *, QTimer *);
    ~Tower();

private:


};


#endif //CLASH_ROYALE_TOWER_H
