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
