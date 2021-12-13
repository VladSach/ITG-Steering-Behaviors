#ifndef COHESION_H
#define COHESION_H

#include "Behavior.h"
#include "Entity.h"
#include "utility.h"
#include <vector>

class Cohesion : public Behavior {
private:
    Entity &animal;

public:
    Cohesion(Entity &parent) : animal(parent) {};

    vector2f getDesiredVelocity(std::vector<Entity*> &neighbours);
};

#endif // COHESION_H