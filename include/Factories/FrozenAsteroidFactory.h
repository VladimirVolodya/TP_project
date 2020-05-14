#ifndef TP_PROJECT_FROZENASTEROIDFACTORY_H
#define TP_PROJECT_FROZENASTEROIDFACTORY_H

#include "Factories/ObjectFactory.h"
#include "Asteroids/OrdinaryAsteroid.h"
#include "SpecialEffects/FreezeEffect.h"


class FrozenAsteroidFactory : public ObjectFactory {
public:
    virtual Object *createObject() override;
};


#endif //TP_PROJECT_FROZENASTEROIDFACTORY_H
