#ifndef GAME_H
#define GAME_H

#include "Observer.h"
#include "Hunter.h"
#include "Config.h"
#include "utility.h"
#include <cmath>

class Game : public Observable {
private:
    Hunter hunter;

    vector2f mapSize;
public:
    Game(Config &config);

    void initGame();
    void update();
    void moveHunter(direction dir);
    void hunterShoot(float mouseX, float mouseY);
    void moveBullet();
    bool isShot();

    // Getters
    float getHunterRadius();
    vector2f getHunterPosition();
    vector2f getHunterCenter();
    int getHunterBulletsCounter();

    float getBulletRadius();
    vector2f getBulletPosition();
    vector2f getBulletCurrentVelocity();

    vector2f getMapSize();
};

#endif // GAME_H