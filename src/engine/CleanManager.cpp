#include "CleanManager.h"

CleanManager::CleanManager(std::forward_list<GameObject> &arg) : gameObjects(arg) {

}

void CleanManager::afterUpdate() {
    gameObjects.remove_if([](const auto &el) { return el.isDestroyed(); });
}