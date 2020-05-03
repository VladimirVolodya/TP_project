#include "HydraEffect.h"

std::vector<Object *> HydraEffect::effect(Object *object) {
    SmallAsteroidFactory factory;
    std::vector<Object *> effected_objects;
    effected_objects.reserve(2);
    effected_objects.push_back(SmallAsteroidAdapter(dynamic_cast<SmallAsteroid *>(factory.createObject())).adapt(object));
    effected_objects.push_back(factory.createObject());
    return effected_objects;
}
