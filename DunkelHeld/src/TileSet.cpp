/* 
 * File:   TileSet.cpp
 * Author: siapran
 * 
 * Created on January 23, 2015, 4:30 PM
 */

#include "TileSet.h"
#include "tinyXML/tinyxml.h"
#include <iostream>

TileSet::TileSet(const char* fileName) {
    std::vector<Tile*>();

    // on interprète le fichier xml
    TiXmlDocument doc(fileName);
    doc.LoadFile();
    TiXmlElement *tileset = doc.RootElement();

    // on initialise le nom du tileset et la taille des tiles
    m_name = tileset->Attribute("name");
    tileset->Attribute("tilewidth", &(m_tileSize.x));
    tileset->Attribute("tileheight", &(m_tileSize.y));

    TiXmlElement *image = tileset->FirstChildElement("image");

    // chargement de la texture
    m_tileSheet.loadFromFile(image->Attribute("source"));
    // on déduis la taille à partir de la texture
    m_sheetSize.x = m_tileSheet.getSize().x;
    m_sheetSize.y = m_tileSheet.getSize().y;

    // on explore les tiles tant qu'on en trouve
    for (
            TiXmlElement *tileNode = tileset->FirstChildElement("tile");
            tileNode != nullptr;
            tileNode = tileNode->NextSiblingElement("tile")) {

        // on récupère le id et on en déduit les coordonnées de texture
        int id;
        tileNode->Attribute("id", &id);

        int g_width = m_sheetSize.x / m_tileSize.x;
        //        int g_height = m_sheetSize.y / m_tileSize.y;

        sf::FloatRect texCoords(
                id % g_width * m_tileSize.x,
                id / g_width * m_tileSize.y,
                m_tileSize.x, m_tileSize.y);

        // on crée le tile
        Tile *tile = new Tile(id + 1, sf::Vector2f(0, 0), &m_tileSheet, texCoords);

        // on explore les hitBox tant qu'on en trouve
        for (
                TiXmlElement *boxNode = tileNode->FirstChildElement("box");
                boxNode != nullptr;
                boxNode = boxNode->NextSiblingElement("box")) {

            // on ajoute la hitbox
            int x, width, y, height;
            boxNode->Attribute("x", &x);
            boxNode->Attribute("y", &y);
            boxNode->Attribute("width", &width);
            boxNode->Attribute("height", &height);
            tile->addHitBox(sf::FloatRect(x, y, width, height));
        }

        if (this->size() <= id + 1) {
            this->resize(id + 2);
        }

        this->at(id + 1) = tile;

    }

}

TileSet::~TileSet() {
    for (auto itr = begin(); itr != end(); ++itr) {
        delete *itr;
    }
}

sf::Texture* TileSet::getTileSheet() {
    return &m_tileSheet;
}
