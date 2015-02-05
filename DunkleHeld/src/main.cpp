/* 
 * File:   main.cpp
 * Author: siapran
 *
 * Created on January 18, 2015, 5:17 PM
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "GameLevel.h"
#include "Game.h"

#include "Controller.h"


using namespace std;

float getFPS(const sf::Time& time) {
    return (1000000.0f / time.asMicroseconds());
}

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& obj) {
    os << "(" << obj.x << ", " << obj.y << ")";
    return os;
}

/*
 * 
 */
int main(int argc, char** argv) {


    //    sf::RenderWindow m_window(sf::VideoMode(240 * 3, 240 * 3), "DunkleHeld", sf::Style::Titlebar | sf::Style::Close);
    //
    //    sf::RectangleShape box(sf::Vector2f(200, 150));
    //    box.setPosition(200, 200);
    //    box.setFillColor(sf::Color::Transparent);
    //    box.setOutlineColor(sf::Color::Red);
    //    box.setOutlineThickness(3);
    //
    //    sf::CircleShape circle(100);
    //    circle.setPosition(50, 50);
    //    circle.setFillColor(sf::Color::Transparent);
    //    circle.setOutlineColor(sf::Color::Blue);
    //    circle.setOutlineThickness(3);
    //
    //    while (m_window.isOpen()) {
    //        sf::Event event;
    //        while (m_window.pollEvent(event)) {
    //            if (event.type == sf::Event::Closed)
    //                m_window.close();
    //            if (event.type == sf::Event::KeyPressed) {
    //                if (event.key.code == sf::Keyboard::Z) {
    //                    circle.move(0, -5);
    //                }
    //                if (event.key.code == sf::Keyboard::Q) {
    //                    circle.move(-5, 0);
    //                }
    //                if (event.key.code == sf::Keyboard::S) {
    //                    circle.move(0, 5);
    //                }
    //                if (event.key.code == sf::Keyboard::D) {
    //                    circle.move(5, 0);
    //                }
    //
    //            }
    //        }
    //        m_window.clear();
    //        m_window.draw(box);
    //        m_window.draw(circle);
    //        m_window.display();
    //        cout << Collidable::collidesBoxVSCircle(box.getGlobalBounds(), circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius()), circle.getRadius())
    //                << " : " << Collidable::resolveBoxVSCircle(box.getGlobalBounds(), circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius()), circle.getRadius()) << endl;
    //    }

    string levelName = "resources/levels/bare/entrance.tmx";
    if (argc == 2) {
        levelName = argv[1];
    }

    Game *game = Game::Instance();
    game->loadTileset();
    game->loadLevel(levelName.c_str());
    game->loadProps();

    game->runGame();

    return 0;
}

