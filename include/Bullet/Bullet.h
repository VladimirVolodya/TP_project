#ifndef TP_PROJECT_BULLET_H
#define TP_PROJECT_BULLET_H

#include "BaseObject/Object.h"


class Bullet : public Object {
public:
    Bullet();
    ~Bullet() override;
    void update(float) override;
    std::list<std::shared_ptr<Object>>::iterator findSomeoneToKill(std::list<std::shared_ptr<Object>> &);
};


#endif //TP_PROJECT_BULLET_H
