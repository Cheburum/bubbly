#include <random>
#include "GunComponent.h"
#include "engine/SpriteComponent.h"
#include "engine/PhysComponent.h"
#include "engine/GlobalInfo.h"
#include "BulletComponent.h"
#include "engine/Scene.h"
#include "engine/Texture.h"
#include "engine/Mouse.h"

GunComponent::GunComponent(GameObject &object, float ypos,
                           const Texture &bulletTexture1)
        : Component(object),
          bulletTexture(bulletTexture1),
          force(1.0f),
          coolDown(1.0f) {
    gameObject.getTransform().position.y = ypos;
    clock.restart();
    //TODO text.setFont(gameObject.getWorldInfo().getFont());
    //TODO text.setFillColor(sf::Color::Red);
}

void GunComponent::setForce(float x) {
    force = x;
}

void GunComponent::draw() {
    const auto t = coolDown - clock.getElapsedTime();
    if (t > 0.0f) {
        /*text.setPosition(gameObject.getTransform().position     //TODO ADD TEXT COMPONENT
                         * gameObject.getWorldInfo().getPixelsPerUnit()
                         + glm::vec2(100.0f, 0.0f));
        text.setString(std::to_string((int) t) + "." + std::to_string((int) (t * 10) % 10));*/
        //TODO gameObject.getWorldInfo().getWindow().draw(text);
    }
}

void GunComponent::update() {
    gameObject.getTransform().position.x = Mouse::getPosition().x
                                           / gameObject.getWorldInfo().getPixelsPerUnit()
                                           - 0.5f;
    if (Mouse::isButtonPressed(Mouse::LEFT) && clock.getElapsedTime() > coolDown) {
        clock.restart();
        auto &newBullet = gameObject.getWorldInfo().getScene().createGameObject();
        newBullet.getTransform().position = gameObject.getTransform().position;
        const auto physComp = new PhysComponent(newBullet, 1.0f, true, true);
        newBullet.addComponent("Physics", physComp);
        physComp->setCollider(Collider::circleCollider(0.5f));
        physComp->addImpulse(glm::vec2(std::uniform_real_distribution<float>(-5, 5)
                                                  (gameObject.getWorldInfo().random_generator), -1.0f * force));
        newBullet.addComponent("Sprite", new SpriteComponent(newBullet, bulletTexture));
        newBullet.addComponent("Bullet", new BulletComponent(newBullet));
    }
}