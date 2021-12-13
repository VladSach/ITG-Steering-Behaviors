#include "Separation.h"

vector2f Separation::getDesiredVelocity(std::vector<Entity*> &neighbours) {
    vector2f desiredVelocity;
    float neighbourCount = 0.f;

    for (auto neighbour : neighbours) {
        vector2f dist = animal.getCenter() - neighbour->getCenter();
        float len = std::sqrt((dist.x * dist.x) + (dist.y * dist.y));

        if (len < 350.f) {
            desiredVelocity += neighbour->getPosition() - animal.getPosition();
            neighbourCount++;
        }
    }

    if (neighbourCount == 0.f)
        return animal.getVelocity();

    desiredVelocity /= neighbourCount;
    desiredVelocity *= -1.f;
    desiredVelocity = normalize(desiredVelocity);

    return desiredVelocity;
}