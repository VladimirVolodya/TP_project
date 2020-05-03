#ifndef TP_PROJECT_SMALLASTEROIDADAPTER_H
#define TP_PROJECT_SMALLASTEROIDADAPTER_H

#include "SmallAsteroid.h"


class SmallAsteroidAdapter{
private:
    SmallAsteroid *p_small_asteroid;
public:
    SmallAsteroidAdapter(SmallAsteroid *);
    SmallAsteroid *adapt(const Object *);
};


#endif //TP_PROJECT_SMALLASTEROIDADAPTER_H
