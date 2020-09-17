#ifndef TP_PROJECT_ORDINARYASTEROID_H
#define TP_PROJECT_ORDINARYASTEROID_H

#include "BaseObject/Object.h"
#include "SpecialEffects/SpecialEffect.h"

enum ObjectType;


class OrdinaryAsteroid : public Object {
protected:
    SpecialEffect *special_effect;
    SpecialEffect *last_effect;
public:
    OrdinaryAsteroid();
    void update(float) override;
    ~OrdinaryAsteroid() override;
    void setEffect(SpecialEffect *);
    SpecialEffect *getEffect() const;
    void effect(std::list<std::shared_ptr<Object>> &);
    void unfreeze() override;
};


#endif //TP_PROJECT_ORDINARYASTEROID_H
