#include "Bullet.h"
#include <iostream>

void Bullet::shot(const vector2f &hunterPos, const vector2f &aimDirNorm) {
    isActive = true;
    
    // set position to hunter shot position
    position = hunterPos;
    startPos = hunterPos;

    velocity = aimDirNorm * maxSpeed;
}

void Bullet::move() {
    if (!isActive) return;
    
    // Update position based on velocity
    position += velocity;

    vector2f difPos;
    difPos.x = std::abs(position.x - startPos.x);
    difPos.y = std::abs(position.y - startPos.y);

    if (difPos.x > 300.f || difPos.y > 300.f) isActive = false;
}

void Bullet::striked() {
    isActive = false;
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

vector2f Bullet::getCenter() {
    vector2f center;
    center.x = getPosition().x + getRadius();
    center.y = getPosition().y + getRadius();
    return center;
}

vector2f Bullet::getPosition() {
    return position;
}

vector2f Bullet::getCurrVelocity() {
    return velocity;
}