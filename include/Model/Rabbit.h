#ifndef RABBIT_H
#define RABBIT_H

#include "utility.h"
#include "Wander.h"
#include "Flee.h"
#include "AvoidEdges.h"
#include "Entity.h"

class Rabbit : public Entity {
private:
    float radius        = 15.f;
    float dangerRadius  = 50.f;
    float velocityLimit = 3.f;
    float steeringLimit = 5.f;
    bool  isAlive       = true;

    vector2f position;
    vector2f velocity;

    Wander wander;
    Flee flee;
    AvoidEdges avoidEdges;
    
public:
    Rabbit(float x, float y) : wander(*this), flee(*this), avoidEdges(*this) {
        position.x = x;
        position.y = y;
    };

    void update(std::vector<Entity*> animals, time64 dt);
    std::vector<Entity*> findEnemiesNear(std::vector<Entity*> &animals);
    void move(float x, float y);
    void die();

    bool     getIsAlive();
    float    getRadius();
    float    getDangerRadius();
    float    getVelocityLimit();
    vector2f getCenter();
    vector2f getPosition();
    vector2f getVelocity();
};

#endif // RABBIT_H