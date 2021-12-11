#include "Flee.h"

// ! Change this later
vector2f Flee::getDesiredVelocity() { return vector2f {0, 0}; }

vector2f Flee::getDesiredVelocity(std::vector<Entity*> &enemies) {
    vector2f vector;

    for (auto enemy : enemies)
        vector += -normalize(enemy->getPosition() - animal.getPosition()) *
                  animal.getVelocityLimit();

    return vector;
}