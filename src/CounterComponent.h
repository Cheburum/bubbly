#ifndef BUBBLY_BUBBLECOUNTERCOMPONENT_H
#define BUBBLY_BUBBLECOUNTERCOMPONENT_H


#include "engine/Component.h"

using namespace Bubbly;

class CounterComponent : public Component {
private:
    unsigned int count;
    unsigned int maxCount;
public:
    explicit CounterComponent(GameObject &);

    void operator++();

    void operator--();

    unsigned int getCount() const;

    unsigned int getMaxCount() const;
};


#endif
