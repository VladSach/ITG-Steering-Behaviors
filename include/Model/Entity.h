#ifndef ENTITY_H
#define ENTITY_H

#include "utility.h"
#include <vector>

class Entity {
// private:
//     bool  isAlive = true;
//     float radius = 15.f;
//     float velocityLimit = 3.f;

//     vector2f position;
//     vector2f velocity;
    
public:
    virtual ~Entity() {};

    virtual void update(std::vector<Entity*> animals, time64 dt) = 0;
    virtual void move(float x, float y) = 0;
    virtual void die()                  = 0;


    virtual bool     getIsAlive()       = 0;
    virtual float    getRadius()        = 0;
    virtual float    getVelocityLimit() = 0;
    virtual vector2f getCenter()        = 0;
    virtual vector2f getPosition()      = 0;
    virtual vector2f getVelocity()      = 0;
};

#endif // ENTITY_H