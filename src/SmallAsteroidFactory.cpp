#include "SmallAsteroidFactory.h"
#include "SmallAsteroid.h"

Object *SmallAsteroidFactory::createObject() {
    return new SmallAsteroid();
}
