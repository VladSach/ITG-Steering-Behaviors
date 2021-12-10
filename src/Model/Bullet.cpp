#include "Bullet.h"
#include <iostream>

void Bullet::shot(const vector2f &hunterPos, const vector2f &aimDirNorm) {
    isActive = true;
    
    // set position to hunter shot position
    position = hunterPos;
    startPos = hunterPos;

    currVelocity.x = aimDirNorm.x * maxSpeed;
    currVelocity.y = aimDirNorm.y * maxSpeed;
}

void Bullet::move() {
    if (!isActive) return;
    
    // Update position based on velocity
    position.x += currVelocity.x;
    position.y += currVelocity.y;

    vector2f difPos;
    difPos.x = std::abs(position.x - startPos.x);
    difPos.y = std::abs(position.y - startPos.y);

    if (difPos.x > 400.f || difPos.y > 400.f) isActive = false;
}

float Bullet::getRadius() {
    return radius;
}

float Bullet::getMaxSpeed() {
    return maxSpeed;
}

bool Bullet::getIsActive() {
    return isActive;
}

vector2f Bullet::getPosition() {
    return position;
}

vector2f Bullet::getCurrVelocity() {
    return currVelocity;
}