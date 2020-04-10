#include "Object.h"

int W = 1200, H = 800;

void Object::draw(sf::RenderWindow &window) {
    if (x > W) {
        x -= W;
    }
    if (x < 0) {
        x += W;
    }
    if (y > H) {
        y -= H;
    }
    if (y < 0) {
        y += H;
    }
    sprite.setPosition(x, y);
    sprite.setRotation(angle + 90);
    window.draw(sprite);
}
