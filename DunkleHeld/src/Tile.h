/* 
 * File:   Tile.h
 * Author: siapran
 *
 * Created on January 22, 2015, 9:15 PM
 */

#ifndef TILE_H
#define	TILE_H

#include <SFML/Graphics.hpp>

#include "Paintable.h"
#include "Collidable.h"

class Tile : public Paintable, public Collidable {
public:

    Tile(
            int gid, sf::Vector2f position,
            sf::Texture *texture, sf::FloatRect &texCoords, float depth);

    Tile(Tile *orig, sf::Vector2f position);
    virtual ~Tile();

    void addHitBox(sf::FloatRect hitBox);
    virtual bool collidesWithCircle(sf::Vector2f pos, float radius);
    virtual sf::Vector2f resoleCollision(sf::Vector2f pos, float radius);

    int getGid() const;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getDepth();

private:

    int m_gid;
    std::vector<sf::FloatRect> m_hitBoxes;
    //    sf::Vector2f m_position; // moved to Collidable

    sf::VertexArray m_vertices;
    sf::Texture *m_texture;
};

#endif	/* TILE_H */

