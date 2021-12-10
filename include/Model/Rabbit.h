#ifndef RABBIT_H
#define RABBIT_H

#include "utility.h"

class Rabbit {
private:
    float radius = 15.f;
    vector2f position;
public:
    Rabbit(float x, float y);

    void move(float x, float y);
};

#endif // RABBIT_H