#ifndef TP_PROJECT_BULLETADAPTER_H
#define TP_PROJECT_BULLETADAPTER_H

#include "Bullet.h"


class BulletAdapter {
private:
    Bullet *p_bullet;
public:
    BulletAdapter(Bullet *);
    Bullet *adapt(const Object *);
};


#endif //TP_PROJECT_BULLETADAPTER_H
