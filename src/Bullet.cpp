#include "Bullet.h"

Bullet::Bullet() {
    speed = 12;
    currFrame = 0;
    alive = true;
}

void Bullet::update(float time) {
    type = bullet;
    x += dx * time;
    y += dy * time;
    checkScreenBorders();
}
