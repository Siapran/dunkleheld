/* 
 * File:   Collidable.h
 * Author: siapran
 *
 * Created on February 5, 2015, 9:17 AM
 */

#ifndef COLLIDABLE_H
#define	COLLIDABLE_H

#include <SFML/Graphics.hpp>

class Actor;

//enum CollideReaction {
//    RESOLVE, DAMAGE, ACTION, NONE
//};

class Collidable {
public:

    Collidable(sf::Vector2f m_position = sf::Vector2f()) :
    m_position(m_position) {
    }

    virtual bool collidesWithCircle(sf::Vector2f pos, float radius);
    virtual sf::Vector2f resoleCollision(sf::Vector2f pos, float radius);
    virtual void onCollide(Actor *target) = 0;
    sf::Vector2f m_position;

    static float distance(sf::Vector2f a, sf::Vector2f b);
    static float squareDistance(sf::Vector2f a, sf::Vector2f b = sf::Vector2f());

    static bool collidesBoxVSCircle(sf::FloatRect box,
            sf::Vector2f pos, float radius);
    static sf::Vector2f resolveBoxVSCircle(sf::FloatRect box,
            sf::Vector2f pos, float radius);

    static sf::Vector2f getCentre(sf::FloatRect box);
    static inline float clamp(float left, float right, float z);
};

#endif	/* COLLIDABLE_H */

