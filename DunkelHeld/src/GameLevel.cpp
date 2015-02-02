/* 
 * File:   GameLevel.cpp
 * Author: siapran
 * 
 * Created on January 22, 2015, 9:01 PM
 */

#include "GameLevel.h"
#include "tinyXML/tinyxml.h"
#include "Paintable.h"
#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

GameLevel::GameLevel(const char *fileName, TileSet &tileSet)
: m_tileSet(tileSet) {
    loadFromXml(fileName);
}

GameLevel::~GameLevel() {
}

void GameLevel::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Clock timer;

    states.transform *= getTransform();
    states.texture = m_tileSet.getTileSheet();

    // on crée un vecteur pour contenir tout ce qu'on va peindre.
    std::vector<Paintable *> paintables;
    paintables.reserve(m_size.x * m_size.y + m_objects.size());

    auto cp_it = paintables.begin();
    for (auto &row : m_tileMap)
        for (auto &tile : row)
            if (tile != nullptr)
                paintables.push_back(tile);
    for (auto &pair : m_objects) {
        Paintable *paintable = dynamic_cast<Paintable*> (pair.second);
        if (paintable)
            paintables.push_back(paintable);
    }

    std::sort(paintables.begin(), paintables.end(), [](Paintable * a, Paintable * b) -> bool {
        return a->getDepth() < b->getDepth();
    });

    for (auto &paintable : paintables)
        paintable->draw(target, states);

    std::cout << timer.restart().asMicroseconds() << std::endl;
    //    for (int i = 0; i < m_size.y; ++i) {
    //        auto &row = m_tileMap[i];
    //        for (int j = 0; j < m_size.x; ++j) {
    //            auto tile = row[j];
    //            if (tile != nullptr)
    //                tile->draw(target, states);
    //        }
    //    }
}

void GameLevel::loadFromXml(const char* fileName) {
    TiXmlDocument doc(fileName);
    doc.LoadFile();

    TiXmlNode *root = doc.RootElement();
    TiXmlElement *tileMapLayer = root->FirstChildElement("layer");

    std::string tmpStr = "Tiles";

    if (tmpStr == tileMapLayer->Attribute("name")) {

        TiXmlElement *tileMapIterator = tileMapLayer->FirstChildElement("data");
        tileMapIterator = tileMapIterator->FirstChildElement("tile");

        tileMapLayer->Attribute("width", &(m_size.x));
        tileMapLayer->Attribute("height", &(m_size.y));

        m_tileMap.resize(m_size.y);
        for (int i = 0; i < m_size.y; ++i) {
            m_tileMap[i].resize(m_size.x);

            for (int j = 0; j < m_size.x; ++j) {
                int gid;
                tileMapIterator->Attribute("gid", &gid);

                auto tile = m_tileSet[gid];
                m_tileMap[i][j] = ((tile == nullptr)
                        ? tile
                        : new Tile(tile, sf::Vector2f(j * 16, i * 16)));

                std::cout << gid << "\t";
                tileMapIterator = tileMapIterator->NextSiblingElement("tile");
            }
            std::cout << std::endl;
        }
    }
}

void GameLevel::addListener(std::string target, GameObject* listener) {

}

void GameLevel::removeListener(std::string target, GameObject* listener) {

}

void GameLevel::broadCastEvent(std::string source, std::string event) {

}