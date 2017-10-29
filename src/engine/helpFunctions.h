//
// Created by cheburum on 23.07.17.
//

#ifndef BUBBLY_HELPFUNCTIONS_H
#define BUBBLY_HELPFUNCTIONS_H

#include <cstdlib>
#include <SFML/System.hpp>

float randomFloat(float from, float to);
template <typename T>
sf::Vector2<T> multiByElement(sf::Vector2<T>& a, sf::Vector2<T>& b)
{
    return sf::Vector2<T>(a.x*b.x,a.y*b.y);
}
#endif
