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

class Game;

enum Interaction {
    USE, EXAMINE, CONTEXT
};

enum Directions {
    None = 0,
    
    N = 1 << 0,
    E = 1 << 1,
    S = 1 << 2,
    W = 1 << 3,

    NE = N | E,
    SE = S | E,
    SW = S | W,
    NW = N | W,
};

#define OFF 0
#define ON 1


class Actor : public Paintable {
public:
    Actor(sf::Vector2f position, float size, float speed, float range, int direction = 4);
    virtual ~Actor();

    virtual void update(sf::Time deltaTime) = 0;
    void interact(GameObject *object, Interaction interaction);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual float getDepth();

    void setMovingFlags(sf::Uint32 movingFlags, char mode);


private:

    void move(sf::Time deltaTime);

    Game *m_game;

    sf::Vector2f m_position; // contiens la position
    float m_size;
    int m_direction; // là où le personnage regarde: 0 == Nord, 7 == Nord-Ouest
    sf::Vector2f m_moving;
    sf::Uint32 m_movingFlags;
    float m_range;
    float m_speed; // vitesse de l'acteur
    

};

#endif	/* ACTOR_H */

