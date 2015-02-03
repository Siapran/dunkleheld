/* 
 * File:   Professor.cpp
 * Author: siapran
 * 
 * Created on February 3, 2015, 10:27 AM
 */

#include "Professor.h"

Professor::Professor() : m_sprite(sf::seconds(0.2), true, false) {
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

}

void Professor::update(sf::Time deltaTime) {

}
