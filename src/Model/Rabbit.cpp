#include "Rabbit.h"

void Rabbit::update(std::vector<Entity*> animals, time64 dt) {
    std::vector<Entity*> enemies = findEnemiesNear(animals);

    vector2f wanderVelocity = wander.getDesiredVelocity();
    vector2f fleeVelocity   = flee.getDesiredVelocity(enemies);
    vector2f edgesVelocity  = avoidEdges.getDesiredVelocity();

    vector2f steeringForce;
    steeringForce += wanderVelocity - velocity;
    steeringForce += fleeVelocity   - velocity;
    steeringForce += edgesVelocity  - velocity;

    steeringForce = truncate(steeringForce - velocity, steeringLimit);

    vector2f acceleration = steeringForce;

    velocity = velocity + acceleration * dt;
    velocity = truncate(velocity, velocityLimit);
    
    vector2f destination = position + velocity * dt;
    move(destination.x, destination.y);
}

std::vector<Entity*> Rabbit::findEnemiesNear(std::vector<Entity*> &animals) {
    std::vector<Entity*> enemies;

    for (auto animal : animals) {
        if (!animal->getIsAlive()) continue;
        vector2f distance = animal->getCenter() - getCenter();
        float    radiiSum = animal->getRadius() + dangerRadius;
        if ((distance.x * distance.x) +
            (distance.y * distance.y) <= (radiiSum * radiiSum)) {
                enemies.push_back(animal);
        }
    }

    return enemies;
}

void Rabbit::move(float x, float y) {
    position.x = x;
    position.y = y;
}

void Rabbit::die() {
    isAlive = false;
}

bool Rabbit::getIsAlive() {
    return isAlive;
}

float Rabbit::getRadius() {
    return radius;
}

float Rabbit::getDangerRadius() {
    return dangerRadius;
}

float Rabbit::getVelocityLimit() {
    return velocityLimit;
}

vector2f Rabbit::getCenter() {
    vector2f center;
    center.x = getPosition().x + getRadius();
    center.y = getPosition().y + getRadius();
    return center;
}

vector2f Rabbit::getPosition() {
    return position;
}

vector2f Rabbit::getVelocity() {
    return velocity;
}