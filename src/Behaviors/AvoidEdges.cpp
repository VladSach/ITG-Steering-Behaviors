#include "AvoidEdges.h"

vector2f AvoidEdges::getDesiredVelocity(std::vector<Entity*> &enemies) {
    float    maxSpeed = animal.getVelocityLimit() * 10;
    vector2f position = animal.getPosition();

    vector2f mapSize;
    //mapSize.x = config.mainWindowWidth  * 3/4;
    //mapSize.y = config.mainWindowHeight * 3/4;
    mapSize.x = 1280 * 3/4;
    mapSize.y = 720  * 3/4;

    vector2f mapOffset;
    //mapOffset.x = (config.mainWindowWidth  - mapSize.x) / 2;
    //mapOffset.y = (config.mainWindowHeight - mapSize.y) / 2;
    mapOffset.x = (1280 - mapSize.x) / 2;
    mapOffset.y = (720  - mapSize.y) / 2;

    if (position.x - edgeDistance <= mapOffset.x) {
        return vector2f {maxSpeed, 0};
    }
    if (position.x + edgeDistance >= mapOffset.x + mapSize.x) {
        return vector2f {-maxSpeed, 0};
    }
    if (position.y - edgeDistance <= mapOffset.y) {
        return vector2f {0, maxSpeed};
    }
    if (position.y + edgeDistance >= mapOffset.y + mapSize.y) {
        return vector2f {0, -maxSpeed};
    }

    return animal.getVelocity();
}