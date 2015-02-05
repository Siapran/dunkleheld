/* 
 * File:   TileSet.h
 * Author: siapran
 *
 * Created on January 23, 2015, 4:30 PM
 */

#ifndef TILESET_H
#define	TILESET_H

#include "Tile.h"
#include <vector>

// un tileset est une collection de tiles à ajouter dans une tilemap
// on ajoute par exemple le tile 42 à la position (1,3) sur la map
//     m_tileMap[1][3] = Tile((*m_tileSet)[42], sf::Vector2f(1*16, 3*16));
// tileset hérite de std::vector pour qu'on puisse facilement accéder aux tiles
class TileSet : public std::vector<Tile*> {
public:

    TileSet(const char *fileName);
    ~TileSet();
    
    sf::Texture *getTileSheet();
    sf::Vector2i getTileSize();
    
private:

    sf::Texture m_tileSheet;
    sf::Vector2i m_tileSize;
    sf::Vector2u m_sheetSize;
    std::string m_name;

};

#endif	/* TILESET_H */

