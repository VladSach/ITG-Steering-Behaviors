#include "MainWindow.h"

MainWindow::MainWindow(Game *game, Config &config)
{
    m_Model = game;
    m_Model->addObserver(this);

    windowWidth = config.mainWindowWidth;
    windowHeight = config.mainWindowHeight;

    m_Window.create(sf::VideoMode(windowWidth, windowHeight),
                    gameTitle,
                    sf::Style::Titlebar |
                        sf::Style::Close);

    const sf::Vector2i centerWindowPos = {
        (desktopWidth - windowWidth) / 2,
        (desktopHeight - windowHeight) / 2};

    m_Window.setPosition(centerWindowPos);
    m_Window.clear(sf::Color::Black);
    m_Window.setFramerateLimit(60);
}

void MainWindow::update()
{
    m_Window.clear();

    // Draw field
    float fieldWidth  = m_Model->getMapSize().x;
    float fieldHeight = m_Model->getMapSize().y;

    sf::RectangleShape field(sf::Vector2f(fieldWidth, fieldHeight));
    field.setFillColor(sf::Color(25, 62, 4)); // Dark Green
    field.setPosition(sf::Vector2f((windowWidth - fieldWidth)   / 2,
                                   (windowHeight - fieldHeight) / 2));
    m_Window.draw(field);

    // Draw hunter
    float hX = m_Model->getHunterPosition().x;
    float hY = m_Model->getHunterPosition().y;

    sf::CircleShape hunter(m_Model->getHunterRadius());
    hunter.setFillColor(sf::Color::Blue);
    hunter.setPosition(sf::Vector2f(hX, hY));
    m_Window.draw(hunter);

    // Draw bullet
    float bX = m_Model->getBulletPosition().x;
    float bY = m_Model->getBulletPosition().y;

    sf::CircleShape bullet(m_Model->getBulletRadius());
    bullet.setPosition(sf::Vector2f(bX, bY));
    
    if (m_Model->isShot()) {
        bullet.setFillColor(sf::Color::Red);
    } else {
        bullet.setFillColor(sf::Color::Transparent);
    }
    m_Window.draw(bullet);

    // Draw rabbits
    for (auto rabbit : m_Model->getRabbits()) {
        sf::CircleShape rabbitShape(rabbit.getRadius());

        if (rabbit.getIsAlive()) {
            rabbitShape.setFillColor(sf::Color::White);
        } else {
            rabbitShape.setFillColor(sf::Color::Transparent);
        }
        
        rabbitShape.setPosition(rabbit.getPosition());
        m_Window.draw(rabbitShape);
    }

    m_Window.display();
}

sf::RenderWindow *MainWindow::getWindow()
{
    return &m_Window;
}