#ifndef TP_PROJECT_FREEZEEFFECT_H
#define TP_PROJECT_FREEZEEFFECT_H

#include "SpecialEffects/SpecialEffect.h"
#include "Asteroids/OrdinaryAsteroid.h"


class FreezeEffect : public SpecialEffect {
    virtual void effect(std::shared_ptr<Object>, Object *);
    void effect(std::list<std::shared_ptr<Object>> &, Object *) override;
};


#endif //TP_PROJECT_FREEZEEFFECT_H
