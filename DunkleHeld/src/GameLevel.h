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

#include <vector>
#include "Tile.h"
#include "TileSet.h"
#include "GameObject.h"

class GameLevel : public sf::Drawable, public sf::Transformable {
public:

    GameLevel(const char *fileName, TileSet &tileSet);
    virtual ~GameLevel();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void broadCastEvent(std::string source, std::string event);

    void addListener(std::string target, GameObject *listener);
    void removeListener(std::string target, GameObject *listener);

private:

    void loadFromXml(const char *fileName);

    std::vector<std::vector<Tile *> > m_tileMap;
    TileSet &m_tileSet;
    sf::Vector2i m_size;

    std::multimap<std::string, GameObject *> m_listeners;
    std::map<std::string, GameObject *> m_objects;
    
    
};

#endif	/* GAMELEVEL_H */

