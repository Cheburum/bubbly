#ifndef BUBBLYENGINE_CLEANMANAGER_H
#define BUBBLYENGINE_CLEANMANAGER_H


#include <stack>
#include "AbstractManager.h"
#include "GameObject.h"

namespace Bubbly {
    class CleanManager {
    private:
        std::forward_list <GameObject> &gameObjects;
    public:
        CleanManager(std::forward_list <GameObject> &arg);

        void afterUpdate();
    };
}

#endif
