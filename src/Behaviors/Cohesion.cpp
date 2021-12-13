#include "Cohesion.h"

vector2f Cohesion::getDesiredVelocity(std::vector<Entity*> &neighbours) {
    vector2f desiredVelocity;
    float neighbourCount = 0.f;

    for (auto neighbour : neighbours) {
        vector2f dist = animal.getCenter() - neighbour->getCenter();
        float len = std::sqrt((dist.x * dist.x) + (dist.y * dist.y));

        if (len < 350.f) {
            desiredVelocity += neighbour->getPosition();
            neighbourCount++;
        }
    }

    if (neighbourCount == 0.f)
        return animal.getVelocity();

    desiredVelocity /= neighbourCount;
    desiredVelocity = normalize(desiredVelocity - animal.getPosition());

    return desiredVelocity;
}