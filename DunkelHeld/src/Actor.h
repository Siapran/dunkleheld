/* 
 * File:   Actor.h
 * Author: siapran
 *
 * Created on February 3, 2015, 12:23 AM
 */

#ifndef ACTOR_H
#define	ACTOR_H

#include "Paintable.h"
#include <SFML/Graphics.hpp>

class Actor : public Paintable {
public:
    Actor();
    virtual ~Actor();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual float getDepth() = 0;

    void move(sf::Vector2f);
    virtual void update(sf::Time deltaTime) = 0;

private:

    sf::FloatRect m_hitbox; // contiens la position
    int m_direction; // là où le personnage regarde: 0 == Nord, 7 == Nord-Ouest

};

#endif	/* ACTOR_H */

