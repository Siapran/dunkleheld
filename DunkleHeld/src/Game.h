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

    static Game *Instance();

    void runGame();

    void loadTileset(const char* fileName = "resources/tilesets/temple.xml");
    void loadLevel(const char* fileName = "resources/levels/test.tmx");
    void loadControls(const char* fileName = "resources/misc/DefaultControls.xml");
    void loadProps(const char* fileName = "resources/props/props.xml");

    void setVar(std::string varName, int value);
    int getVar(std::string varName);
    bool isSet(std::string varName);
    
    GameObject *createGameObject(TiXmlElement *node);
    
private:

    Game();
    static Game *m_instance;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow m_window;
    sf::View m_view;
    Controller m_controller;

    TileSet *m_tileSet;
    GameLevel *m_level;
    std::map<std::string, Prop *> m_propSet;

    std::map<std::string, int> m_globalVars;

    Professor m_player;

};

#endif	/* GAME_H */

