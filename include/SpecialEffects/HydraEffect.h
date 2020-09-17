#ifndef TP_PROJECT_HYDRAEFFECT_H
#define TP_PROJECT_HYDRAEFFECT_H

#include "SpecialEffects/SpecialEffect.h"

class HydraEffect : public SpecialEffect {
    void effect(std::list<std::shared_ptr<Object>> &, Object *) override;
};


#endif //TP_PROJECT_HYDRAEFFECT_H
