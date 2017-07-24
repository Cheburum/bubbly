//
// Created by cheburum on 23.07.17.
//

#ifndef SHOOTINGGALLERY_BUBBLECOMPONENT_H
#define SHOOTINGGALLERY_BUBBLECOMPONENT_H


#include "Component.h"
#include "PhysComponent.h"
#include "CounterComponent.h"

class BubbleComponent : public Component {
private:
    PhysComponent* physComponent;
    CounterComponent& counter;
    sf::Clock clock;
public:
    BubbleComponent(GameObject&,CounterComponent& counter);
    void update();
};


#endif //SHOOTINGGALLERY_BUBBLECOMPONENT_H
