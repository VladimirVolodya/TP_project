#ifndef TP_PROJECT_HYDRAEFFECT_H
#define TP_PROJECT_HYDRAEFFECT_H

#include "SpecialEffect.h"
#include "SmallAsteroidFactory.h"
#include "SmallAsteroidAdapter.h"

class HydraEffect : SpecialEffect {
    std::vector<Object *> effect(Object *) override;
};


#endif //TP_PROJECT_HYDRAEFFECT_H
