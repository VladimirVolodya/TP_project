#include "SmallAsteroid.h"
#include <cmath>

SmallAsteroid::SmallAsteroid() : OrdinaryAsteroid() {
    x = 400;
    y = 400;
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
    speed = sqrt(dx * dx + dy * dy);
    type = smallAsteroid;
    radius = 16;
}
