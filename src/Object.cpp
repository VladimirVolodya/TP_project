#include "Object.h"

void Object::checkScreenBorders() {
    if (x > resolution.width) {
        x -= resolution.width;
    }
    if (x < 0) {
        x += resolution.width;
    }
    if (y > resolution.height) {
        y -= resolution.height;
    }
    if (y < 0) {
        y += resolution.height;
    }
}

float Object::getX() const {
    return x;
}

float Object::getY() const {
    return y;
}

void Object::setSpeed(float new_speed) {
    speed = new_speed;
}

float Object::getSpeed() {
    return speed;
}

void Object::setDx(float new_dx) {
    dx = new_dx;
}

void Object::setDy(float new_dy) {
    dy = new_dy;
}

float Object::getDx() const {
    return dx;
}

float Object::getDy() const {
    return dy;
}

float Object::getRadius() const {
    return radius;
}

void Object::setRadius(float new_radius) {
    radius = new_radius;
}

void Object::setAngle(float new_angle) {
    angle = new_angle;
}

float Object::getAngle() const {
    return angle;
}

void Object::setX(float new_x) {
    x = new_x;
}

void Object::setY(float new_y) {
    y = new_y;
}

bool Object::outOfScreen() const {
    return (x < 0 || y < 0 || x > resolution.width || y > resolution.height);
}

ObjectType Object::getType() const {
    return type;
}

bool Object::isFrozen() const {
    return frozen;
}

void Object::freeze() {
    dx /= 2;
    dy /= 2;
    speed /= 2;
    frozen = true;
}

void Object::unfreeze() {
    dx *= 2;
    dy *= 2;
    speed *= 2;
    frozen = false;
}

double distance(const Object &first_object, const Object &second_object) {
    return sqrt(pow(first_object.getX() - second_object.getX(), 2) + pow(first_object.getY() - second_object.getY(), 2));
}
