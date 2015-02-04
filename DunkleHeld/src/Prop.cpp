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
    std::string imgfile = root->Attribute("file");
    m_texture = new sf::Texture;
    m_texture->loadFromFile(imgfile);

    std::vector<sf::FloatRect> hitBoxes;

    bool rootdamage = false, rootsolid = true;
    int rootdepth = 0;

    TiXmlElement *propertiesNode = root->FirstChildElement("properties");
    if (propertiesNode != nullptr) {
        std::string tmpstr = "true";
        const char *tmp;
        if (tmp = propertiesNode->Attribute("damage")) rootdamage = tmpstr == tmp;
        if (tmp = propertiesNode->Attribute("solid")) rootsolid = tmpstr == tmp;
        propertiesNode->Attribute("depth", &rootdepth);
    }

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
            stateNode = stateNode->NextSiblingElement("state")) {
        std::string name = stateNode->Attribute("name");
        PropState *state = &(m_states[name]);
        state->name = name;

        TiXmlElement *propertiesNode = stateNode->FirstChildElement("properties");
        state->damage = rootdamage;
        state->depth = rootdepth;
        state->solid = rootsolid;
        if (propertiesNode != nullptr) {
            std::string tmpstr = "true";
            const char *tmp;
            if (tmp = propertiesNode->Attribute("damage")) state->damage = tmpstr == tmp;
            if (tmp = propertiesNode->Attribute("solid")) state->solid = tmpstr == tmp;
            int depth = 0;
            propertiesNode->Attribute("depth", &depth);
            state->depth = depth;
        }

        for (
                TiXmlElement *descNode = stateNode->FirstChildElement("description");
                descNode != nullptr;
                descNode = descNode->NextSiblingElement("description")) {
            std::string lang = descNode->Attribute("lang");
            state->descriptions[lang] = descNode->GetText();
        }

        state->hitBoxes.insert(state->hitBoxes.end(), hitBoxes.begin(), hitBoxes.end());
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
            state->hitBoxes.push_back(sf::FloatRect(x, y, width, height));
        }

        TiXmlElement *stateAnimationNode = stateNode->FirstChildElement("animation");
        if (stateAnimationNode->GetText() != nullptr) {
            std::string animText = stateAnimationNode->GetText();

            std::string numstr = "";
            int num = 0;
            for (const char cur : animText)
                if (cur >= '0' && cur <= '9')
                    numstr += cur;
                else {
                    num = std::atoi(numstr.c_str());
                    state->animation.addFrame(frames[num]);
                    numstr = "";
                }
            num = std::atoi(numstr.c_str());
            state->animation.addFrame(frames[num]);
        }

        for (
                TiXmlElement *actionNode = stateNode->FirstChildElement("action");
                actionNode != nullptr;
                actionNode = stateNode->NextSiblingElement("action")) {

            std::string actionName = actionNode->Attribute("name");
            PropAction *action = &(state->actions[actionName]);
            action->name = actionName;
            action->state = actionNode->Attribute("state");

            std::string tmpstr = "true";
            const char* tmp;
            if (tmp = actionNode->Attribute("playeruse")) action->playerUse = tmpstr == tmp;
            if (tmp = actionNode->Attribute("golemuse")) action->golemUse = tmpstr == tmp;

            for (
                    TiXmlElement *descNode = actionNode->FirstChildElement("description");
                    descNode != nullptr;
                    descNode = descNode->NextSiblingElement("description")) {
                std::string lang = descNode->Attribute("lang");
                action->descriptions[lang] = descNode->GetText();
            }

            TiXmlElement *animationNode = actionNode->FirstChildElement("animation");
            const char *text = animationNode->GetText();
            if (text != nullptr) {
                std::string animText = text;

                std::string numstr = "";
                int num = 0;
                for (const char cur : animText)
                    if (cur >= '0' && cur <= '9')
                        numstr += cur;
                    else {
                        num = std::atoi(numstr.c_str());
                        action->animation.addFrame(frames[num]);
                        numstr = "";
                    }
                num = std::atoi(numstr.c_str());
                action->animation.addFrame(frames[num]);
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

std::string Prop::getContext() {

}

void Prop::loadFromXML(TiXmlElement* node) {

}

void Prop::showDescription() {

}

void Prop::use(Actor* user) {
    
}
