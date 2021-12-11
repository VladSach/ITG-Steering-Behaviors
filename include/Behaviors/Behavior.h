#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "utility.h"

class Behavior {
private:
    float weight = 1.f;

public:
    virtual ~Behavior() {};

    virtual vector2f getDesiredVelocity() = 0;
};

#endif // BEHAVIOR_H