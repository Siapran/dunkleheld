/* 
 * File:   Trigger.h
 * Author: siapran
 *
 * Created on February 2, 2015, 7:52 PM
 */

#ifndef TRIGGER_H
#define	TRIGGER_H

#include "GameObject.h"

class Trigger : public GameObject {
public:
    Trigger(GameLevel *level, TiXmlElement *triggerElement);

private:

    // TODO: implement condition expression and listeners
};

#endif	/* TRIGGER_H */

