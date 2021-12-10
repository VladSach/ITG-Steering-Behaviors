#include "Controller.h"

Controller::Controller(Game *game, MainWindow *window) {
    m_model = game;
    m_window = window;
    m_model->initGame();
}

void Controller::start() {
    sf::Window &window = *(m_window->getWindow());

    while (window.isOpen()) {
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        // ! Move this to game
        sf::Vector2f hunterCenter = sf::Vector2f(m_model->getHunterCenter().x,
                                                 m_model->getHunterCenter().y);

        // Line between the hunter and the mouse position
        sf::Vector2f aimDir = mousePos - hunterCenter;
        
        // Length of vector: |V| = sqrt(V.x^2 + V.y^2)
        // Normalize vector: |V| = V / |V|
        sf::Vector2f aimDirNorm = aimDir / std::sqrt((aimDir.x * aimDir.x) + 
                                                     (aimDir.y * aimDir.y));
                                                                                
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Player movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                m_model->moveHunter(left);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                m_model->moveHunter(right);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                m_model->moveHunter(up);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                m_model->moveHunter(down);

            // Shooting
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                m_model->hunterShoot(aimDirNorm.x, aimDirNorm.y);
            }
        }

        m_model->update();
    }
}