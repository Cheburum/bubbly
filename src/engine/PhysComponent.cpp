#include "PhysComponent.h"
#include "CollisionManager.h"
#include "GlobalInfo.h"

namespace Bubbly {
    PhysComponent::PhysComponent(GameObject &gameObject1, const float mass,
                                 bool affectGravity, bool dynamic)
            : Component(gameObject1),
              mass(mass),
              speed(0.0f, 0.0f),
              acceleration(0.0f, 0.0f),
              affectGravity(affectGravity),
              collider(Collider::circleCollider(1.0f)),
              isDynamic(dynamic) {
        gameObject.getWorldInfo().getCollisionDetector().add(this);
    };

    PhysComponent::PhysComponent(PhysComponent *other) :
            Component(other->gameObject),
            acceleration(other->acceleration),
            affectGravity(other->affectGravity),
            mass(other->mass),
            speed(other->speed),
            isDynamic(other->isDynamic),
            collider(other->collider) {
    };


    void PhysComponent::setMass(float x) {
        if (x > 0)
            mass = x;
    }

    void PhysComponent::update() {
        if (isDynamic) {
            const auto deltaSeconds = (float) gameObject.getWorldInfo().getDeltaTime() / 1000.0f;
            auto totalAcceleration = acceleration;
            if (affectGravity)
                totalAcceleration += gameObject.getWorldInfo().getGravity();
            speed += totalAcceleration * deltaSeconds;
            if (!collisions.empty())
                speed = (collisions.back()->speed * collisions.back()->mass - speed * mass)
                        * mass / (collisions.back()->mass + mass) * 0.9f;
            gameObject.getTransform().position +=
                    speed * deltaSeconds;
        }
    }

    void PhysComponent::setDynamic(bool x) {
        isDynamic = x;
    }

    void PhysComponent::addForce(const glm::vec2 &force) {
        if (isDynamic)
            acceleration += force / mass;
    }

    void PhysComponent::addImpulse(const glm::vec2 &impulse) {
        if (isDynamic)
            speed += impulse / mass;
    }

    void PhysComponent::setCollider(const Collider &col) {
        collider = col;
    }

    const CollisionList &PhysComponent::getCollisions() {
        return collisions;
    }

    PhysComponent::~PhysComponent() {
        gameObject.getWorldInfo().getCollisionDetector().remove(this);
    }
}