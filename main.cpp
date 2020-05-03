#include <SFML/Graphics.hpp>
#include "src/Player.h"

//extern const int W, H;
#include "src/SmallAsteroidFactory.h"
#include "src/OrdinaryAsteroidFactory.h"
#include "src/Artist.h"
#include <list>
using namespace sf;

int main() {
    Clock clock;
    RenderWindow window(VideoMode(1200, 800), "Game");
    Player &p = Player::getInstance();
    std::list<Object *> objects;
    std::list<Object *>::iterator iter;
    Artist &artist = Artist::getInstance();
    OrdinaryAsteroidFactory astFac;

    objects.push_back(astFac.createObject());
    objects.push_back(astFac.createObject());
    objects.push_back(astFac.createObject());

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 20000;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) p.turnRight();
        if (Keyboard::isKeyPressed(Keyboard::Left)) p.turnLeft();
        if (Keyboard::isKeyPressed(Keyboard::Up)) p.go();
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            objects.push_back(p.shoot());
        }
        if (Keyboard::isKeyPressed(Keyboard::R)) {
            objects.push_back(astFac.createObject());
        }
        window.clear();
        p.update(time);
        if (!objects.empty()) {
            iter = objects.begin();
            while (iter != objects.end()) {
                (*iter++)->update(time);
            }
        }
        artist.draw(p, window);
        artist.draw(objects, window);
        window.display();
    }
    while (!objects.empty()) {
        delete objects.back();
        objects.pop_back();
    }
}