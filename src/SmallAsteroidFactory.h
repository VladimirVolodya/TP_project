#ifndef TP_PROJECT_SMALLASTEROIDFACTORY_H
#define TP_PROJECT_SMALLASTEROIDFACTORY_H

#include "ObjectFactory.h"

class SmallAsteroidFactory : ObjectFactory {
public:
    Object *createObject() override;
};


#endif //TP_PROJECT_SMALLASTEROIDFACTORY_H
