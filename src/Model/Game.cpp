#include "Game.h"

Game::Game() : hunter() {
    Config *config = Config::GetInstance();

    mapSize.x = config->mainWindowWidth  * 3/4;
    mapSize.y = config->mainWindowHeight * 3/4;

    mapOffset.x = (config->mainWindowWidth  - mapSize.x) / 2;
    mapOffset.y = (config->mainWindowHeight - mapSize.y) / 2;

    rabbitsPopulation = config->rabbitsAmount;
    wolvesPopulation  = config->wolvesAmount;
    doesFlocks        = config->doesAmount;
    doesPerFlock      = config->doesPerFlock;

    doesPopulation = doesFlocks * doesPerFlock;
}

void Game::initGame() {
    for (int i = 0; i < rabbitsPopulation; i++) {
        Rabbit *rabbit = new Rabbit(getRandomNumber(mapOffset.x, mapSize.x + mapOffset.x),
                                    getRandomNumber(mapOffset.y, mapSize.y + mapOffset.y));
        
        animals.push_back(rabbit);
    }

    for (int i = 0; i < doesFlocks; i++) {
        for (int j = 0; j < doesPerFlock; j++) {
            // TODO: spawn one int random point and spawn others around it
            Doe *doe = new Doe(getRandomNumber(mapOffset.x, mapSize.x + mapOffset.x),
                           getRandomNumber(mapOffset.y, mapSize.y + mapOffset.y));

            doe->setFlockNumber(j);

            animals.push_back(doe);
        }
    }

    for (int i = 0; i < wolvesPopulation; i++) {
        Wolve *wolve = new Wolve(getRandomNumber(mapOffset.x, mapSize.x + mapOffset.x),
                                 getRandomNumber(mapOffset.y, mapSize.y + mapOffset.y));

        animals.push_back(wolve);
    }

    animals.push_back(&hunter);

    notifyUpdate();
}

void Game::update(time64 dt) {
    // All animals logic goes here too
    for (auto animal : animals) {
        animal->update(animals, dt);
    }

    collisionDetection();

    notifyUpdate();
}

void Game::moveHunter(direction dir, time64 dt) {
    hunter.changeVelocity(dir, dt);
}

void Game::hunterShoot(float mouseX, float mouseY, time64 dt) {
    if (!hunter.getBulletsCnt() || isShot() || !hunter.getIsAlive()) {
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

        // Wolves
        int wolvesPopulationIndex = rabbitsPopulation + doesPopulation + wolvesPopulation;
        for (int i = rabbitsPopulation + doesPopulation; i < wolvesPopulationIndex; i++) {
            Wolve *wolve = static_cast<Wolve*>(animals[i]);
            if (!wolve->getIsAlive() || animal == wolve) continue;
        
            vector2f distance = animal->getCenter() - wolve->getCenter();
            float    radiiSum = animal->getRadius() + wolve->getRadius();
            if ((distance.x * distance.x) + 
                (distance.y * distance.y) <= (radiiSum * radiiSum)) {
                    wolve->kill();
                    animal->die();
            }
        }       

        if (animal == &hunter) continue;
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
    return hunter.getCenter();
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

std::vector<Doe> Game::getDoes() {
    std::vector<Doe> does;
    for (int i = rabbitsPopulation; i < rabbitsPopulation + doesPopulation; i++) {
        does.push_back(*static_cast<Doe*>(animals[i]));
    }
    return does;
}

std::vector<Wolve> Game::getWolves() {
    std::vector<Wolve> wolves;
    int wolvesPopulationIndex = rabbitsPopulation + doesPopulation + wolvesPopulation;
    for (int i = rabbitsPopulation + doesPopulation; i < wolvesPopulationIndex; i++) {
        wolves.push_back(*static_cast<Wolve*>(animals[i]));
    }
    return wolves;
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