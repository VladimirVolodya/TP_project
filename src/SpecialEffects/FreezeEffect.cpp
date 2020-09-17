#include "SpecialEffects/FreezeEffect.h"

void FreezeEffect::effect(std::list<std::shared_ptr<Object>> &objects, Object *p_ref_object) {
    std::list<std::shared_ptr<Object>>::iterator iter = objects.begin();
    while (iter != objects.end()) {
        effect(*iter++, p_ref_object);
    }
}

void FreezeEffect::effect(std::shared_ptr<Object> object, Object *ref_object) {
    double effect_radius = 200;
    if (object.get() != ref_object && distance(*object, *ref_object) < effect_radius && !object->isFrozen()) {
        object->freeze();
        object->setTimer(500);
        if (object->getType() == ordinaryAsteroid) {
            OrdinaryAsteroid *p_asteroid = dynamic_cast<OrdinaryAsteroid *>(object.get());
            p_asteroid->setEffect(new FreezeEffect);
        }
    }
}
