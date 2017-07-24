//
// Created by cheburum on 14.07.17.
//

#ifndef SHOOTINGGALLERY_COLLIDER_H
#define SHOOTINGGALLERY_COLLIDER_H

#include <vector>
#include <SFML/System.hpp>
#include <variant>

enum ColliderType{
    CIRCLE,
    RECTANGLE
};

//Abstract collider
class Collider {
private:
    ColliderType type;
    std::variant<float,sf::Vector2f> properties;
public:
    ColliderType getType();
    float getRadius();
    sf::Vector2f getSize();
    static Collider circleCollider(float radius);
    static Collider rectangleCollider(sf::Vector2f size);
};


#endif //SHOOTINGGALLERY_COLLIDER_H
