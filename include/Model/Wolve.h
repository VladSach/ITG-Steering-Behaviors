#ifndef WOLVE_H
#define WOLVE_H

#include "utility.h"
#include "Wander.h"
#include "Flee.h"
#include "AvoidEdges.h"
#include "Pursuit.h"
#include "Entity.h"

class Wolve : public Entity {
private:
    bool  isAlive         = true;
    float radius          = 15.f;
    float seekRadius      = 200.f;
    float velocityLimit   = 20.f;
    float steeringLimit   = 3.f;
    float starvationTimer = 0.f;

    vector2f position;
    vector2f velocity;

    Wander wander;
    AvoidEdges avoidEdges;
    Pursuit pursuit;
    
public:
    Wolve(float x, float y) : wander(*this), avoidEdges(*this), pursuit(*this) {
        position.x = x;
        position.y = y;
    }; 

    void update(std::vector<Entity*>animals, time64 dt);
    std::vector<Entity*> findTargets(std::vector<Entity*> &animals);
    void move(float x, float y);
    void kill();
    void die();

    bool     getIsAlive();
    float    getRadius();
    float    getSeekRadius();
    float    getVelocityLimit();
    vector2f getCenter();
    vector2f getPosition();
    vector2f getVelocity();
};

#endif // WOLVE_H