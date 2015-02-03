/* 
 * File:   Controller.h
 * Author: siapran
 *
 * Created on February 3, 2015, 9:10 AM
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <map>
#include <SFML/Graphics.hpp>

#include "Actor.h"

class Controller {
public:
    Controller();
    Controller(const Controller& orig);
    virtual ~Controller();
    
    
    
private:

    typedef void(*void_function_ptr)();

    std::map<sf::Keyboard::Key, void_function_ptr> m_bindings;
    std::map<std::string, void_function_ptr> m_actions;
    
    Actor *m_golem;
    Actor *m_player;
    
    

};

#endif	/* CONTROLLER_H */

