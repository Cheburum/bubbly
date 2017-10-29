//
// Created by cheburum on 24.07.17.
//

#include "CounterComponent.h"


CounterComponent::CounterComponent(GameObject &obj) :
        Component(obj),
        count(0),
        maxCount(0) {
}

void CounterComponent::operator++() {
    ++count;
    if (count > maxCount)maxCount = count;
}

void CounterComponent::operator--() {
    --count;
}

unsigned int CounterComponent::getMaxCount() const {
    return maxCount;
}

unsigned int CounterComponent::getCount() const {
    return count;
}