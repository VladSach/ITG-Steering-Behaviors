#include "Wander.h"

vector2f Wander::getDesiredVelocity(std::vector<Entity*> &enemies) {
    if (getRandomNumber(0, 1)) {
        angle += angleChangeStep;
    } else {
        angle -= angleChangeStep;
    }
    // angle += getRandomNumber(0, 1) ? angleChangeStep : -angleChangeStep;

    vector2f futurePos = animal.getPosition() + 
                         normalize(animal.getVelocity()) * circleDistance;
    
    vector2f vector = vector2f {std::sin(deg2rad(angle)),
                                std::cos(deg2rad(angle))} * circleRadius;
    
    vector2f desiredVelocity = normalize(futurePos + vector - 
                               animal.getPosition()) * animal.getVelocityLimit();

    
    return desiredVelocity;
}