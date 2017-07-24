//
// Created by cheburum on 19.07.17.
//

#include <iostream>
#include <cmath>
#include <SFML/Window/Event.hpp>
#include "TimerComponent.h"
#include "GameObject.h"
#include "GlobalInfo.h"
#include "Scene.h"

TimerComponent::TimerComponent(GameObject& obj, CounterComponent& counter,const float time1)
:Component(obj),
 time(time1),
 timeExceeded(false),
 bubbleCounter(counter){
    text.setFont(gameObject.getWorldInfo().getFont());
    text.setCharacterSize(55);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(gameObject.getTransform().position);
    text.setScale(gameObject.getTransform().scale);
    clock.restart();
}

void TimerComponent::draw() {
    if(!timeExceeded) {
        auto t = time - clock.getElapsedTime().asSeconds();
        if (t < 0.0f) {
            t = 0.0f;
            timeExceeded=true;
            text.setString("You loose...\nPress space to restart Level");
            text.setPosition(20.0f,20.0f);
        }else if(bubbleCounter.getCount()==0){
            timeExceeded=true;
            text.setString("You won!!!\nPress space to restart Level");
            text.setPosition(20.0f,20.0f);
        }
        else
            text.setString(std::to_string((int) t) + "." + std::to_string((int) (t * 10) % 10));
    }else{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
            gameObject.getWorldInfo().getScene().reload();
    }
    gameObject.getWorldInfo().getWindow().draw(text);
}