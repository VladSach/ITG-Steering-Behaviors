#include "Hunter.h"


Hunter::Hunter() {
    Config *config = Config::GetInstance();

    bulletsCnt = config->hunterBulletsAmount;

    // Center hunter
    position.x = config->mainWindowWidth  / 2;
    position.y = config->mainWindowHeight / 2;
}

void Hunter::update(std::vector<Entity*> animals, time64 dt) {
    vector2f pos = position + velocity * dt;
    velocity *= 0.f;

    move(pos.x, pos.y);
    getBullet()->move();
}

void Hunter::changeVelocity(direction dir, time64 dt) {
    switch (dir) {
    case left:
        velocity.x = -velocityLimit;
        break;

    case right:
        velocity.x = velocityLimit;
        break;

    case up:
        velocity.y = -velocityLimit;
        break;

    case down:
        velocity.y = velocityLimit;
        break;

    default:
        break;
    }
}

void Hunter::move(float x, float y) {
    position.x = x;
    position.y = y;
}

void Hunter::shoot(const vector2f &aimDirNorm) {
    bulletsCnt -= 1;
    bullet.shot(getCenter(), aimDirNorm);
}

void Hunter::die() {
    isAlive = false;
}

bool Hunter::haveShot() {
    return bullet.getIsActive();
}

bool Hunter::getIsAlive() {
    return isAlive;
}

float Hunter::getRadius() {
    return radius;
}

float Hunter::getVelocityLimit() {
    return velocityLimit;
}

vector2f Hunter::getPosition() {
    return position;
}

vector2f Hunter::getVelocity() {
    return velocity;
}

vector2f Hunter::getCenter() {
    vector2f center;
    center.x = getPosition().x + getRadius();
    center.y = getPosition().y + getRadius();
    return center;
}

int Hunter::getBulletsCnt() {
    return bulletsCnt;
}

Bullet *Hunter::getBullet() {
    return &bullet;
}