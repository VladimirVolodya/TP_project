#ifndef TP_PROJECT_OBJECT_H
#define TP_PROJECT_OBJECT_H

#include <SFML/Graphics.hpp>

class Object {
protected:
    float x, y, width, height, dx, dy, radius, speed;
    std::string textureImgName;
    sf::Texture texture;
    sf::Sprite sprite;
    bool alive;
public:
    float angle;
    virtual void update(float) = 0;
    virtual ~Object() = default;
    void draw(sf::RenderWindow &);
};


#endif //TP_PROJECT_OBJECT_H
