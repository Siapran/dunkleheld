/* 
 * File:   Professor.cpp
 * Author: siapran
 * 
 * Created on February 3, 2015, 10:27 AM
 */

#include "Professor.h"

Professor::Professor(sf::Vector2f position)
: m_sprite(sf::seconds(0.15), true, false), m_offset(sf::Vector2f(8, 12)),
Actor(position, 5, 48, 10) {
    m_texture.loadFromFile("resources/actors/prof_dunkleheld.png");

    auto anim = &(m_animations["S"]);
    anim->setSpriteSheet(m_texture);
    anim->addFrame(sf::IntRect(0, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(0, 16 * 1, 16, 16));
    anim->addFrame(sf::IntRect(0, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(0, 16 * 2, 16, 16));
    anim = &(m_animations["E"]);
    anim->setSpriteSheet(m_texture);
    anim->addFrame(sf::IntRect(16, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(16, 16 * 1, 16, 16));
    anim->addFrame(sf::IntRect(16, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(16, 16 * 2, 16, 16));
    anim = &(m_animations["N"]);
    anim->setSpriteSheet(m_texture);
    anim->addFrame(sf::IntRect(32, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(32, 16 * 1, 16, 16));
    anim->addFrame(sf::IntRect(32, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(32, 16 * 2, 16, 16));
    anim = &(m_animations["W"]);
    anim->setSpriteSheet(m_texture);
    anim->addFrame(sf::IntRect(48, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(48, 16 * 1, 16, 16));
    anim->addFrame(sf::IntRect(48, 16 * 0, 16, 16));
    anim->addFrame(sf::IntRect(48, 16 * 2, 16, 16));

}

Professor::~Professor() {
}

void Professor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite);

    sf::CircleShape circle(m_size);
    circle.move(m_position.x - m_size, m_position.y - m_size);
    circle.setFillColor(sf::Color(255, 0, 0, 64));
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(0.5);
    target.draw(circle);
}

void Professor::update(sf::Time deltaTime) {

    m_moving.x = 0;
    m_moving.y = 0;

    if (m_movingFlags & Direction::E) m_moving.x += 1;
    if (m_movingFlags & Direction::W) m_moving.x -= 1;
    if (m_movingFlags & Direction::N) m_moving.y -= 1;
    if (m_movingFlags & Direction::S) m_moving.y += 1;

    if (m_moving.x == 1) m_direction = 2;
    if (m_moving.x == -1) m_direction = 6;
    if (m_moving.y == -1) m_direction = 0;
    if (m_moving.y == 1) m_direction = 4;

    switch (m_direction) {
        case 0: m_currentAnimation = &(m_animations["N"]);
            break;
        case 2: m_currentAnimation = &(m_animations["E"]);
            break;
        case 4: m_currentAnimation = &(m_animations["S"]);
            break;
        case 6: m_currentAnimation = &(m_animations["W"]);
            break;
        default: m_currentAnimation = &(m_animations["S"]);
            break;
    }

    move(deltaTime);
    m_sprite.setPosition(m_position - m_offset);
    m_sprite.play(*m_currentAnimation);
    if (m_moving == sf::Vector2f(0, 0)) m_sprite.stop();
    m_sprite.update(deltaTime);
}

void Professor::setPosition(sf::Vector2f position) {
    m_position = position;
    m_sprite.setPosition(m_position - m_offset);
}

float Professor::getDepth() {
    return m_position.y + m_size - 2;
}

void Professor::onCollide(Actor* target) {
    move(-resoleCollision(target->m_position, target->getSize()));
}
