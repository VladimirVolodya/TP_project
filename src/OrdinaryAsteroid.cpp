#include "OrdinaryAsteroid.h"
#include <cmath>

OrdinaryAsteroid::OrdinaryAsteroid() {
    x = rand() % 1000;
    y = rand() % 600;
    if (x > 500) {
        x += 200;
    }
    if (y > 300) {
        y += 200;
    }
    dx = rand() % 6 - 3;
    dy = rand() % 6 - 3;
    angle = rand() % 360;
    speed = sqrt(dx * dx + dy * dy);
    type = ordinaryAsteroid;
    currFrame = 0;
    radius = 24;
    frozen = false;
    special_effect = new HydraEffect;
}

void OrdinaryAsteroid::update(float time) {
    currFrame += 0.1 * time;
    if (currFrame >= 16) {
        currFrame -= 16;
    }
    x += dx * time;
    y += dy * time;
    checkScreenBorders();
}

SpecialEffect *OrdinaryAsteroid::getEffect() const {
    return special_effect;
}

void OrdinaryAsteroid::setEffect(SpecialEffect *new_effect) {
    special_effect = new_effect;
}
