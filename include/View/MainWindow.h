#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "Game.h"
#include "Config.h"
#include "Observer.h"
#include <SFML/Graphics.hpp>

typedef unsigned int uint;

class MainWindow : public Observer {
private:
    Game *m_Model;

    sf::RenderWindow m_Window;

    int windowWidth = 0;
    int windowHeight = 0;

    const sf::String gameTitle = "Steering Begaviours";
    const int desktopWidth  = sf::VideoMode::getDesktopMode().width;
    const int desktopHeight = sf::VideoMode::getDesktopMode().height;

public:
    MainWindow(Game *game, Config &condig);
    ~MainWindow() = default;

    virtual void update();

    sf::RenderWindow *getWindow();
};

#endif // MAIN_WINDOW_H