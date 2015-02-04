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

struct PropState;
struct PropAction;

class Prop : public GameObject, public Paintable {
public:

    Prop(const char* fileName);
    Prop(const Prop& orig);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getDepth();

    virtual void update(sf::Time deltaTime, std::vector<std::string>& events);
    
    

private:

    AnimatedSprite m_sprite;
    sf::Texture *m_texture;

    std::map<std::string, PropState> m_states; // nom état -> état
    std::string m_currentState; // état actuel
    std::string m_currentAction; // éction en cours
};

struct PropState {
    std::string name;
    std::map<std::string, std::string> descriptions; // langue -> description
    std::vector<sf::FloatRect> hitBoxes; // liste de hitboxes
    std::map<std::string, PropAction> actions; // nom action -> action
    Animation animation; // animation
};

struct PropAction {
    std::string name;
    std::map<std::string, std::string> descriptions; // langue -> description
    Animation animation; // animation
};

#endif	/* PROP_H */

