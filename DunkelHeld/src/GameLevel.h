/* 
 * File:   GameLevel.h
 * Author: siapran
 *
 * Created on January 22, 2015, 9:01 PM
 */

#ifndef GAMELEVEL_H
#define	GAMELEVEL_H

#include <vector>
#include "Tile.h"
#include "TileSet.h"

using std::vector;

class GameLevel : public sf::Drawable, public sf::Transformable {
public:

    GameLevel(const char *fileName, TileSet &tileSet);
    virtual ~GameLevel();


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    void loadFromXml(const char *fileName);

    vector<vector<Tile *> > m_tileMap;
    TileSet &m_tileSet;
    sf::Vector2i m_size;

};

#endif	/* GAMELEVEL_H */

