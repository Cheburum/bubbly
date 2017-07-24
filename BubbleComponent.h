//
// Created by cheburum on 23.07.17.
//

#ifndef SHOOTINGGALLERY_BUBBLECOMPONENT_H
#define SHOOTINGGALLERY_BUBBLECOMPONENT_H


#include "Component.h"
#include "PhysComponent.h"

class BubbleComponent : public Component {
private:
    PhysComponent* physComponent;
    sf::Clock clock;
public:
    BubbleComponent(GameObject&);
    void update();
};


#endif //SHOOTINGGALLERY_BUBBLECOMPONENT_H
