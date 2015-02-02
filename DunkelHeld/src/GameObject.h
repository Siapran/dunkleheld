/* 
 * File:   GameObject.h
 * Author: siapran
 *
 * Created on February 2, 2015, 3:59 PM
 */

#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

class GameObject {
public:
    GameObject();
    GameObject(const GameObject& orig);
    virtual ~GameObject();

    
    virtual void update(std::vector<std::string>& events);
    
protected:

    std::string m_name;
    std::vector<GameObject> m_children;
    
};

#endif	/* GAMEOBJECT_H */

