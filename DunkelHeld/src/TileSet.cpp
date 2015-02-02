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

        // on récupère le gid et on en déduit les coordonnées de texture
        int gid;
        tileNode->Attribute("gid", &gid);

        int width = m_sheetSize.x / m_tileSize.x;
        int height = m_sheetSize.y / m_tileSize.y;
        int gnum = gid - 1;

        sf::FloatRect texCoords(
                gnum % width * m_tileSize.x,
                gnum / width * m_tileSize.y,
                m_tileSize.x, m_tileSize.y);

        // on crée le tile
        Tile *tile = new Tile(gid, sf::Vector2f(0, 0), &m_tileSheet, texCoords);

        sf::IntRect hitBox;
        // on explore les hitBox tant qu'on en trouve
        for (
                TiXmlElement *boxNode = tileNode->FirstChildElement("box");
                boxNode != nullptr;
                boxNode = boxNode->NextSiblingElement("box")) {

            // on ajoute la hitbox
            int x1, x2, y1, y2;
            boxNode->Attribute("x1", &x1);
            boxNode->Attribute("y1", &y1);
            boxNode->Attribute("x2", &x2);
            boxNode->Attribute("y2", &y2);
            tile->addHitBox(sf::FloatRect(x1, y1, x2 - x1, y2 - y1));
        }

        if (this->size() <= gid) {
            this->resize(gid + 1);
        }

        this->at(gid) = tile;

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
