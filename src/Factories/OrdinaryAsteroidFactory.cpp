#include "Factories/OrdinaryAsteroidFactory.h"

Object *OrdinaryAsteroidFactory::createObject() {
    OrdinaryAsteroid *new_asteroid = new OrdinaryAsteroid();
    new_asteroid->setEffect(new HydraEffect());
    return new_asteroid;
}
