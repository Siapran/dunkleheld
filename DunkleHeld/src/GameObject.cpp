/* 
 * File:   GameObject.cpp
 * Author: siapran
 * 
 * Created on February 2, 2015, 3:59 PM
 */

#include "GameObject.h"
#include "GameLevel.h"

GameObject::GameObject(GameLevel* level) {

}

GameObject::~GameObject() {
    for (auto& child : m_children) {
        delete child;
    }
    for (auto& target : m_listening) {
        ignore(target);
    }
}

void GameObject::addChild(GameObject* child) {
    m_children.push_back(child);
    child->setParent(this);
}

void GameObject::ignore(std::string target) {
    if (m_parent == nullptr) {
        if (m_listening.find(target) != m_listening.end()) {
            m_level->removeListener(target, this);
            m_listening.erase(target);
        }
    } else {
        m_parent->ignore(target);
    }
}

void GameObject::listen(std::string target) {
    if (m_parent == nullptr) {
        if (m_listening.find(target) == m_listening.end()) {
            m_level->addListener(target, this);
            m_listening.insert(target);
        }
    } else {
        m_parent->listen(target);
    }
}

void GameObject::update(sf::Time deltaTime) {
    for (auto& child : m_children) {
        child->update(deltaTime);
    }
}

void GameObject::evaluate() {
    for (auto& child : m_children) {
        child->evaluate();
    }
}


void GameObject::setParent(GameObject* parent) {
    m_parent = parent;
}

