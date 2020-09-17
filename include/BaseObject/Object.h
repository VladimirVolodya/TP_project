#ifndef TP_PROJECT_OBJECT_H
#define TP_PROJECT_OBJECT_H

#include <list>
#include <cmath>
#include <memory>
#include "Timer/Timer.h"

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
    bool frozen;
    friend class Artist;
    Timer *timer;
public:
    virtual void update(float) = 0;
    Object();
    virtual ~Object();
    void checkScreenBorders();
    bool outOfScreen() const;
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
    ObjectType getType() const;
    bool isFrozen() const;
    virtual void freeze();
    virtual void unfreeze();
    virtual void effect(std::list<std::shared_ptr<Object>> &);
    void setTimer(int64_t);
};

double distance(const Object &, const Object &);
bool checkCollision(const Object &, const Object &);


#endif //TP_PROJECT_OBJECT_H
