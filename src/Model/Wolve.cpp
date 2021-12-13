#include "Wolve.h"

void Wolve::update(std::vector<Entity*> animals, time64 dt) {
    starvationTimer += dt;
    if (starvationTimer >= 3000) { die(); }

    std::vector<Entity*> targets = findTargets(animals);

    vector2f wanderVelocity  = wander.getDesiredVelocity(animals)     - velocity;
    vector2f edgesVelocity   = avoidEdges.getDesiredVelocity(animals) - velocity;
    vector2f pursuitVelocity = pursuit.getDesiredVelocity(targets)    - velocity;

    vector2f steeringForce;
    steeringForce =  wanderVelocity
                  +  edgesVelocity
                  +  pursuitVelocity;

    steeringForce = truncate(steeringForce - velocity, steeringLimit);

    vector2f acceleration = steeringForce;

    velocity = velocity + acceleration * dt;
    velocity = truncate(velocity, velocityLimit);
    
    vector2f destination = position + velocity * dt;
    move(destination.x, destination.y);
}

std::vector<Entity*> Wolve::findTargets(std::vector<Entity*> &animals) {
    std::vector<Entity*> targets;

    for (auto animal : animals) {
        if (!animal->getIsAlive()) continue;

        vector2f distance = animal->getCenter() - getCenter();
        float    radiiSum = animal->getRadius() + seekRadius;
        if ((distance.x * distance.x) +
            (distance.y * distance.y) <= (radiiSum * radiiSum)) {
                targets.push_back(animal);
        }
    }

    return targets;
}

void Wolve::move(float x, float y) {
    position.x = x;
    position.y = y;
}

void Wolve::die() {
    isAlive = false;
}

void Wolve::kill() {
    starvationTimer = 0.f;
}

bool Wolve::getIsAlive() {
    return isAlive;
}

float Wolve::getRadius() {
    return radius;
}

float Wolve::getSeekRadius() {
    return seekRadius;
}

float Wolve::getVelocityLimit() {
    return velocityLimit;
}

vector2f Wolve::getCenter() {
    vector2f center;
    center.x = getPosition().x + getRadius();
    center.y = getPosition().y + getRadius();
    return center;
}

vector2f Wolve::getPosition() {
    return position;
}

vector2f Wolve::getVelocity() {
    return velocity;
}