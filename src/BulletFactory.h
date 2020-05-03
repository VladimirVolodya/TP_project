#ifndef TP_PROJECT_BULLETFACTORY_H
#define TP_PROJECT_BULLETFACTORY_H

#include "ObjectFactory.h"


class BulletFactory : ObjectFactory {
public:
    Object *createObject() override;
};


#endif //TP_PROJECT_BULLETFACTORY_H
