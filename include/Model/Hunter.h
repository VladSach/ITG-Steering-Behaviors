#ifndef HUNTER_H
#define HUNTER_H

#include "Config.h"
#include "Bullet.h"
#include "Entity.h"
#include "utility.h"

class Hunter : public Entity {
private:
    bool  isAlive       = true;
    float radius        = 20.f;
    float velocityLimit = 30.f;
    vector2f position;
    vector2f velocity;

    Bullet bullet;
    int bulletsCnt = 0;
public:
    Hunter();

    void update(std::vector<Entity*> animals, time64 dt);
    void changeVelocity(direction dir, time64 dt);
    void move(float x, float y);
    void shoot(const vector2f &aimDirNorm);
    void die();

    bool     haveShot();
    bool     getIsAlive();
    float    getRadius();
    float    getVelocityLimit();
    vector2f getCenter();
    vector2f getPosition();
    vector2f getVelocity();
    int      getBulletsCnt();

    Bullet *getBullet();
};

#endif // HUNTER_H