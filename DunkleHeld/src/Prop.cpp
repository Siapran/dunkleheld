/* 
 * File:   Prop.cpp
 * Author: siapran
 * 
 * Created on January 31, 2015, 9:32 PM
 */

#include "Prop.h"

Prop::Prop(const char* fileName) {
    TiXmlDocument doc(fileName);
    doc.LoadFile();

    TiXmlElement *root = doc.RootElement();
    m_name = root->Attribute("name");
    m_texture->loadFromFile(root->Attribute("file"));

    std::vector<sf::FloatRect> hitBoxes;

    for (
            TiXmlElement *boxNode = root->FirstChildElement("hitbox");
            boxNode != nullptr;
            boxNode = boxNode->NextSiblingElement("hitbox")) {

        // on ajoute la hitbox
        int x = 0, width = 0, y = 0, height = 0;
        boxNode->Attribute("x", &x);
        boxNode->Attribute("y", &y);
        boxNode->Attribute("width", &width);
        boxNode->Attribute("height", &height);
        hitBoxes.push_back(sf::FloatRect(x, y, width, height));
    }

    TiXmlElement *frameNode = root->FirstChildElement("frames");
    int xoff = 0, xsize = 0, yoff = 0, ysize = 0, t = 0;
    frameNode->Attribute("xoff", &xoff);
    frameNode->Attribute("yoff", &yoff);
    frameNode->Attribute("xsize", &xsize);
    frameNode->Attribute("ysize", &ysize);
    frameNode->Attribute("t", &t);

    m_sprite.setFrameTime(sf::milliseconds(t));

    std::vector<sf::IntRect> frames;
    for (
            frameNode = frameNode->FirstChildElement("frame");
            frameNode != nullptr;
            frameNode = frameNode->NextSiblingElement("frame")) {

        int id = 0;
        frameNode->Attribute("id", &id);
        if (id >= frames.size()) frames.resize(id + 1);
        int x = 0, y = 0;
        frameNode->Attribute("x", &x);
        frameNode->Attribute("y", &y);
        frames[id].left = xoff + x * xsize;
        frames[id].top = yoff + y * ysize;
        frames[id].width = xsize;
        frames[id].height = ysize;
    }

    for (
            TiXmlElement *stateNode = root->FirstChildElement("state");
            stateNode != nullptr;
            stateNode = frameNode->NextSiblingElement("state")) {
        std::string name = frameNode->Attribute("name");
        PropState *state = &(m_states[name]);
        state->name = name;

        for (
                TiXmlElement *descNode = stateNode->FirstChildElement("description");
                descNode != nullptr;
                descNode = frameNode->NextSiblingElement("description")) {
            std::string lang = descNode->Attribute("lang");
            state->descriptions[lang] = descNode->GetText();
        }

        TiXmlElement *animationNode = frameNode->FirstChildElement("animation");
        if (animationNode->GetText() != nullptr) {
            std::string animText = animationNode->GetText();

            std::string numstr = "";
            int num = 0;
            for (char cur : animText)
                if (cur >= "0" && cur <= "9")
                    numstr += cur;
                else {
                    num = std::atoi(numstr.c_str());
                    state->animation.addFrame(frames[num]);
                }
            num = std::atoi(numstr.c_str());
            state->animation.addFrame(frames[num]);
        }
        
        for (
                TiXmlElement *actionNode = stateNode->FirstChildElement("action");
                actionNode != nullptr;
                actionNode = frameNode->NextSiblingElement("action")) {

            std::string actionName = actionNode->Attribute("name");
            PropAction *action = state->actions[actionName];
            action->name = actionName;
            action->state = actionNode->Attribute("state");
            
            std::string tmpstr = "true";
            char* tmp;
            if (tmp = actionNode->Attribute()) {

            }

            
            for (
                    TiXmlElement *descNode = actionNode->FirstChildElement("description");
                    descNode != nullptr;
                    descNode = frameNode->NextSiblingElement("description")) {
                std::string lang = descNode->Attribute("lang");
                action->descriptions[lang] = descNode->GetText();
            }
        }

    }

}

Prop::Prop(const Prop& orig) {

}

void Prop::update(sf::Time deltaTime, std::vector<std::string>& events) {

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
