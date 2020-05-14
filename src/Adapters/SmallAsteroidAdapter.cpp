#include "Adapters/SmallAsteroidAdapter.h"

SmallAsteroidAdapter::SmallAsteroidAdapter(SmallAsteroid *small_asteroid) : p_small_asteroid(small_asteroid) {}

SmallAsteroid *SmallAsteroidAdapter::adapt(const Object *object) {
    p_small_asteroid->setX(object->getX());
    p_small_asteroid->setY(object->getY());
    return p_small_asteroid;
}
