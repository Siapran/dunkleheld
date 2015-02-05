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
        PropState *state = new PropState;
        m_states[name] = state;
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

            if (const char *depth = propertiesNode->Attribute("depth")) {
                state->depth = std::atoi(depth);
            }

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

Prop::Prop(const Prop* orig, GameLevel *level) :
m_sprite(sf::seconds(0.1), false, true) {
    m_level = level;
    m_texture = orig->m_texture;
    m_states = orig->m_states;

    m_sprite.setFrameTime(orig->m_sprite.getFrameTime());

    m_parent = nullptr;

    depth = orig->depth;
}

void Prop::update(sf::Time deltaTime) {
    m_sprite.update(deltaTime);
}

void Prop::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite);

    //    sf::RectangleShape box(sf::Vector2f(16, 16));
    //    box.move(m_position.x, m_position.y);
    //    box.setFillColor(sf::Color(255, 0, 0, 64));
    //    box.setOutlineColor(sf::Color::Red);
    //    box.setOutlineThickness(0.5);
    //    target.draw(box);

}

float Prop::getDepth() {
    if (ground) return -1;
    //    return 9001;
    return depth + m_position.y;
}

std::string Prop::getContext() {

}

void Prop::loadFromXML(TiXmlElement* node) {
    //    name = "pebbles" x = "80" y = "112" width = "16" height = "16" state = "frame3" id = "1"
    std::string name = node->Attribute("name");
    std::string state = node->Attribute("state");
    std::string id = node->Attribute("id");
    int x = 0, y = 0;
    node->Attribute("x", &x);
    node->Attribute("y", &y);
    setPosition(x, y);
    m_name = name + "#" + id;
    setState(state);


}

void Prop::showDescription() {

}

void Prop::use(Actor* user) {

}

void Prop::doAction(std::string actionName) {

}

std::string Prop::getState() {
    return m_currentState;
}

void Prop::setState(std::string stateName) {
    m_currentState = stateName;
    depth = m_states[stateName]->depth;
    dirty = true;
    ground = depth == 0;
    m_states[stateName]->animation.setSpriteSheet(*m_texture);
    m_sprite.play(m_states[stateName]->animation);
}

bool Prop::collidesWithCircle(sf::Vector2f pos, float radius) {
    if (m_states[m_currentState]->solid) {
        for (sf::FloatRect box : m_states[m_currentState]->hitBoxes) {
            box.left += m_position.x;
            box.top += m_position.y;
            if (Collidable::collidesBoxVSCircle(box, pos, radius))
                return true;
        }
    }
    return false;
}

void Prop::onCollide(Actor* target) {

}

sf::Vector2f Prop::resoleCollision(sf::Vector2f pos, float radius) {
    sf::Vector2f total;
    sf::Vector2f moved;
    for (sf::FloatRect box : m_states[m_currentState]->hitBoxes) {
        box.left += m_position.x;
        box.top += m_position.y;
        moved = Collidable::resolveBoxVSCircle(box, pos, radius);
        pos += moved;
        total += moved;
    }
    return total;
}

void Prop::setPosition(float x, float y) {
    m_position.x = x;
    m_position.y = y;
    m_sprite.setPosition(m_position);
    dirty = true;
}
