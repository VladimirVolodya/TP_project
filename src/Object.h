#ifndef TP_PROJECT_OBJECT_H
#define TP_PROJECT_OBJECT_H

#include <vector>
#include <cmath>

const float DEGTORAD = 0.017453f;

enum ObjectType {player, ordinaryAsteroid, smallAsteroid, bullet};

struct sizes {
    float width, height;
};

const sizes resolution = {1200, 800};

class Object {
protected:
    ObjectType type;
    float x, y;
    float dx, dy, speed;
    float radius;
    float currFrame;
    bool alive;
    float angle;
    friend class Artist;
public:
    virtual void update(float) = 0;
    virtual ~Object() = default;
    void checkScreenBorders();
    float getX() const;
    float getY() const;
    void setX(float);
    void setY(float);
    void setSpeed(float);
    float getSpeed();
    void setDx(float);
    void setDy(float);
    float getDx() const;
    float getDy() const;
    float getRadius() const;
    void setRadius(float);
    void setAngle(float);
    float getAngle() const;
};


#endif //TP_PROJECT_OBJECT_H
