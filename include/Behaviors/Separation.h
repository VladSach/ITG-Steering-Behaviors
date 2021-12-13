#ifndef SEPARATION_H
#define SEPARATION_H

#include "Behavior.h"
#include "Entity.h"
#include "utility.h"
#include <vector>

class Separation : public Behavior {
private:
    Entity &animal;

public:
    Separation(Entity &parent) : animal(parent) {};

    vector2f getDesiredVelocity(std::vector<Entity*> &neighbours);
};

#endif // SEPARATION_H