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

/*
 * 
 */
int main(int argc, char** argv) {

    string levelName = "resources/levels/bare/entrance.tmx";
    if (argc == 2) {
        levelName = argv[1];
    }

    Game game;
    game.loadTileset();
    game.loadLevel(levelName.c_str());
    game.loadProps();



    return 0;
}

