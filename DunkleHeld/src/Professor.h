/* 
 * File:   Professor.h
 * Author: siapran
 *
 * Created on February 3, 2015, 10:27 AM
 */

#ifndef PROFESSOR_H
#define	PROFESSOR_H

#include "Actor.h"
#include "AnimatedSprite.h"

class Professor : public Actor {
public:
    Professor(sf::Vector2f position = sf::Vector2f());
    virtual ~Professor();

    virtual void update(sf::Time deltaTime);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void setPosition(sf::Vector2f position);
    
private:

    AnimatedSprite m_sprite;

    sf::Vector2f m_offset;
    sf::Texture m_texture;
    std::map<std::string, Animation> m_animations;
    Animation *m_currentAnimation;

};

#endif	/* PROFESSOR_H */

