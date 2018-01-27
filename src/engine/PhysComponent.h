#ifndef BUBBLYENGINE_PHYSCOMPONENT_H
#define BUBBLYENGINE_PHYSCOMPONENT_H

#include <memory>
#include "GameObject.h"
#include "Component.h"
#include "Collider.h"

namespace Bubbly {
    class CollisionManager;

    class PhysComponent;

    typedef std::vector<PhysComponent *> CollisionList;

    class PhysComponent : public Component {
    private:
        friend class CollisionManager;

        float mass;
        glm::vec2 speed;
        glm::vec2 acceleration;
        CollisionList collisions;
        Collider collider;
        bool affectGravity;
        bool isDynamic;

        explicit PhysComponent(PhysComponent *);

    public:
        PhysComponent(GameObject &gameObject1,
                      float mass, bool affectGravity, bool dynamic);

        void setCollider(const Collider &col);

        void update();

        void setMass(float);

        void addForce(const glm::vec2 &); //Permanent force
        void addImpulse(const glm::vec2 &);

        void setDynamic(bool);

        const CollisionList &getCollisions();

        ~PhysComponent();
    };
}
#endif