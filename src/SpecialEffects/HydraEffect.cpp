#include "SpecialEffects/HydraEffect.h"
#include "Adapters/SmallAsteroidAdapter.h"

void HydraEffect::effect(std::list<std::shared_ptr<Object>> &objects, Object *p_ref_object) {
    objects.emplace_back(SmallAsteroidAdapter(new SmallAsteroid()).adapt(p_ref_object));
    objects.emplace_back(SmallAsteroidAdapter(new SmallAsteroid()).adapt(p_ref_object));
}
