//
// Created by cheburum on 19.07.17.
//

#include <iostream>
#include <cmath>
#include "TimerComponent.h"
#include "GameObject.h"
#include "GlobalInfo.h"

TimerComponent::TimerComponent(GameObject& obj, sf::Vector2f place,
                               sf::Vector2f size,const float time1)
:Component(obj),time(time1){
    text.setFont(gameObject.getWorldInfo().getFont());
    text.setScale(size);
    text.setPosition(place);
    text.setCharacterSize(55);
    text.setFillColor(sf::Color::Blue);
    clock.restart();
}

void TimerComponent::draw() {
    auto t = time-clock.getElapsedTime().asSeconds();
    if(t<0.0f)
        t=0.0f;
    text.setString(std::to_string((int)t)+"."+std::to_string((int)(t*10)%10));
    gameObject.getWorldInfo().getWindow().draw(text);
}