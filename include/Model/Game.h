#ifndef GAME_H
#define GAME_H

#include "Observer.h"
#include "Hunter.h"
#include "Rabbit.h"
#include "Entity.h"
#include "Config.h"
#include "utility.h"

#include <vector>

class Game : public Observable {
private:
    int rabbitsPopulation = 0;
    int doesPopulation    = 0;
    int wolvesPopulation  = 0;

    Hunter hunter;
    std::vector<Entity*> animals;

    vector2f mapSize;
    vector2f mapOffset;
public:
    Game(Config &config);

    void initGame();
    void update(time64 dt);
    void moveHunter(direction dir, time64 dt);
    void hunterShoot(float mouseX, float mouseY, time64 dt);
    void moveBullet();
    bool isShot();

    void collisionDetection();

    // Getters
    float getHunterRadius();
    vector2f getHunterPosition();
    vector2f getHunterCenter();
    int getHunterBulletsCounter();
    bool getIsHunterAlive();

    std::vector<Rabbit> getRabbits();

    float getBulletRadius();
    vector2f getBulletPosition();
    vector2f getBulletCurrentVelocity();

    vector2f getMapSize();
};

#endif // GAME_H