#ifndef HUNTER_H
#define HUNTER_H

#include "Config.h"

class Hunter {
private:
    int x = 0;
    int y = 0;
    int bulletsCnt = 0;
public:
    Hunter(Config &config) {
        bulletsCnt = config.hunterBulletsAmount;
    };

    void move();
    void shoot();
};

#endif