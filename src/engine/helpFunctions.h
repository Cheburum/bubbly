//
// Created by cheburum on 23.07.17.
//

#ifndef BUBBLYENGINE_HELPFUNCTIONS_H
#define BUBBLYENGINE_HELPFUNCTIONS_H

#include <cstdlib>

float randomFloat(float from, float to){
    return from + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(to-from)));
}
#endif //SHOOTINGGALLERY_RANDOMFUN_H
