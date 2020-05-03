#ifndef TP_PROJECT_ORDINARYASTEROID_H
#define TP_PROJECT_ORDINARYASTEROID_H

#include "Object.h"

enum ObjectType;


class OrdinaryAsteroid : public Object {
private:
//    std::string effect;
public:
    OrdinaryAsteroid();
    void update(float) override;
};


#endif //TP_PROJECT_ORDINARYASTEROID_H
