/* 
 * File:   Prop.cpp
 * Author: siapran
 * 
 * Created on January 31, 2015, 9:32 PM
 */

#include "Prop.h"

Prop::Prop(const char* fileName) {

}

Prop::Prop(GameLevel* level, const Prop& orig, TiXmlElement) {

}

void Prop::update(std::vector<std::string>& events) {

}

void Prop::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}

float Prop::getDepth() {
    if (ground) return -1;
    if (dirty) {
        depth = 0;
        for (auto& box : m_states.at(m_currentState).hitBoxes)
            if (box.top + box.height > depth)
                depth = box.top + box.height;
        dirty = false;
    }
    return depth;
}
