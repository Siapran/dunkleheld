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

class Prop : public sf::Drawable, public sf::Transformable {
public:

    Prop();
    Prop(const Prop& orig);
    virtual ~Prop();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    std::string m_name;
    sf::Vector2f m_center;

    sf::Time m_frameTime; // temps entre chaque frame
    std::vector<sf::Sprite> m_frames; // liste de frames
    sf::Texture *m_texture;

    std::map<std::string, PropState> m_states; // nom état -> état

};

struct PropState {
    std::string name;
    std::map<std::string, std::string> descriptions; // langue -> description
    std::vector<sf::FloatRect> hitBoxes; // liste de hitboxes
    std::map<std::string, PropAction> actions; // nom action -> action
    std::vector<int> animation; // liste d'id de frames
};

struct PropAction {
    std::string name;
    std::map<std::string, std::string> descriptions; // langue -> description
    std::vector<int> animation; // liste d'id de frames
};

#endif	/* PROP_H */

