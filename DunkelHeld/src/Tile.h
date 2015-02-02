/* 
 * File:   Tile.h
 * Author: siapran
 *
 * Created on January 22, 2015, 9:15 PM
 */

#ifndef TILE_H
#define	TILE_H

#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable, public sf::Transformable {
public:

    Tile(
            int gid, sf::Vector2f position,
            sf::Texture *texture, sf::FloatRect &texCoords);
    
    Tile(Tile *orig, sf::Vector2f position);
    virtual ~Tile();

    void addHitBox(sf::FloatRect hitBox);

    bool collidesWith(sf::FloatRect& hitBox) const;
    int getGid() const;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    int m_gid;
    std::vector<sf::FloatRect> m_hitBoxes;
    sf::Vector2f m_position;

    sf::VertexArray m_vertices;
    sf::Texture *m_texture;

};

#endif	/* TILE_H */

