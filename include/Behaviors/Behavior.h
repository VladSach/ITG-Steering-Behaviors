#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "utility.h"
#include "Entity.h"
#include <vector>

class Behavior {
public:
    virtual ~Behavior() {};

    virtual vector2f getDesiredVelocity(std::vector<Entity*> &enemies) = 0;
};

#endif // BEHAVIOR_H