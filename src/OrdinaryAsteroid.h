#ifndef TP_PROJECT_ORDINARYASTEROID_H
#define TP_PROJECT_ORDINARYASTEROID_H

#include "Object.h"


class OrdinaryAsteroid : public Object {
private:
    std::string effect;
public:
    OrdinaryAsteroid(std::string, float, float);
    void update(float) override;
};


#endif //TP_PROJECT_ORDINARYASTEROID_H
