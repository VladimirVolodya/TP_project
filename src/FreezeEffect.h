#ifndef TP_PROJECT_FREEZEEFFECT_H
#define TP_PROJECT_FREEZEEFFECT_H

#include "SpecialEffect.h"


class FreezeEffect : public SpecialEffect {
    virtual void effect(Object *, Object *);
    virtual void effect(std::list<Object *> &, Object *) override;
};


#endif //TP_PROJECT_FREEZEEFFECT_H
