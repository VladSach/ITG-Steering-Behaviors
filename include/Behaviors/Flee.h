#ifndef FLEE_H
#define FLEE_H

#include "Behavior.h"
#include "Entity.h"
#include "utility.h"
#include <vector>

class Flee : public Behavior {
private:
    Entity &animal;

public:
    Flee(Entity &parent) : animal(parent) {};

    vector2f getDesiredVelocity();
    vector2f getDesiredVelocity(std::vector<Entity*> &enemies);
};

#endif // FLEE_H