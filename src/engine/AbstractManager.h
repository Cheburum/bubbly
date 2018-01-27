#ifndef BUBBLYENGINE_ABSTRACTMANAGER_H
#define BUBBLYENGINE_ABSTRACTMANAGER_H


#include "Component.h"

namespace Bubbly {
    class AbstractManager {
    public:
        virtual void add(Component *);

        virtual void update();

        virtual void remove(Component *);
    };
}
#endif
