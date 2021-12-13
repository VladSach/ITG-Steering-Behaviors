#include "Doe.h"

void Doe::update (std::vector<Entity*> animals, time64 dt) {
    std::vector<Entity*> flock   = findFlockNear(animals);
    std::vector<Entity*> enemies = findEnemiesNear(animals);

    vector2f wanderVelocity     = wander.getDesiredVelocity(enemies) - velocity;
    vector2f evadeVelocity      = evade.getDesiredVelocity(enemies) - velocity;
    vector2f edgesVelocity      = avoidEdges.getDesiredVelocity(enemies) - velocity;
    vector2f cohesionVelocity   = cohesion.getDesiredVelocity(flock) - velocity;
    vector2f separationVelocity = separation.getDesiredVelocity(flock) - velocity;

    vector2f steeringForce; // !Muiltipliy them to sme weight
    steeringForce = wanderVelocity     * 0.5f
                  + evadeVelocity      * 2.f
                  + edgesVelocity      * 10.f
                  + cohesionVelocity   * 2.f
                  + separationVelocity * 3.f;

    steeringForce = truncate(steeringForce - velocity, steeringLimit);

    vector2f acceleration = steeringForce;

    velocity = velocity + acceleration * dt;
    velocity = truncate(velocity, velocityLimit);
    
    vector2f destination = position + velocity * dt;
    move(destination.x, destination.y);
}

std::vector<Entity*> Doe::findFlockNear(std::vector<Entity*> &animals) {
    Config *config = Config::GetInstance();

    std::vector<Entity*> flock;
    int doesEndIndex = config->rabbitsAmount + config->doesAmount * config->doesPerFlock;

    for (int i = config->rabbitsAmount; i < doesEndIndex; i++) {
        Doe *doe = static_cast<Doe*>(animals[i]);
        if (!doe->getIsAlive() || doe->getFlockNumber() != flockNumber) 
            continue;

        vector2f distance = doe->getCenter() - getCenter();
        float    radiiSum = doe->getRadius() + flockRadius;
        if ((distance.x * distance.x) +
            (distance.y * distance.y) <= (radiiSum * radiiSum)) {
                flock.push_back(animals[i]);
        }
    }

    return flock;
}

std::vector<Entity*> Doe::findEnemiesNear(std::vector<Entity*> &animals) {
    Config *config = Config::GetInstance();

    std::vector<Entity*> enemies;
    int wolfsIndex = config->rabbitsAmount + config->doesAmount;

    for (int i = wolfsIndex; i < (int)animals.size(); i++) {
        if (!animals[i]->getIsAlive()) continue;

        vector2f distance = animals[i]->getCenter() - getCenter();
        float    radiiSum = animals[i]->getRadius() + dangerRadius;
        if ((distance.x * distance.x) +
            (distance.y * distance.y) <= (radiiSum * radiiSum)) {
                enemies.push_back(animals[i]);
        }
    }

    return enemies;
}

void Doe::move(float x, float y) {
    position.x = x;
    position.y = y;
}

void Doe::die() {
    isAlive = false;
}

void Doe::setFlockNumber(int number) {
    flockNumber = number;
}

int Doe::getFlockNumber() {
    return flockNumber;
}

bool Doe::getIsAlive() {
    return isAlive;
}

float Doe::getRadius() {
    return radius;
}

float Doe::getDangerRadius() {
    return dangerRadius;
}

float Doe::getVelocityLimit() {
    return velocityLimit;
}

vector2f Doe::getCenter() {
    vector2f center;
    center.x = getPosition().x + getRadius();
    center.y = getPosition().y + getRadius();
    return center;
}

vector2f Doe::getPosition() {
    return position;
}

vector2f Doe::getVelocity() {
    return velocity;
}