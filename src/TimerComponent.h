#ifndef BUBBLY_CLOCKCOMPONENT_H
#define BUBBLY_CLOCKCOMPONENT_H


#include "engine/Component.h"
#include "CounterComponent.h"
#include "engine/Clock.h"

using namespace Bubbly;

class TimerComponent : public Component {
private:
    //sf::Text text;
    Clock clock;
    const float time;
    bool timeExceeded;
    CounterComponent &bubbleCounter;
public:
    TimerComponent(GameObject &, CounterComponent &, float time);

    void draw();
};

#endif
