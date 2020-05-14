#include "Factories/FrozenAsteroidFactory.h"

Object *FrozenAsteroidFactory::createObject() {
    OrdinaryAsteroid *p_asteroid = new OrdinaryAsteroid();
    p_asteroid->freeze();
    p_asteroid->setEffect(new FreezeEffect());
    return p_asteroid;
}
