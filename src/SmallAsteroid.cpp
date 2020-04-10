#include "SmallAsteroid.h"
#include <cmath>

SmallAsteroid::SmallAsteroid(std::string textureName, float h, float w, float x_, float y_) : OrdinaryAsteroid(textureName, h, w) {
    x = x_;
    y = y_;
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
    speed = sqrt(dx * dx + dy * dy);
}
