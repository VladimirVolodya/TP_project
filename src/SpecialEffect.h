#ifndef TP_PROJECT_SPECIALEFFECT_H
#define TP_PROJECT_SPECIALEFFECT_H

#include "Object.h"


class SpecialEffect {
  public:
    virtual ~SpecialEffect() {}
    virtual std::vector<Object *> effect(Object *) = 0;
};


#endif //TP_PROJECT_SPECIALEFFECT_H
