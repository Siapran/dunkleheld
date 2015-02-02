/* 
 * File:   main.cpp
 * Author: siapran
 *
 * Created on January 18, 2015, 5:17 PM
 */

#include <cstdlib>
#include "GameLevel.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    TileSet tileSet("resources/tilesets/temple.xml");
    GameLevel level("resources/levels/test.tmx", tileSet);

    
    sf::RenderWindow window(sf::VideoMode(480, 480), "Donker Held", sf::Style::Titlebar | sf::Style::Close);
    sf::View view(sf::FloatRect(0, 0, 240, 240));
    window.setView(view);

    
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(0x91, 0xb0, 0x9a));
        window.draw(level);
        window.display();
    }

    return 0;
}

