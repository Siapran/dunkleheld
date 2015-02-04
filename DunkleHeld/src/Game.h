/* 
 * File:   Game.h
 * Author: siapran
 *
 * Created on January 21, 2015, 9:15 PM
 */

#ifndef GAME_H
#define	GAME_H

#include <SFML/Graphics.hpp>
#include <map>

#include "TileSet.h"
#include "GameLevel.h"
#include "Controller.h"
#include "Professor.h"
#include "Prop.h"

#define BACKGROUND_COLOR sf::Color(0x91, 0xb0, 0x9a)

class Game {
public:
    Game();
    void runGame();

    void loadTileset(const char* fileName = "resources/tilesets/temple.xml");
    void loadLevel(const char* fileName = "resources/levels/test.tmx");
    void loadControls(const char* fileName = "resources/misc/DefaultControls.xml");
    void loadProps(const char* fileName = "resources/props/props.xml");
    
private:

    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow m_window;
    Controller m_controller;

    TileSet *m_tileSet;
    GameLevel *m_level;
    
    Professor m_player;
    std::map<std::string, Prop *> m_propSet;

};

#endif	/* GAME_H */

