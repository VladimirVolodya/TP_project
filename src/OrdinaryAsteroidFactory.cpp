#include "OrdinaryAsteroidFactory.h"

Object *OrdinaryAsteroidFactory::createObject() {
    return new OrdinaryAsteroid();
}
