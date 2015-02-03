/* 
 * File:   Paintable.h
 * Author: siapran
 *
 * Created on February 2, 2015, 8:13 PM
 */

#ifndef PAINTABLE_H
#define	PAINTABLE_H

#include <SFML/Graphics.hpp>

class Paintable : public sf::Drawable {
public:

    Paintable();

    // si le Paintable est altéré, dirty = true
    // si le Paintable n'a pas été altéré depuis le dernier calcul, dirty = false
    virtual float getDepth() = 0;
    bool dirty;
    float depth;
    bool ground;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif	/* PAINTABLE_H */

