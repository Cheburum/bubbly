//
// Created by cheburum on 13.07.17.
//

#ifndef SHOOTINGGALLERY_TRANSFORM_H
#define SHOOTINGGALLERY_TRANSFORM_H


#include <SFML/System.hpp>

class Transform {
public:
    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;
    Transform();
};


#endif //SHOOTINGGALLERY_TRANSFORM_H
