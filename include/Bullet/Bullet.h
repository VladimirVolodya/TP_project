#ifndef TP_PROJECT_BULLET_H
#define TP_PROJECT_BULLET_H

#include "BaseObject/Object.h"


class Bullet : public Object {
public:
    Bullet();
    void update(float) override;
};


#endif //TP_PROJECT_BULLET_H
