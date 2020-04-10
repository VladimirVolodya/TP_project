#include <SFML/Graphics.hpp>
#include "src/Player.h"

//extern const int W, H;
#include "src/SmallAsteroidFactory.h"
#include "src/OrdinaryAsteroidFactory.h"
using namespace sf;

int main() {
    Clock clock;
    RenderWindow window(VideoMode(1200, 800), "Game");
    Player *p = Player::getInstance();
    Object *a = nullptr;
    OrdinaryAsteroidFactory *astFac = new OrdinaryAsteroidFactory;

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
        if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle += 1;
        if (Keyboard::isKeyPressed(Keyboard::Left)) p->angle -= 1;
        if (Keyboard::isKeyPressed(Keyboard::Up)) p->engineOn = true;
        if (Keyboard::isKeyPressed(Keyboard::R)) a = astFac->createObject();
        window.clear();
        p->update(time);
        p->draw(window);
        if (a != nullptr) {
            a->update(time);
            a->draw(window);
        }
        window.display();
    }
    delete astFac;
    if (a != nullptr) {
        delete a;
    }
}