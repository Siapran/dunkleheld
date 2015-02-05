/* 
 * File:   Collidable.h
 * Author: siapran
 *
 * Created on February 5, 2015, 9:17 AM
 */

#ifndef COLLIDABLE_H
#define	COLLIDABLE_H

#include <SFML/Graphics.hpp>

class Collidable {
public:
    virtual bool collidesWithCircle(sf::Vector2f pos, float radius);
    virtual sf::Vector2f resoleCollision(sf::Vector2f pos, float radius);
    sf::Vector2f m_position;

    static float distance(sf::Vector2f a, sf::Vector2f b);
    static float squareDistance(sf::Vector2f a, sf::Vector2f b);
};

#endif	/* COLLIDABLE_H */

