#ifndef TP_PROJECT_FROZENASTEROIDFACTORY_H
#define TP_PROJECT_FROZENASTEROIDFACTORY_H

#include "ObjectFactory.h"


class FrozenAsteroidFactory : public ObjectFactory {
public:
    virtual Object *createObject() override;
};


#endif //TP_PROJECT_FROZENASTEROIDFACTORY_H
