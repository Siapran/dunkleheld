/* 
 * File:   Prop.h
 * Author: siapran
 *
 * Created on January 31, 2015, 9:32 PM
 */

#ifndef PROP_H
#define	PROP_H

#include <map>

class Prop : public sf::Drawable, public sf::Transformable {
public:
    Prop();
    Prop(const Prop& orig);
    virtual ~Prop();
private:
    
    std::string m_name;
    sf::Vector2f m_center;

    std::vector<Frame> m_frames;
    sf::Texture *m_texture;
    
    std::map<std::string, PropState> m_states;
};

class PropState {
public:
    std::string name;

private:
    
    std::map<std::string, std::string> m_descriptions;
    std::vector<sf::FloatRect> m_hitBoxes;
    std::map<std::string, PropAction> m_actions;

};

class PropAction {
public:
    std::string name;
public:
    
};

#endif	/* PROP_H */

