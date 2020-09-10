#ifndef TP_PROJECT_ORDINARYASTEROID_H
#define TP_PROJECT_ORDINARYASTEROID_H

#include "BaseObject/Object.h"
#include "SpecialEffects/SpecialEffect.h"

enum ObjectType;


class OrdinaryAsteroid : public Object {
protected:
    SpecialEffect *special_effect;
public:
    OrdinaryAsteroid();
    void update(float) override;
    ~OrdinaryAsteroid();
    void setEffect(SpecialEffect *);
    SpecialEffect *getEffect() const;
};


#endif //TP_PROJECT_ORDINARYASTEROID_H
