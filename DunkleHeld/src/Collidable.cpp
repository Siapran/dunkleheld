/* 
 * File:   Collidable.cpp
 * Author: siapran
 * 
 * Created on February 5, 2015, 9:17 AM
 */

#include "Collidable.h"

bool Collidable::collidesWithCircle(sf::Vector2f pos, float radius) {
    return squareDistance(pos, m_position) <= radius * radius;
}

sf::Vector2f Collidable::resoleCollision(sf::Vector2f pos, float radius) {
    auto len = distance(pos, m_position);
    auto normal = (pos - m_position) / len;
    auto penetration = radius - len;
    return (len > 0) ? len : 0;
}

float Collidable::distance(sf::Vector2f a, sf::Vector2f b) {
    return std::sqrt(squareDistance(a, b));
}

float Collidable::squareDistance(sf::Vector2f a, sf::Vector2f b) {
    auto tmp = (a - b);
    return (tmp.x * tmp.x + tmp.y * tmp.y);
}
