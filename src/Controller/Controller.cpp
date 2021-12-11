#include "Controller.h"

Controller::Controller(Game *game, MainWindow *window) {
    m_model = game;
    m_window = window;
    m_model->initGame();
}

void Controller::start() {
    sf::Window &window = *(m_window->getWindow());

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        float time = clock.getElapsedTime().asSeconds() * 1000;
        
        // TODO: Change 120 to config.FPS * 2
        if (clock.getElapsedTime().asSeconds() >= 1/120)
            m_model->update(time);                     
                                            
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Player movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                m_model->moveHunter(left, time);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                m_model->moveHunter(right, time);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                m_model->moveHunter(up, time);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                m_model->moveHunter(down, time);

            // Shooting
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                m_model->hunterShoot(mousePos.x, mousePos.y, time);
            }
        }

        clock.restart();
    }
}