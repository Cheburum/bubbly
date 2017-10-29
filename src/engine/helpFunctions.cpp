//
// Created by cheburum on 27.10.17.
//

#include "helpFunctions.h"

float randomFloat(float from, float to) {
    return from + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (to - from)));
}
