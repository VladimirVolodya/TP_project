//
// Created by smirnvov on 10.04.2020.
//

#include "SmallAsteroidFactory.h"
#include "SmallAsteroid.h"

Object *SmallAsteroidFactory::createObject() {
    return new SmallAsteroid("rock_small", 64, 64, 400, 400);
}
