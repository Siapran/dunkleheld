/* 
 * File:   Prop.h
 * Author: siapran
 *
 * Created on January 31, 2015, 9:32 PM
 */

#ifndef PROP_H
#define	PROP_H

#include <map>

class Prop {
public:
    Prop();
    Prop(const Prop& orig);
    virtual ~Prop();
private:

    sf::Vector2f m_position;

    sf::Texture *m_texture;
};

class PropState {
public:
    std::string name;

private:
    std::vector<sf::FloatRect> m_hitBoxes;
    std::map<std::string, PropAction> m_actions;

    sf::VertexArray m_vertices;
};

class PropAction {
public:
    std::string name;
public:
    
};

#endif	/* PROP_H */

