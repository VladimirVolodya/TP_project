#include "BulletFactory.h"
#include "Bullet.h"

Object *BulletFactory::createObject() {
    return new Bullet();
}
