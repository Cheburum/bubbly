#ifndef BUBBLY_BUBBLECOMPONENT_H
#define BUBBLY_BUBBLECOMPONENT_H

#include "engine/Component.h"
#include "engine/PhysComponent.h"
#include "CounterComponent.h"

class BubbleComponent : public Component {
private:
    std::weak_ptr<PhysComponent> physComponent;
    CounterComponent &counter;
    sf::Clock clock;
public:
    BubbleComponent(GameObject &, CounterComponent &counter);

    void update();
};


#endif //SHOOTINGGALLERY_BUBBLECOMPONENT_H
