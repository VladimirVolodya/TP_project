#ifndef TP_PROJECT_FREEZEEFFECT_H
#define TP_PROJECT_FREEZEEFFECT_H

#include "SpecialEffect.h"


class FreezeEffect : SpecialEffect {
    std::vector<Object *> effect(Object *) override;
};


#endif //TP_PROJECT_FREEZEEFFECT_H
