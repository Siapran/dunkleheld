/* 
 * File:   Professor.h
 * Author: siapran
 *
 * Created on February 3, 2015, 10:27 AM
 */

#ifndef PROFESSOR_H
#define	PROFESSOR_H

#include "Actor.h"

class Professor : public Actor {
public:
    Professor();
    virtual ~Professor();
    

    virtual void update(sf::Time deltaTime);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getDepth();
    
private:

    
    
};

#endif	/* PROFESSOR_H */

