/* 
 * File:   Prop.h
 * Author: siapran
 *
 * Created on January 31, 2015, 9:32 PM
 */

#ifndef PROP_H
#define	PROP_H

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "tinyXML/tinyxml.h"
#include "GameObject.h"
#include "Paintable.h"
#include "AnimatedSprite.h"
#include "Collidable.h"

class Game;

struct PropState;
struct PropAction;

class Prop : public GameObject, public Paintable, public Collidable {
public:

    Prop(const char* fileName);
    Prop(const Prop* orig, GameLevel *level);

    virtual void loadFromXML(TiXmlElement* node);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getDepth();

    virtual void update(sf::Time deltaTime);
    void setPosition(float x, float y);

    void setState(std::string stateName);
    std::string getState();
    void doAction(std::string actionName);

    virtual std::string getContext();
    virtual void showDescription();
    virtual void use(Actor* user);


    virtual bool collidesWithCircle(sf::Vector2f pos, float radius);
    virtual sf::Vector2f resoleCollision(sf::Vector2f pos, float radius);
    virtual void onCollide(Actor* target);


private:

    AnimatedSprite m_sprite;
    sf::Texture *m_texture;

    std::map<std::string, PropState *> m_states; // nom état -> état
    std::string m_currentState; // état actuel
    std::string m_currentAction; // éction en cours
};

struct PropState {
    std::string name;
    std::map<std::string, std::string> descriptions; // langue -> description
    std::vector<sf::FloatRect> hitBoxes; // liste de hitboxes
    std::map<std::string, PropAction> actions; // nom action -> action
    Animation animation; // animation
    float depth;
    bool damage;
    bool solid;
};

struct PropAction {
    std::string name;
    std::string state;
    bool playerUse;
    bool golemUse;
    std::map<std::string, std::string> descriptions; // langue -> description
    Animation animation; // animation
};

#endif	/* PROP_H */

