/* 
 * File:   GameLevel.cpp
 * Author: siapran
 * 
 * Created on January 22, 2015, 9:01 PM
 */

#include "GameLevel.h"
#include "tinyXML/tinyxml.h"

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
    states.transform *= getTransform();
    states.texture = m_tileSet.getTileSheet();
    for (int i = 0; i < m_size.y; ++i) {
        auto &row = m_tileMap[i];
        for (int j = 0; j < m_size.x; ++j) {
            auto tile = row[j];
            if (tile != nullptr)
                tile->draw(target, states);
        }
    }
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
