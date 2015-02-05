/* 
 * File:   GameLevel.h
 * Author: siapran
 *
 * Created on January 22, 2015, 9:01 PM
 */

#ifndef GAMELEVEL_H
#define	GAMELEVEL_H

#include <vector>
#include "Tile.h"
#include "TileSet.h"

#include <vector>
#include "Tile.h"
#include "TileSet.h"
#include "GameObject.h"
#include "Prop.h"
#include "Professor.h"

class Game;

enum TokenType {
    INT, STR, OBJ, OP, PAR, UNKNOWN, EXPREND
};

struct Token {
    TokenType type;
    std::string value;
    std::string strVal;
    std::string objVal;
    int intVal;
};

class GameLevel : public sf::Drawable, public sf::Transformable {
public:

    GameLevel(Game *game, const char *fileName, TileSet &tileSet, Professor &player);
    virtual ~GameLevel();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void broadCastEvent(std::string source, std::string event);

    void addListener(std::string target, GameObject *listener);
    void removeListener(std::string target, GameObject *listener);

    void setVar(std::string varName, int value);
    int getVar(std::string varName);
    bool isSet(std::string varName);

private:

    void loadFromXml(const char *fileName);

    std::vector<std::vector<Tile *> > m_tileMap;
    TileSet &m_tileSet;
    sf::Vector2i m_size;



    Prop *findProp(std::string propName);
    std::multimap<std::string, GameObject *> m_listeners;
    std::map<std::string, GameObject *> m_objects;
    std::map<std::string, int> m_localVars;

    Game *m_game;
    Professor *m_player;

    // pour l'interprétation d'expression
    int evalExpr(const char *expression);
    Token readToken();
    int evalOp(int left, int right, std::string op);
    const char* reader;
};

#endif	/* GAMELEVEL_H */

