#include "Evade.h"

vector2f Evade::getDesiredVelocity(std::vector<Entity*> &enemies) {
    if (enemies.empty()) { return animal.getVelocity(); }
    
    vector2f vector;

    for (auto enemy : enemies) {
        vector2f distance = enemy->getCenter() - animal.getCenter();
        float len = std::sqrt((distance.x * distance.x) + (distance.y * distance.y));
        float t = len / enemy->getVelocityLimit();
    
        vector2f futurePos = enemy->getPosition() + enemy->getVelocity() * t;

        vector += -normalize(futurePos - animal.getPosition()) *
                  animal.getVelocityLimit();
    }

    return vector;
}