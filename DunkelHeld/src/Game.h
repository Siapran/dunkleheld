/* 
 * File:   Game.h
 * Author: siapran
 *
 * Created on January 21, 2015, 9:15 PM
 */

#ifndef GAME_H
#define	GAME_H

#include <SFML/Graphics.hpp>
#include "TileSet.h"
#include "GameLevel.h"

#define BACKGROUND_COLOR sf::Color(0x91, 0xb0, 0x9a)

class Game {
public:
    Game();
    void runGame();
    
    void loadTileset(const char* fileName = "resources/tilesets/temple.xml");
    void loadLevel(const char* fileName = "resources/levels/bare/test.tmx");
    
private:
    
    void processEvents();
    void update();
    void render();
    
    sf::RenderWindow m_window;
    
    TileSet *m_tileSet;
    GameLevel *m_level;
    
};

#endif	/* GAME_H */

