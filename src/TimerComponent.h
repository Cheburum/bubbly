#ifndef BUBBLY_CLOCKCOMPONENT_H
#define BUBBLY_CLOCKCOMPONENT_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "engine/Component.h"
#include "CounterComponent.h"

class TimerComponent : public Component {
private:
    sf::Text text;
    sf::Clock clock;
    const float time;
    bool timeExceeded;
    CounterComponent &bubbleCounter;
public:
    TimerComponent(GameObject &, CounterComponent &, float time);

    void draw();
};


#endif //SHOOTINGGALLERY_CLOCKCOMPONENT_H
