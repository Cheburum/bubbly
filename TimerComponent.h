//
// Created by cheburum on 19.07.17.
//

#ifndef SHOOTINGGALLERY_CLOCKCOMPONENT_H
#define SHOOTINGGALLERY_CLOCKCOMPONENT_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Component.h"

class TimerComponent : public Component {
private:
    sf::Text text;
    sf::Clock clock;
    const float time;
public:
    TimerComponent(GameObject&,sf::Vector2f place,sf::Vector2f size,float time);
    void draw();
};


#endif //SHOOTINGGALLERY_CLOCKCOMPONENT_H
