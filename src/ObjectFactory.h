#ifndef TP_PROJECT_OBJECTFACTORY_H
#define TP_PROJECT_OBJECTFACTORY_H

#include "Object.h"


class ObjectFactory {
public:
    virtual Object *createObject() = 0;
};


#endif //TP_PROJECT_OBJECTFACTORY_H
