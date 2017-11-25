#ifndef BUBBLY_HELPFUNCTIONS_H
#define BUBBLY_HELPFUNCTIONS_H

#include <SFML/System.hpp>

template <typename T>
sf::Vector2<T> multiByElement(sf::Vector2<T>& a, sf::Vector2<T>& b)
{
    return sf::Vector2<T>(a.x*b.x,a.y*b.y);
}
#endif
