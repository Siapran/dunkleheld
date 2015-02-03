/* 
 * File:   Controller.cpp
 * Author: siapran
 * 
 * Created on February 3, 2015, 9:10 AM
 */

#include "Controller.h"
#include <algorithm>

const char *Controller::KEY_NAMES[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9", "Escape", "LControl", "LShift", "LAlt", "LSystem", "RControl", "RShift", "RAlt", "RSystem", "Menu", "LBracket", "RBracket", "SemiColon", "Comma", "Period", "Quote", "Slash", "BackSlash", "Tilde", "Equal", "Dash", "Space", "Return", "BackSpace", "Tab", "PageUp", "PageDown", "End", "Home", "Insert", "Delete", "Add", "Subtract", "Multiply", "Divide", "Left", "Right", "Up", "Down", "Numpad0", "Numpad1", "Numpad2", "Numpad3", "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8", "Numpad9", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15", "Pause"};




sf::Keyboard::Key Controller::getKeyFromName(std::string keyName) {
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
        if (keyName == KEY_NAMES[i])
            return (sf::Keyboard::Key) i;
    return (sf::Keyboard::Key) -1;
}

std::string Controller::getNameFromKey(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Unknown)
        return "Unknown";
    return KEY_NAMES[key];
}

void Controller::handleInput(sf::Keyboard::Key key, bool isPressed) {
    
}

Controller::Controller() {
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
}

