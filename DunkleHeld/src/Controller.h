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

    static const char *KEY_NAMES[sf::Keyboard::KeyCount];
    static std::string getNameFromKey(sf::Keyboard::Key key);
    static sf::Keyboard::Key getKeyFromName(std::string keyName);

    void handleInput(sf::Keyboard::Key key, bool isPressed);

    void setPlayer1(Actor *player);
    void setPlayer2(Actor *player);
    
    void bindKey(std::string action, sf::Keyboard::Key key);
    
private:

    std::map<std::string, sf::Keyboard::Key> m_bindings;
    
    Actor *m_player1;
    Actor *m_player2;



};

#endif	/* CONTROLLER_H */

