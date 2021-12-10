#include "Game.h"

Game::Game(Config &config) : hunter(config){
    mapSize.x = config.mainWindowWidth * 3/4;
    mapSize.y = config.mainWindowHeight * 3/4;
}

void Game::initGame() {
    return;
}

void Game::update() {
    // All animals logic goes here too


    // Bullet update
    hunter.getBullet()->move();

    notifyUpdate();
}

void Game::moveHunter(direction dir) {
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
    update();
}

void Game::hunterShoot(float mouseX, float mouseY) {
    if (!hunter.getBulletsCnt() || isShot()) {
        notifyUpdate();
        return;
    }
    vector2f aimDirNorm;
    aimDirNorm.x = mouseX;
    aimDirNorm.y = mouseY;

    hunter.shoot(aimDirNorm);

    notifyUpdate();
    update();
}

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