#include "Pursuit.h"

vector2f Pursuit::getDesiredVelocity(std::vector<Entity*> &targets) {
    if (targets.empty()) { return animal.getVelocity(); }
    
    Entity *target = targets[0]; // Pursue first seen prey
    vector2f distance = target->getCenter() - animal.getCenter();
    float len = std::sqrt((distance.x * distance.x) + (distance.y * distance.y));
    float t = len / target->getVelocityLimit();
    
    vector2f futurePos = target->getPosition() + target->getVelocity() * t;

    return normalize(futurePos - animal.getPosition()) * animal.getVelocityLimit();
}