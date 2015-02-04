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

    virtual void update(std::vector<std::string>& events);
    void listen(std::string target);
    void ignore(std::string target);

    virtual void use(Actor *user);
    virtual void showDescription();
    virtual std::string getContext();
    
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
