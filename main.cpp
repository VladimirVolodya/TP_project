#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include <unistd.h>

//extern const int W, H;
#include "Factories/OrdinaryAsteroidFactory.h"
#include "Factories/FrozenAsteroidFactory.h"
#include "Bullet/Bullet.h"
#include "Artist/Artist.h"
#include "Timer/Timer.h"
#include <memory>
#include <list>

using namespace sf;

void spawnNewAsteroid(std::list<std::shared_ptr<Object>> &);

int main() {
    Clock clock;
    RenderWindow window(VideoMode(1200, 800), "Game");
    Player *p(Player::getInstance());
    std::list<std::shared_ptr<Object>> objects;
    objects.emplace_back(Player::getInstance());
    std::list<std::shared_ptr<Bullet>> bullets;
    std::list<std::shared_ptr<Object>>::iterator iter;
    std::list<std::shared_ptr<Bullet>>::iterator bullet_iter;
    std::shared_ptr<Artist> artist(Artist::getInstance());
    Artist::tieWithPlayer(p);
    Timer *spawn_timer = new Timer(100);
    for (int i = 0; i < 10; ++i) {
        spawnNewAsteroid(objects);
    }


    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 20000;
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
            bullets.emplace_back(p->shoot());
        }
        window.clear();
        if (!objects.empty()) {
            iter = objects.begin();
            while (iter != objects.end()) {
                (*iter++)->update(time);
            }
        }
        if (!bullets.empty()) {
            bullet_iter = bullets.begin();
            while (bullet_iter != bullets.end()) {
                (*bullet_iter)->update(time);
                auto target = (*bullet_iter)->findSomeoneToKill(objects);
                if (target != objects.end()) {
                    objects.erase(target);
                    bullet_iter = bullets.erase(bullet_iter);
                } else if ((*bullet_iter)->outOfScreen()) {
                    bullet_iter = bullets.erase(bullet_iter);
                } else {
                    ++bullet_iter;
                }
            }
        }
        artist->drawBackground(window);
        artist->draw(objects, window);
        if (!bullets.empty()) {
            artist->draw(bullets, window);
        }
        if (p->died(objects)) {
            if (p->isFrozen()) {
                p->unfreeze();
            }
            p->respawn();
        }
        if (spawn_timer->Tick(time)) {
            delete spawn_timer;
            spawn_timer = new Timer(100);
            spawnNewAsteroid(objects);
        }
        window.display();
        usleep(50000);
    }
    delete spawn_timer;
}

void spawnNewAsteroid(std::list<std::shared_ptr<Object>> &objects) {
    static OrdinaryAsteroidFactory ast_fact;
    static FrozenAsteroidFactory frzn_fact;
    if (rand() % 5 == 0) {
        objects.emplace_back(frzn_fact.createObject());
    } else {
        objects.emplace_back(ast_fact.createObject());
    }
}
