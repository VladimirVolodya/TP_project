#ifndef TP_PROJECT_HYDRAEFFECT_H
#define TP_PROJECT_HYDRAEFFECT_H

#include "SpecialEffect.h"

class HydraEffect : public SpecialEffect {
    virtual void effect(std::list<Object *> &, Object *) override;
};


#endif //TP_PROJECT_HYDRAEFFECT_H
