#ifndef TP_PROJECT_ORDINARYASTEROIDFACTORY_H
#define TP_PROJECT_ORDINARYASTEROIDFACTORY_H

#include "OrdinaryAsteroid.h"
#include "ObjectFactory.h"


class OrdinaryAsteroidFactory : ObjectFactory {
public:
    Object *createObject() override;
};


#endif //TP_PROJECT_ORDINARYASTEROIDFACTORY_H
