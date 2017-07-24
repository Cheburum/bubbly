//
// Created by cheburum on 23.07.17.
//

#ifndef SHOOTINGGALLERY_RANDOMFUN_H
#define SHOOTINGGALLERY_RANDOMFUN_H

#include <cstdlib>

float randomFloat(float from, float to){
    return from + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(to-from)));
}
#endif //SHOOTINGGALLERY_RANDOMFUN_H
