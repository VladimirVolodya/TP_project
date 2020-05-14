#ifndef TP_PROJECT_ORDINARYASTEROIDFACTORY_H
#define TP_PROJECT_ORDINARYASTEROIDFACTORY_H

#include "Asteroids/OrdinaryAsteroid.h"
#include "Factories/ObjectFactory.h"
#include "SpecialEffects/HydraEffect.h"


class OrdinaryAsteroidFactory : ObjectFactory {
public:
    Object *createObject() override;
};


#endif //TP_PROJECT_ORDINARYASTEROIDFACTORY_H
