/* 
 * File:   Actor.cpp
 * Author: siapran
 * 
 * Created on February 3, 2015, 12:23 AM
 */

#include "Actor.h"

Actor::Actor() {
}

Actor::~Actor() {
}

void Actor::move(sf::Time deltaTime) {
    float xmovement =  m_moving.x * m_speed * deltaTime.asSeconds();
    float ymovement =  m_moving.y * m_speed * deltaTime.asSeconds();
    if (m_moving.x != 0 && m_moving.y != 0) {
        xmovement /= std::sqrt(2);
        ymovement /= std::sqrt(2);
    }
    m_hitbox.left += xmovement;
    m_hitbox.top += ymovement;
}

void Actor::interact(GameObject* object, Interaction interaction) {
    object
}
