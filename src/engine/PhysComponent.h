#ifndef BUBBLYENGINE_PHYSCOMPONENT_H
#define BUBBLYENGINE_PHYSCOMPONENT_H


#include <SFML/System.hpp>
#include <memory>
#include "GameObject.h"
#include "Component.h"
#include "Collider.h"

class CollisionManager;

class PhysComponent;

typedef std::vector<PhysComponent *> CollisionList;

class PhysComponent : public Component {
private:
    friend class CollisionManager;

    float mass;
    sf::Vector2f speed;
    sf::Vector2f acceleration;
    CollisionList collisions;
    Collider collider;
    bool affectGravity;
    bool isDynamic;

    explicit PhysComponent(PhysComponent *);

public:
    //too many arguments, need to create more constructors?
    PhysComponent(GameObject &gameObject1,
                  float mass, bool affectGravity, bool dynamic);

    void setCollider(const Collider &col);

    void update();

    void setMass(float);

    void addForce(const sf::Vector2f &); //Permanent force
    void addImpulse(const sf::Vector2f &);

    void setDynamic(bool);

    const CollisionList &getCollisions();

    ~PhysComponent();
};


#endif //SHOOTINGGALLERY_PHYSOBJECT_H