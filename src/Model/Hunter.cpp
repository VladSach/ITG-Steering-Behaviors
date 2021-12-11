#include "Hunter.h"


Hunter::Hunter(Config &config) {
    bulletsCnt = config.hunterBulletsAmount;

    // Center hunter
    position.x = config.mainWindowWidth  / 2;
    position.y = config.mainWindowHeight / 2;
}

void Hunter::move(float x, float y) {
    position.x += x;
    position.y += y;
}

void Hunter::shoot(const vector2f &aimDirNorm) {
    bulletsCnt -= 1;
    bullet.shot(getPositionCenter(), aimDirNorm);
}

bool Hunter::haveShot() {
    return bullet.getIsActive();
}

float Hunter::getRadius() {
    return radius;
}

vector2f Hunter::getPosition() {
    return position;
}

vector2f Hunter::getPositionCenter() {
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

bool Hunter::getIsAlive() {
    return isAlive;
}