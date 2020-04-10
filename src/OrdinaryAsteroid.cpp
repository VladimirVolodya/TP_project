#include "OrdinaryAsteroid.h"
#include <cmath>

OrdinaryAsteroid::OrdinaryAsteroid(std::string textureName, float h, float w) {
    x = rand() % 1000;
    y = rand() % 600;
    if (x > 500) {
        x += 200;
    }
    if (y > 300) {
        y += 200;
    }
    height = h;
    width = w;
    textureImgName = textureName;
    texture.loadFromFile("images/" + textureImgName);
    sprite.setTexture(texture);
    sprite.setOrigin(width / 2, height / 2);
    sprite.setTextureRect(sf::IntRect(0, 0, height, width));
    dx = rand() % 6 - 3;
    dy = rand() % 6 - 3;
    angle = rand() % 360;
    speed = sqrt(dx * dx + dy * dy);
}

void OrdinaryAsteroid::update(float time) {
    static float currFrame = 0;
    currFrame += 0.1 * time;
    if (currFrame >= 16) {
        currFrame -= 16;
    }
    x += dx * time;
    y += dy * time;
    sprite.setTextureRect(sf::IntRect(width * static_cast<int>(currFrame), 0, width, height));
}
