#ifndef AVOID_EDGES_H
#define AVOID_EDGES_H

#include "Behavior.h"
#include "Entity.h"
#include "utility.h"

class AvoidEdges : public Behavior {
private:
    float edgeDistance = 50.f;

    Entity &animal;

public:
    AvoidEdges(Entity &parent) : animal(parent) {};

    vector2f getDesiredVelocity(std::vector<Entity*> &enemies);
};

#endif // AVOID_EDGES_H