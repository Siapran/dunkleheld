/* 
 * File:   Actor.cpp
 * Author: siapran
 * 
 * Created on February 3, 2015, 12:23 AM
 */

#include "Actor.h"

Actor::Actor(sf::Vector2f position, float size, float speed, float range, int direction)
: m_position(position), m_size(size), m_speed(speed), m_range(range), m_direction(direction) {

}

Actor::~Actor() {
}

void Actor::move(sf::Time deltaTime) {
    sf::Vector2f movement = m_moving * m_speed * deltaTime.asSeconds();
    if (m_moving.x != 0 && m_moving.y != 0) {
        movement /= (float) std::sqrt(2);
    }
    m_position += movement;
}

void Actor::interact(GameObject* object, Interaction interaction) {
    switch (interaction) {
        case USE:
            object->use(this);
            break;
        case EXAMINE:
            object->showDescription();
            break;
        case CONTEXT:

            break;
        default:
            break;
    }
}

float Actor::getDepth() {
    return m_position.y + m_size;
}

void Actor::setMovingFlags(sf::Uint32 movingFlags, bool mode) {
    if (mode) {
        m_movingFlags |= movingFlags;
    } else {
        m_movingFlags &= ~movingFlags;
    }
}

void Actor::setPosition(sf::Vector2f position) {
    m_position = position;
}
