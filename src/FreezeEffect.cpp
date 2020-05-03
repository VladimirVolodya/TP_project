#include "FreezeEffect.h"

std::vector<Object *> FreezeEffect::effect(Object *object) {
    object->setDx(object->getDx() / 2);
    object->setDy(object->getDy() / 2);
    object->setSpeed(object->getSpeed() / 2);
    std::vector<Object *> effected_objects(1, object);
    return effected_objects;
}
