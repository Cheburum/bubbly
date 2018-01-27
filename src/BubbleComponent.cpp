#include <random>
#include "BubbleComponent.h"
#include "engine/GlobalInfo.h"
BubbleComponent::BubbleComponent(GameObject &obj, CounterComponent &counter) :
        Component(obj),
        physComponent(obj.getComponent<PhysComponent>("Physics")),
        counter(counter) {
    ++counter;
    clock.restart();
}

void BubbleComponent::update() {
    if (clock.getElapsedTime() > 1.0f) { //TODO
        physComponent.lock()->addImpulse(
                glm::vec2(
                        std::uniform_real_distribution<float>(-0.5f, 0.5f)(gameObject.getWorldInfo().random_generator),
                        std::uniform_real_distribution<float>(-0.5f, 0.5f)(
                                gameObject.getWorldInfo().random_generator)));
        clock.restart();
    }
    for (auto &el: physComponent.lock()->getCollisions())
        if (el->getGameObject().containsComponent("Bullet")) {
            --counter;
            gameObject.destroy();
        }
}