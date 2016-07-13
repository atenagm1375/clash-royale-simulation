//
// Created by atenagm on 7/3/16.
//

#ifndef CLASH_ROYALE_SPECIFICATIONS_H
#define CLASH_ROYALE_SPECIFICATIONS_H

namespace spc{
    enum Type{AIRTROOP, GROUNDTROOP, BUILDING, SPELL};
    enum Target{Ground, Building, AirGround, what};
    enum Speed{NONE, Slow, Medium, Fast, VeryFast};
    enum fireType{blueFire, greenFire, redFire};
    extern int cardNo;
}

#endif //CLASH_ROYALE_SPECIFICATIONS_H
