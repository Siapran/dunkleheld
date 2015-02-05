/* 
 * File:   GameObject.h
 * Author: siapran
 *
 * Created on February 2, 2015, 3:59 PM
 */

#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include <vector>
#include <set>
#include <SFML/Graphics.hpp>

#include "tinyXML/tinyxml.h"
//#include "Actor.h"
//#include "GameLevel.h"

class GameLevel;
class Actor;

class GameObject {
public:
    GameObject(GameLevel *level = nullptr);
    virtual ~GameObject();

    virtual void loadFromXML(TiXmlElement *node) = 0;

    virtual void evaluate();
    virtual void update(sf::Time deltaTime);
    void listen(std::string target);
    void ignore(std::string target);

    virtual void use(Actor *user) = 0;
    virtual void showDescription() = 0;
    virtual std::string getContext() = 0;

    void addChild(GameObject *child);

protected:

    GameLevel *m_level;
    std::string m_name;

    std::vector<GameObject *> m_children;
    GameObject *m_parent;

    std::set<std::string> m_listening;

    void setParent(GameObject *parent);

};

#endif	/* GAMEOBJECT_H */

