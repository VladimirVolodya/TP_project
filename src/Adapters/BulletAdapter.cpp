#include "Adapters/BulletAdapter.h"

BulletAdapter::BulletAdapter(Bullet *bullet) : p_bullet(bullet) {}

Bullet *BulletAdapter::adapt(const Object *object) {
    p_bullet->setAngle(object->getAngle());
    p_bullet->setX(object->getX());
    p_bullet->setY(object->getY());
    p_bullet->setDx(std::cos(p_bullet->getAngle() * DEGTORAD) * p_bullet->getSpeed());
    p_bullet->setDy(std::sin(p_bullet->getAngle() * DEGTORAD) * p_bullet->getSpeed());
    return p_bullet;
}
