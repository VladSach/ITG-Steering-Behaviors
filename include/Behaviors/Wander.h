#ifndef WANDER_H
#define WANDER_H

#include "Behavior.h"
#include "Entity.h"
#include "utility.h"

class Wander : public Behavior {
private:
    float circleDistance = 1.f;
    float circleRadius   = 2.f;

    int angleChangeStep = 15;
    int angle           = 0;

    Entity &animal;

public:
    Wander(Entity &parent) : animal(parent) {};

    vector2f getDesiredVelocity();
};

#endif // WANDER_H