#ifndef EVADE_H
#define EVADE_H

#include "Behavior.h"
#include "Entity.h"
#include "utility.h"
#include <vector>

class Evade : public Behavior {
private:
    Entity &animal;

public:
    Evade(Entity &parent) : animal(parent) {};

    vector2f getDesiredVelocity(std::vector<Entity*> &enemies);
};

#endif // EVADE_H