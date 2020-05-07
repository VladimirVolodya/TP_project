#include "FreezeEffect.h"
#include "OrdinaryAsteroid.h"

void FreezeEffect::effect(std::list<Object *> &objects, Object *p_ref_object) {
    std::list<Object *>::iterator iter = objects.begin();
    while (iter != objects.end()) {
        effect(*iter++, p_ref_object);
    }
}

void FreezeEffect::effect(Object *object, Object *ref_object) {
    double effect_radius = 200;
    if (object != ref_object && distance(*object, *ref_object) < effect_radius && !object->isFrozen()) {
        object->freeze();
        if (object->getType() == ordinaryAsteroid) {
            OrdinaryAsteroid *p_asteroid = dynamic_cast<OrdinaryAsteroid *>(object);
            delete p_asteroid->getEffect();
            p_asteroid->setEffect(new FreezeEffect);
        }
    }
}
