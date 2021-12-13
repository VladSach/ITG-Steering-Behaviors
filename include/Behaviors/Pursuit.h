#ifndef PURSUIT_H
#define PURSUIT_H

#include "Behavior.h"
#include "Entity.h"
#include "utility.h"
#include <vector>

class Pursuit : public Behavior {
private:
    Entity &animal;

public:
    Pursuit(Entity &parent) : animal(parent) {};

    vector2f getDesiredVelocity(std::vector<Entity*> &targets);
};

#endif // PURSUIT_H