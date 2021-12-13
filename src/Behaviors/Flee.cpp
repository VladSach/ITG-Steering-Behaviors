#include "Flee.h"

vector2f Flee::getDesiredVelocity(std::vector<Entity*> &enemies) {
    vector2f vector;

    for (auto enemy : enemies)
        vector += -normalize(enemy->getPosition() - animal.getPosition()) *
                  animal.getVelocityLimit();

    return vector;
}