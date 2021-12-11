#ifndef BULLET_H
#define BULLET_H

#include "utility.h"

class Bullet {
private:
    float radius = 5.f;
    float maxSpeed = 15.f;
    bool isActive = false;
    vector2f position;
    vector2f startPos;
    vector2f velocity;

public:
    Bullet() = default;

    void shot(const vector2f &hunterPos, const vector2f &aimDirNorm);
    void move();
    void striked();

    float getRadius();
    float getMaxSpeed();
    bool getIsActive();
    vector2f getCenter();
    vector2f getPosition();
    vector2f getCurrVelocity();
};

#endif // BULLET_H