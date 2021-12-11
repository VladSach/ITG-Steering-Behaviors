#include "Game.h"

Game::Game(Config &config) : hunter(config){
    mapSize.x = config.mainWindowWidth  * 3/4;
    mapSize.y = config.mainWindowHeight * 3/4;

    mapOffset.x = (config.mainWindowWidth  - mapSize.x) / 2;
    mapOffset.y = (config.mainWindowHeight - mapSize.y) / 2;

    rabbitsPopulation = config.rabbitsAmount;
    doesPopulation    = config.doesAmount;
    wolvesPopulation  = config.wolvesAmount;
}

void Game::initGame() {
    for (int i = 0; i < rabbitsPopulation; i++) {
        Rabbit *rabbit = new Rabbit(getRandomNumber(mapOffset.x, mapSize.x + mapOffset.x),
                                    getRandomNumber(mapOffset.y, mapSize.y + mapOffset.y));
        
        animals.push_back(rabbit);
    }

    notifyUpdate();
}

void Game::update(time64 dt) {
    // All animals logic goes here too
    for (auto animal : animals) {
        animal->update(animals, dt);
    }

    // Bullet update
    hunter.getBullet()->move();

    collisionDetection();

    notifyUpdate();
}

void Game::moveHunter(direction dir, time64 dt) {
    // TODO: Change to vector movement
    switch (dir) {
    case left:
        hunter.move(-10.f, 0.f);
        break;

    case right:
        hunter.move(10.f, 0.f);
        break;

    case up:
        hunter.move(0.f, -10.f);
        break;

    case down:
        hunter.move(0.f, 10.f);
        break;

    default:
        break;
    }

    notifyUpdate();
    update(dt);
}

void Game::hunterShoot(float mouseX, float mouseY, time64 dt) {
    if (!hunter.getBulletsCnt() || isShot()) {
        notifyUpdate();
        return;
    }

    vector2f mousePos {mouseX, mouseY};
    vector2f hunterCenter = getHunterCenter();

    // Line between the hunter and the mouse position
    vector2f aimDir = mousePos - hunterCenter;
        
    // Length of vector: |V| = sqrt(V.x^2 + V.y^2)
    // Normalize vector: |V| = V / |V|
    vector2f aimDirNorm = normalize(aimDir);

    hunter.shoot(aimDirNorm);

    notifyUpdate();
    update(dt);
}

void Game::collisionDetection() {
    for (auto animal : animals) {
        if (!animal->getIsAlive()) continue;

        // End of the world collision
        if (animal->getPosition().x < mapOffset.x             || 
            animal->getPosition().x > mapSize.x + mapOffset.x ||
            animal->getPosition().y < mapOffset.y             || 
            animal->getPosition().y > mapSize.y + mapOffset.y  ) {
                animal->die();
            }

        // Bullet collision
        if (isShot()) {
            vector2f distance = animal->getCenter() - hunter.getBullet()->getCenter();
            float    radiiSum = animal->getRadius() + hunter.getBullet()->getRadius();
            if ((distance.x * distance.x) + 
                (distance.y * distance.y) <= (radiiSum * radiiSum)) {
                    hunter.getBullet()->striked();
                    animal->die();
            }
        }
    }

    // Wolfs collisions
}

/* ****************************** */
/*            Getters             */
/* ****************************** */

bool Game::isShot() {
    return hunter.haveShot();
}

float Game::getHunterRadius() {
    return hunter.getRadius();
}

vector2f Game::getHunterPosition() {
    return hunter.getPosition();
}

vector2f Game::getHunterCenter() {
    return hunter.getPositionCenter();
}

int Game::getHunterBulletsCounter() {
    return hunter.getBulletsCnt();
}

bool Game::getIsHunterAlive() {
    return hunter.getIsAlive();
}

std::vector<Rabbit> Game::getRabbits() {
    std::vector<Rabbit> rabbits;
    for (int i = 0; i < rabbitsPopulation; i++) {
        rabbits.push_back(*static_cast<Rabbit*>(animals[i]));
    }
    return rabbits;
}

float Game::getBulletRadius() {
    return hunter.getBullet()->getRadius();
}

vector2f Game::getBulletPosition() {
    return hunter.getBullet()->getPosition();
}

vector2f Game::getBulletCurrentVelocity() {
    return hunter.getBullet()->getCurrVelocity();
}

vector2f Game::getMapSize() {
    return mapSize;
}