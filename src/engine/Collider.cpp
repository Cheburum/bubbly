#include "Collider.h"

Collider Collider::circleCollider(float radius) {
    Collider result;
    result.type = CIRCLE;
    result.properties = radius;
    return result;
}

Collider Collider::rectangleCollider(sf::Vector2f size) {
    Collider result;
    result.type = RECTANGLE;
    result.properties = size;
    return result;
}

ColliderType Collider::getType() {
    return type;
}

float Collider::getRadius() {
    return std::get<float>(properties);
}

sf::Vector2f Collider::getSize() {
    return std::get<sf::Vector2f>(properties);
}