/* 
 * File:   Tile.cpp
 * Author: siapran
 * 
 * Created on January 22, 2015, 9:15 PM
 */

#include "Tile.h"
#include <iostream>

Tile::Tile(int gid, sf::Vector2f position, sf::Texture *texture, sf::FloatRect &texCoords)
: m_position(position), m_gid(gid), m_vertices(sf::Quads, 4), m_texture(texture) {

    m_vertices[0].position = position;
    m_vertices[1].position = sf::Vector2f(position.x, position.y + texCoords.height);
    m_vertices[2].position = sf::Vector2f(position.x + texCoords.width, position.y + texCoords.height);
    m_vertices[3].position = sf::Vector2f(position.x + texCoords.width, position.y);

    m_vertices[0].texCoords = sf::Vector2f(texCoords.left, texCoords.top);
    m_vertices[1].texCoords = sf::Vector2f(texCoords.left, texCoords.top + texCoords.height);
    m_vertices[2].texCoords = sf::Vector2f(texCoords.left + texCoords.width, texCoords.top + texCoords.height);
    m_vertices[3].texCoords = sf::Vector2f(texCoords.left + texCoords.width, texCoords.top);

    depth = 0;
    for (const sf::FloatRect &box : m_hitBoxes)
        if (box.top + box.height > depth)
            depth = box.top + box.height;
    dirty = false;
    
}

Tile::Tile(Tile *orig, sf::Vector2f position)
: Tile(*orig) {
    // on réajuste les positions des vertices
    for (int i = 0; i < 4; i++) {
        m_vertices[i].position.x = m_vertices[i].position.x - m_position.x + position.x;
        m_vertices[i].position.y = m_vertices[i].position.y - m_position.y + position.y;
    }
    // même chose pour les hitboxes
    for (sf::FloatRect &box : m_hitBoxes) {
        box.left = box.left - m_position.x + position.x;
        box.top = box.top - m_position.y + position.y;
    }
    m_position = position;
    
    depth = 0;
    for (const sf::FloatRect &box : m_hitBoxes)
        if (box.top + box.height > depth)
            depth = box.top + box.height;
    dirty = false;
    
}

Tile::~Tile() {
}

void Tile::addHitBox(sf::FloatRect hitBox) {
    hitBox.left += m_position.x;
    hitBox.top += m_position.y;
    m_hitBoxes.push_back(hitBox);
}

// les positions sont déjà calculées donc il suffit de faire
//  box.intersects pour chaque hitbox

bool Tile::collidesWith(sf::FloatRect& hitBox) const {
    for (const sf::FloatRect &box : m_hitBoxes)
        if (box.intersects(hitBox))
            return true;
    return false;
}

int Tile::getGid() const {
    return m_gid;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //    std::cout << "DEBUG " << m_gid << std::endl;
    target.draw(m_vertices, states);

//    for (const sf::FloatRect &hitbox : m_hitBoxes) {
//        sf::RectangleShape box(sf::Vector2f(hitbox.width, hitbox.height));
//        box.move(hitbox.left, hitbox.top);
//        box.setFillColor(sf::Color(255, 0, 0, 64));
//        box.setOutlineColor(sf::Color::Red);
//        box.setOutlineThickness(0.5);
//        target.draw(box);
//    }
}

float Tile::getDepth() {
    // on ne déplace pas un tile donc depth est constant
    return depth;
}
