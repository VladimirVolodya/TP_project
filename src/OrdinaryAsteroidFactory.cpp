#include "OrdinaryAsteroidFactory.h"

Object *OrdinaryAsteroidFactory::createObject() {
    return new OrdinaryAsteroid("rock.png", 64, 64);
}
