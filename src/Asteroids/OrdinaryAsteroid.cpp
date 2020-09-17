#include "Asteroids/OrdinaryAsteroid.h"

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
    special_effect = nullptr;
    last_effect = nullptr;
}

void OrdinaryAsteroid::update(float time) {
    currFrame += 0.1 * time;
    if (currFrame >= 16) {
        currFrame -= 16;
    }
    if (timer) {
        if (timer->Tick(time)) {
            delete timer;
            timer = nullptr;
            if (frozen) {
                unfreeze();
            }
        }
    }
    x += dx * time;
    y += dy * time;
    checkScreenBorders();
}

SpecialEffect *OrdinaryAsteroid::getEffect() const {
    return special_effect;
}

void OrdinaryAsteroid::setEffect(SpecialEffect *new_effect) {
    if (last_effect != special_effect) {
        delete last_effect;
    }
    last_effect = special_effect;
    special_effect = new_effect;
}

OrdinaryAsteroid::~OrdinaryAsteroid() {
    delete special_effect;
    delete last_effect;
    delete timer;
}

void OrdinaryAsteroid::effect(std::list<std::shared_ptr<Object>> &objects) {
    if (special_effect) {
        special_effect->effect(objects, this);
    }
}

void OrdinaryAsteroid::unfreeze() {
    Object::unfreeze();
    if (special_effect != last_effect) {
        delete special_effect;
    }
    special_effect = last_effect;
    last_effect = nullptr;
}
