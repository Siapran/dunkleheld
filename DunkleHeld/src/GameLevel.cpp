/* 
 * File:   GameLevel.cpp
 * Author: siapran
 * 
 * Created on January 22, 2015, 9:01 PM
 */

#include <SFML/System/Vector2.hpp>


#include "GameLevel.h"
#include "tinyXML/tinyxml.h"
#include "Paintable.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <ctype.h>

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

    sf::Sprite shadow(m_shadow.getTexture());
    target.draw(shadow);

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
    Token token;
    std::string leftStr = "";
    std::string op = "+";
    int total = 0;
    token = readToken();
    switch (token.type) {
        case PAR:
            ++reader;
            if (token.value == "(") {
                total = evalOp(total, evalExpr(reader), op);
            }
            if (token.value == ")") {
                return total;
            }
            break;
        case EXPREND:
            return total;
            break;
        case INT:
            total = evalOp(total, token.intVal, op);
            break;
        case STR:
            if (op == "+") op = "==";
            if (op == "==") total = leftStr == token.strVal;
            if (op == "!=") total = leftStr != token.strVal;
            leftStr = token.strVal;
            break;
        case OP:
            op = token.value;
            break;
        default:
            throw "INVALID TOKEN";
            return total;
            break;
    }

    return total;
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

Token GameLevel::readToken() {
    Token token;
    if (*reader == '(' || *reader == ')') {
        token.type = TokenType::PAR;
        token.value = *reader++;
    } else if (isdigit(*reader)) {
        token.type = TokenType::INT;
        do {
            token.value += *reader++;
        } while (isdigit(*reader));
        token.intVal = std::atoi(token.value.c_str());
    } else if (isalnum(*reader) || *reader == '_') {
        do {
            token.value += *reader++;
        } while (isalnum(*reader) || *reader == '_');
        if (*reader == '#') {
            token.type = TokenType::OBJ;
            do {
                token.value += *reader++;
            } while (isdigit(*reader));
            token.objVal = token.value;
            token.value = "";
            if (*reader == '.') {
                auto prop = findProp(token.objVal);
                ++reader;
                do {
                    token.value += *reader++;
                } while (isdigit(*reader));
                if (token.value == "state") {
                    token.type = TokenType::STR;
                    token.strVal = prop->getState();
                } else {
                    token.type = TokenType::UNKNOWN;
                }
            } else {
                if (isSet(token.value)) {
                    token.type = TokenType::INT;
                    token.intVal = getVar(token.value);
                } else if (m_game->isSet(token.value)) {
                    token.type = TokenType::INT;
                    token.intVal = m_game->getVar(token.value);
                } else if (token.value == "true") {
                    token.type = TokenType::INT;
                    token.intVal = 1;
                } else if (token.value == "false") {
                    token.type = TokenType::INT;
                    token.intVal = 0;
                } else {
                    token.type = TokenType::STR;
                    token.strVal = token.value;
                }
            }
        }
    } else if (
            *reader == '+' ||
            *reader == '-' ||
            *reader == '*' ||
            *reader == '/' ||

            *reader == '=' ||
            *reader == '!' ||
            *reader == '<' ||
            *reader == '>' ||

            *reader == '&' ||
            *reader == '|' ||
            *reader == '^') {
        token.type = TokenType::OP;
        token.value = *reader;
        if (
                *reader == '=' ||
                *reader == '&' ||
                *reader == '|') {
            token.value += *reader++;
        }
    } else if (*reader == 0) {
        token.type = TokenType::EXPREND;
    } else {
        token.type = TokenType::UNKNOWN;
        token.value = *reader++;
    }
    while (isblank(*reader)) ++reader;
    return token;
}

bool GameLevel::isSet(std::string varName) {
    return m_localVars.find(varName) != m_localVars.end();
}

Prop* GameLevel::findProp(std::string propName) {
    auto found = m_objects.find(propName);
    if (found != m_objects.end()) {
        return dynamic_cast<Prop*> (found->second);
    }
    return nullptr;
}

void GameLevel::queryCollideWith(sf::Vector2f pos, float radius) {
    m_collideQuery.clear();
    auto tilesize = m_tileSet.getTileSize();
    for (int i = (pos.y - radius) / tilesize.y; i <= (pos.y + radius) / tilesize.y; i++)
        for (int j = (pos.x - radius) / tilesize.x; j <= (pos.x + radius) / tilesize.x; j++) {
            if (i >= 0 && i <= m_size.y)
                if (j >= 0 && j <= m_size.x) {
                    auto tile = m_tileMap[i][j];
                    if (tile != nullptr) {
                        if (tile->collidesWithCircle(pos, radius)) {
                            std::cout << "[" << i << "] [" << j << "]" << std::endl;

                            sf::RectangleShape box(sf::Vector2f(tilesize.x, tilesize.y));
                            box.move(i * tilesize.y, j * tilesize.x);
                            box.setFillColor(sf::Color(0, 255, 0, 64));
                            box.setOutlineColor(sf::Color::Green);
                            box.setOutlineThickness(0.5);

                            m_shadow.draw(box);

                            m_collideQuery.push_back(tile);
                        }
                    }
                }
        }

    for (auto &pair : m_objects) {
        Collidable *collidable = dynamic_cast<Collidable*> (pair.second);
        if (collidable) // on n'ajoute que les objets peignables
            if (collidable->collidesWithCircle(pos, radius))
                m_collideQuery.push_back(collidable);
    }

    m_shadow.display();
    std::cout << "DEBUG 1 " << m_collideQuery.size() << std::endl;
}

sf::Vector2i GameLevel::getMapSize() {
    return m_size;
}

void GameLevel::update(sf::Time deltaTime) {
    // collision du professeur avec le golem en premier;
    auto pos = m_player->getPos();
    auto radius = m_player->getSize();

    // puis avec le reste des tiles et objets
    queryCollideWith(pos, radius);

    sf::Vector2f total;
    float num = 0;

    for (auto &collidable : m_collideQuery) {

        total += collidable->resoleCollision(pos, radius);
        ++num;
    }
    if (num != 0)
        m_player->move(total / num);

}
