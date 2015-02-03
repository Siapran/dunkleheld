/* 
 * File:   Game.cpp
 * Author: siapran
 * 
 * Created on January 21, 2015, 9:15 PM
 */

#include "Game.h"

Game::Game() :
m_window(sf::VideoMode(480, 480), "Donker Held", sf::Style::Titlebar | sf::Style::Close),
m_tileSet(nullptr), m_level(nullptr) {
}

void Game::runGame() {

    sf::View view(sf::FloatRect(0, 0, 240, 240));
    m_window.setView(view);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    while (m_window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            processEvents();
            update(timePerFrame);
        }
        render();
    }

}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                m_controller.handleInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                m_controller.handleInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void Game::update(sf::Time) {
}

void Game::render() {
    m_window.clear(BACKGROUND_COLOR);
    m_window.draw(*m_level);
    m_window.display();
}

void Game::loadLevel(const char* fileName) {
    if (m_level != nullptr) delete m_level;
    m_level = new GameLevel(fileName, *m_tileSet);
}

void Game::loadTileset(const char* fileName) {
    if (m_tileSet != nullptr) delete m_tileSet;
    m_tileSet = new TileSet(fileName);
}

void Game::loadControls(const char* fileName) {

}
