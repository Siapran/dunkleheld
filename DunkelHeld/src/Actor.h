/* 
 * File:   Actor.h
 * Author: siapran
 *
 * Created on February 3, 2015, 12:23 AM
 */

#ifndef ACTOR_H
#define	ACTOR_H

#include "Paintable.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>

enum Interaction {
    USE, EXAMINE
};

class Actor : public Paintable {
public:
    Actor();
    virtual ~Actor();

    virtual void update(sf::Time deltaTime) = 0;
    void interact(GameObject *object, Interaction interaction);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual float getDepth() = 0;
    
    
private:

    void move(sf::Time deltaTime);

    sf::FloatRect m_hitbox; // contiens la position
    int m_direction; // là où le personnage regarde: 0 == Nord, 7 == Nord-Ouest
    sf::Vector2i m_moving;
    float m_range;
    float m_speed; // vitesse de l'acteur

};

#endif	/* ACTOR_H */

