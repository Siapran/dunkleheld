/* 
 * File:   Game.cpp
 * Author: siapran
 * 
 * Created on January 21, 2015, 9:15 PM
 */

#include "Game.h"

Game *Game::m_instance = nullptr;

Game* Game::Instance() {
    if (m_instance == nullptr)
        m_instance = new Game();
    return m_instance;
}

Game::Game() :
m_window(sf::VideoMode(240 * 3, 240 * 3), "Donker Held", sf::Style::Titlebar | sf::Style::Close),
m_view(sf::FloatRect(0, 0, 240, 240)),
m_tileSet(nullptr), m_level(nullptr),
m_player() {
    m_controller.setPlayer1(&m_player);
    m_controller.bindKey("P1 up", sf::Keyboard::Z);
    m_controller.bindKey("P1 left", sf::Keyboard::Q);
    m_controller.bindKey("P1 down", sf::Keyboard::S);
    m_controller.bindKey("P1 right", sf::Keyboard::D);
}

void Game::runGame() {

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

void Game::update(sf::Time deltaTime) {
    m_player.update(deltaTime);
}

void Game::render() {

    m_window.setView(m_view);
    m_window.clear(BACKGROUND_COLOR);
    m_window.draw(*m_level);
    m_window.display();
}

void Game::loadLevel(const char* fileName) {
    if (m_level != nullptr) delete m_level;
    m_level = new GameLevel(this, fileName, *m_tileSet, m_player);

}

void Game::loadTileset(const char* fileName) {
    if (m_tileSet != nullptr) delete m_tileSet;
    m_tileSet = new TileSet(fileName);
}

void Game::loadControls(const char* fileName) {

}

void Game::loadProps(const char* fileName) {
    TiXmlDocument doc(fileName);
    doc.LoadFile();
    TiXmlElement *root = doc.RootElement();

    for (
            TiXmlElement *propNode = root->FirstChildElement("prop");
            propNode != nullptr;
            propNode = propNode->NextSiblingElement()) {
        std::string propName = propNode->Attribute("name");
        m_propSet[propName] = new Prop(propNode->Attribute("file"));
    }
}

int Game::getVar(std::string varName) {
    auto found = m_globalVars.find(varName);
    if (found != m_globalVars.end())
        return found->second;
    else return 0;
}

void Game::setVar(std::string varName, int value) {
    m_globalVars[varName] = value;
}
