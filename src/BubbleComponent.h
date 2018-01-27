#ifndef BUBBLY_BUBBLECOMPONENT_H
#define BUBBLY_BUBBLECOMPONENT_H

#include "engine/Component.h"
#include "engine/PhysComponent.h"
#include "CounterComponent.h"
#include "engine/Clock.h"

using namespace Bubbly;

class BubbleComponent : public Component {
private:
    std::weak_ptr<PhysComponent> physComponent;
    CounterComponent &counter;
    Clock clock;
public:
    BubbleComponent(GameObject &, CounterComponent &counter);

    void update();
};


#endif
