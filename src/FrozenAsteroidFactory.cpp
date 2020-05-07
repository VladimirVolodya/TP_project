#include "FrozenAsteroidFactory.h"
#include "OrdinaryAsteroid.h"

Object *FrozenAsteroidFactory::createObject() {
    OrdinaryAsteroid *asteroid = new OrdinaryAsteroid();
    asteroid->freeze();
    return asteroid;
}
