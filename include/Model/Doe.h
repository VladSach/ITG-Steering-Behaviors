#ifndef DOE_H
#define DOE_H

#include "utility.h"
#include "Wander.h"
#include "Evade.h"
#include "AvoidEdges.h"
#include "Cohesion.h"
#include "Separation.h"
#include "Entity.h"
#include "Config.h"

class Doe : public Entity {
private:
    int   flockNumber   = 0;
    bool  isAlive       = true;
    float radius        = 15.f;
    float flockRadius   = 1500.f;
    float dangerRadius  = 350.f;
    float velocityLimit = 25.f;
    float steeringLimit = 10.f;

    vector2f position;
    vector2f velocity;

    Wander wander;
    Evade evade;
    AvoidEdges avoidEdges;
    Cohesion cohesion;
    Separation separation;
    
public:
    Doe(float x, float y) : wander(*this),
                            evade(*this),
                            avoidEdges(*this),
                            cohesion(*this),
                            separation(*this) {
        position.x = x;
        position.y = y;
    };

    void update(std::vector<Entity*> animals, time64 dt);
    std::vector<Entity*> findFlockNear(std::vector<Entity*> &animals);
    std::vector<Entity*> findEnemiesNear(std::vector<Entity*> &animals);
    void move(float x, float y);
    void die();

    void     setFlockNumber(int number);

    int      getFlockNumber();
    bool     getIsAlive();
    float    getRadius();
    float    getDangerRadius();
    float    getVelocityLimit();
    vector2f getCenter();
    vector2f getPosition();
    vector2f getVelocity();
};

#endif // DOE_H