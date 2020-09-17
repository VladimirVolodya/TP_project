#ifndef TP_PROJECT_SPECIALEFFECT_H
#define TP_PROJECT_SPECIALEFFECT_H

#include "BaseObject/Object.h"


class SpecialEffect {
  public:
    virtual ~SpecialEffect() {}
    virtual void effect(std::list<std::shared_ptr<Object>> &, Object *) = 0;
};


#endif //TP_PROJECT_SPECIALEFFECT_H
