#ifndef HUNTER_H
#define HUNTER_H

#include "Config.h"
#include "Bullet.h"
#include "utility.h"

class Hunter {
private:
    float radius = 25.f;
    vector2f position;

    Bullet bullet;
    int bulletsCnt = 0;
public:
    Hunter(Config &config);

    void move(float x, float y);
    void shoot(const vector2f &aimDirNorm);

    bool haveShot();
    float getRadius();
    vector2f getPosition();
    vector2f getPositionCenter();
    int getBulletsCnt();

    Bullet *getBullet();
};

#endif // HUNTER_H