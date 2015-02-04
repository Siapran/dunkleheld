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

GameLevel::GameLevel(Game *game, const char *fileName, TileSet &tileSet, Professor &player)
: m_tileSet(tileSet), m_player(&player), m_game(game) {
    loadFromXml(fileName);
}

GameLevel::~GameLevel() {
    for (auto& object : m_objects)
        delete object.second;
}

void GameLevel::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    //    sf::Clock timer;

    states.transform *= getTransform();
    states.texture = m_tileSet.getTileSheet();

    // on crée un vecteur pour contenir tout ce qu'on va peindre.
    std::vector<Paintable *> paintables;
    // vector::reserve alloue la place nécessaire mais ne change pas la taille du vector
    // on perd en mémoire... mais on gagne en vitesse!
    paintables.reserve(m_size.x * m_size.y + m_objects.size() + 2);

    for (auto &row : m_tileMap)
        for (auto &tile : row)
            if (tile != nullptr) // on n'ajoute pas les tiles vides
                paintables.push_back(tile);
    for (auto &pair : m_objects) {
        Paintable *paintable = dynamic_cast<Paintable*> (pair.second);
        if (paintable) // on n'ajoute que les objets peignables
            paintables.push_back(paintable);
    }
    if (m_player != nullptr)
        paintables.push_back(m_player);



    // on trie les entités à peindre pour peindre les entités derrièrre en premier
    std::sort(paintables.begin(), paintables.end(), [](Paintable * a, Paintable * b) -> bool {
        // on trie par ordre décroissant de distance à la caméra
        return a->getDepth() < b->getDepth();
    });

    // on peint les entités dans le bon ordre
    for (auto &paintable : paintables)
        paintable->draw(target, states);

    //    std::cout << timer.restart().asMicroseconds() << std::endl;

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
                        ? nullptr // tile vide
                        : new Tile(tile, sf::Vector2f(j * 16, i * 16))); // copie du tile

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

int GameLevel::getVar(std::string varName) {
    auto found = m_localVars.find(varName);
    if (found != m_localVars.end())
        return found->second;
    else return 0;
}

void GameLevel::setVar(std::string varName, int value) {
    m_localVars[varName] = value;
}

int GameLevel::evalExpr(const char *expr) {
    std::string token = "";
    std::string op = "+";
    int tmp = 0;
    for (reader = expr; reader != nullptr; ++reader) {
        if (*reader == '(')
            tmp = evalOp(tmp, evalExpr(reader + 1), op);

    }
    return 0
}

int GameLevel::evalOp(int left, int right, std::string op) {

    if (op == "+") return left + right;
    if (op == "-") return left - right;
    if (op == "*") return left * right;
    if (op == "/") return left / right;

    if (op == "==") return left == right;
    if (op == "!=") return left != right;
    if (op == "<") return left < right;
    if (op == ">") return left > right;
    if (op == "<=") return left <= right;
    if (op == ">=") return left >= right;

    if (op == "&&") return left && right;
    if (op == "||") return left || right;
    if (op == "^") return left ^ right;
    if (op == "!") return !right;

    return 0;
}

std::string GameLevel::readToken() {
    std::string token = "";
    for (; reader != nullptr; ++reader) {
        if (
                (*reader >= 'a' && *reader <= 'z')
                || (*reader >='A' && *reader <= 'Z')
                || (*reader >='0' && *reader <= '9')
                || *reader == '_')
    }
}
