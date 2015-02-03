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

    static const char *KEY_NAMES[sf::Keyboard::KeyCount];
    static std::string getNameFromKey(sf::Keyboard::Key key);
    static sf::Keyboard::Key getKeyFromName(std::string keyName);

    void handleInput(sf::Keyboard::Key key, bool isPressed);

private:

    typedef void(*void_function_ptr)();

    std::map<std::string, sf::Keyboard::Key> m_bindings;
    static std::map<std::string, std::pair<void_function_ptr, void_function_ptr>> m_actions;

    void Player1N();
    void Player1S();
    void Player1E();
    void Player1W();
    void Player1Use();
    void Player1Examine();
    void Player1Switch();
    
    void stopPlayer1N();
    void stopPlayer1S();
    void stopPlayer1E();
    void stopPlayer1W();
    void stopPlayer1Use();
    void stopPlayer1Examine();
    void stopPlayer1Switch();
    
    void Player2N();
    void Player2S();
    void Player2E();
    void Player2W();
    void stopPlayer2N();
    void stopPlayer2S();
    void stopPlayer2E();
    void stopPlayer2W();
    
    Actor *m_player1;
    Actor *m_player2;



};

#endif	/* CONTROLLER_H */

