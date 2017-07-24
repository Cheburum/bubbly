//
// Created by cheburum on 24.07.17.
//

#ifndef SHOOTINGGALLERY_BUBBLECOUNTERCOMPONENT_H
#define SHOOTINGGALLERY_BUBBLECOUNTERCOMPONENT_H


#include "Component.h"

class CounterComponent : public Component{
private:
    unsigned int count;
public:
    CounterComponent(GameObject&);
    void operator++();
    void operator--();
    unsigned int getCount()const;
};


#endif //SHOOTINGGALLERY_BUBBLECOUNTERCOMPONENT_H
