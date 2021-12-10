#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Game.h"
#include "MainWindow.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Controller {
private:
    Game *m_model;
    MainWindow *m_window;

public:
    Controller(Game *game, MainWindow *window);
    ~Controller() = default;

    void start();
};

#endif // CONTROLLER_H