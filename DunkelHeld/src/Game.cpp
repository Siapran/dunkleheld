/* 
 * File:   Game.cpp
 * Author: siapran
 * 
 * Created on January 21, 2015, 9:15 PM
 */

#include "Game.h"

Game::Game() : m_window(sf::VideoMode(480, 480), "Donker Held", sf::Style::Titlebar | sf::Style::Close) {
}

void Game::runGame() {

    sf::View view(sf::FloatRect(0, 0, 240, 240));
    m_window.setView(view);

    //    sf::Clock timer;

    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type) {
                //Si une touche est pressée
            case sf::Event::KeyPressed:
                //On envoit le code de la touche et un boolean à true
                handlePlayerInput(event.key.code, true);
                break;
                //Si une touche est relachée
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void Game::update() {
}

void Game::render() {
    m_window.clear(BACKGROUND_COLOR);
    m_window.draw(m_level);
    m_window.display(); //Affiche l'écran.
}

void Game::loadLevel(const char* fileName) {
    delete m_level;
    m_level = new GameLevel(fileName, *m_tileSet);
}

void Game::loadTileset(const char* fileName) {

}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}