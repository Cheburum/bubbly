//
// Created by cheburum on 12.07.17.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "PhysComponent.h"
#include "CollisionManager.h"
#include "GlobalInfo.h"

PhysComponent::PhysComponent(GameObject& gameObject1, const float mass,
                             bool affectGravity,bool dynamic)
        : Component(gameObject1),
          mass(mass),
          speed(0.0f, 0.0f),
          acceleration(0.0f, 0.0f),
          affectGravity(affectGravity),
          isDynamic(dynamic){
    gameObject.getWorldInfo().getCollisionDetector().add(this);
};

PhysComponent::PhysComponent(PhysComponent* other) :
        Component(other->gameObject),
        acceleration(other->acceleration),
        affectGravity(other->affectGravity),
        mass(other->mass),
        speed(other->speed),
        isDynamic(other->isDynamic){
};


void PhysComponent::setMass(float x) {
    if (x > 0)
        mass = x;
}

void PhysComponent::update() {
    if(isDynamic) {
        const auto deltaSeconds = (float) gameObject.getWorldInfo().getDeltaTime() / 1000.0f;
        auto totalAcceleration = acceleration;
        if (affectGravity)
            totalAcceleration += gameObject.getWorldInfo().getGravity();
        speed += totalAcceleration * deltaSeconds;
        if(!collisions.empty())
                speed=(collisions.back()->speed*collisions.back()->mass-speed*mass)
                       *mass/(collisions.back()->mass+mass)*0.9f;
        gameObject.getTransform().position +=
                speed * deltaSeconds * gameObject.getWorldInfo().getPixelsPerMeter();
    }
}
void PhysComponent::setDynamic(bool x) {
    isDynamic=x;
}

void PhysComponent::addForce(const sf::Vector2f &force) {
    if(isDynamic)
        acceleration += sf::Vector2f(force.x / mass, force.y / mass);
}

void PhysComponent::addImpulse(const sf::Vector2f &impulse) {
    if(isDynamic)
        speed += sf::Vector2f(impulse.x / mass, impulse.y / mass);
}

void PhysComponent::setCollider(const Collider &col) {
    collider=col;
}

const CollisionList& PhysComponent::getCollisions() {
    return collisions;
}
PhysComponent::~PhysComponent() {
    gameObject.getWorldInfo().getCollisionDetector().remove(this);
}