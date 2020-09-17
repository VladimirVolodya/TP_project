#include "Bullet/Bullet.h"

Bullet::Bullet() {
    speed = 12;
    currFrame = 0;
    alive = true;
    frozen = false;
    type = bullet;
    radius = 25.3;
}

void Bullet::update(float time) {
    x += dx * time;
    y += dy * time;
}

std::list<std::shared_ptr<Object>>::iterator Bullet::findSomeoneToKill(std::list<std::shared_ptr<Object>> &objects) {
    auto iter = objects.begin();
    ++iter;
    while (iter != objects.end()) {
        if (checkCollision(*this, **iter)) {
            (*iter)->effect(objects);
            return iter;
        }
        ++iter;
    }
    return objects.end();
}

Bullet::~Bullet() {
    delete timer;
}
