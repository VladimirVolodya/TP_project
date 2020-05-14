#ifndef TP_PROJECT_SPECIALEFFECT_H
#define TP_PROJECT_SPECIALEFFECT_H

#include "BaseObject/Object.h"
#include <list>


class SpecialEffect {
  public:
    virtual ~SpecialEffect() {}
    virtual void effect(std::list<Object *> &, Object *) = 0;
};


#endif //TP_PROJECT_SPECIALEFFECT_H
