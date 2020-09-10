#include "SpecialEffects/HydraEffect.h"
#include "Adapters/SmallAsteroidAdapter.h"

void HydraEffect::effect(std::list<Object *> &objects, Object *p_ref_object) {
    std::list<Object *>::iterator iter = objects.begin();
    std::list<Object *>::iterator end = objects.end();
    while (iter != end && *iter++ != p_ref_object);
    --iter;
    objects.push_back(SmallAsteroidAdapter(new SmallAsteroid()).adapt(p_ref_object));
    objects.push_back(SmallAsteroidAdapter(new SmallAsteroid()).adapt(p_ref_object));
    objects.erase(iter);
}
