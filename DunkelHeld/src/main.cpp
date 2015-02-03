/* 
 * File:   main.cpp
 * Author: siapran
 *
 * Created on January 18, 2015, 5:17 PM
 */

#include <cstdlib>
#include "GameLevel.h"
#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

float getFPS(const sf::Time& time) {
    return (1000000.0f / time.asMicroseconds());
}

/*
 * 
 */
int main(int argc, char** argv) {

    string levelName = "resources/levels/bare/test.tmx";
    if (argc == 2) {
        levelName = argv[1];
    }

    Game game;
    game.loadTileset();
    game.loadLevel(levelName.c_str());
    
    Game.runGame();

    return 0;
}

