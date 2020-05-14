#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include <unistd.h>

//extern const int W, H;
#include "Factories/OrdinaryAsteroidFactory.h"
#include "Bullet/Bullet.h"
#include "Artist/Artist.h"
#include <list>

using namespace sf;

int main() {
    Clock clock;
    RenderWindow window(VideoMode(1200, 800), "Game");
    Player *p = Player::getInstance();
    std::list<Object *> objects;
    objects.push_back(Player::getInstance());
    std::list<Object *> bullets;
    std::list<Object *>::iterator iter;
    Artist &artist = Artist::getInstance();
    OrdinaryAsteroidFactory astFac;

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
        if (Keyboard::isKeyPressed(Keyboard::Right)) p->turnRight();
        if (Keyboard::isKeyPressed(Keyboard::Left)) p->turnLeft();
        if (Keyboard::isKeyPressed(Keyboard::Up)) p->go();
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            bullets.push_back(p->shoot());
        }
        if (Keyboard::isKeyPressed(Keyboard::R)) {
            objects.push_back(astFac.createObject());
        }
        window.clear();
        if (!objects.empty()) {
            iter = objects.begin();
            while (iter != objects.end()) {
                (*iter++)->update(time);
            }
        }
        if (!bullets.empty()) {
            iter = bullets.begin();
            while (iter != bullets.end()) {
                (*iter)->update(time);
                if ((*iter)->outOfScreen()) {
                    iter = bullets.erase(iter);
                } else {
                    ++iter;
                }
            }
        }
        artist.draw(objects, window);
        artist.draw(bullets, window);
        window.display();
        usleep(50000);
    }
    while (objects.size() > 1) {
        delete objects.back();
        objects.pop_back();
    }
    while (!bullets.empty()) {
        delete bullets.back();
        bullets.pop_back();
    }
}
