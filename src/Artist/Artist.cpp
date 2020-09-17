#include "Artist/Artist.h"

Artist *Artist::p_instance = nullptr;
Player *Artist::p_player = nullptr;

Artist *Artist::getInstance() {
    if (!p_instance) {
        p_instance = new Artist();
    }
    return p_instance;
}

void Artist::draw(const Object &object, sf::RenderWindow &window) {
    if (p_player->completelyDead()) {
        finalDraw(window);
    } else {
        sprites[object.type].setTextureRect(sf::IntRect(
                textureSizes[object.type].width * int(object.currFrame), 0,
                textureSizes[object.type].width, textureSizes[object.type].height));
        sprites[object.type].setPosition(object.x, object.y);
        sprites[object.type].setRotation(object.angle + 90);
        if (object.isFrozen()) {
            sprites[object.type].setColor(sf::Color(0, 247, 255));
        } else {
            sprites[object.type].setColor(sf::Color(255, 255, 255, 255));
        }
        window.draw(sprites[object.type]);
    }
}

Artist::Artist() {
    textureSizes.resize(4);
    sprites.resize(4);
    textures.resize(4);
    textureSizes[player] = {41, 45};
    textureSizes[ordinaryAsteroid] = {64, 64};
    textureSizes[smallAsteroid] = {64, 64};
    textureSizes[bullet] = {32, 64};
    textures[player].loadFromFile("images/new_spaceship.png");
    textures[ordinaryAsteroid].loadFromFile("images/rock.png");
    textures[smallAsteroid].loadFromFile("images/rock_small.png");
    textures[bullet].loadFromFile("images/fire_blue.png");
    wasted_texture.loadFromFile("images/wasted2.png");
    background_texture.loadFromFile("images/background2.jpg");
    sprites[player].setTexture(textures[player]);
    sprites[ordinaryAsteroid].setTexture(textures[ordinaryAsteroid]);
    sprites[smallAsteroid].setTexture(textures[smallAsteroid]);
    sprites[bullet].setTexture(textures[bullet]);
    wasted.setTexture(wasted_texture);
    background.setTexture(background_texture);
    sprites[player].setOrigin(textureSizes[player].width / 2, textureSizes[player].height / 2);
    sprites[ordinaryAsteroid].setOrigin(textureSizes[ordinaryAsteroid].width / 2, textureSizes[ordinaryAsteroid].height / 2);
    sprites[smallAsteroid].setOrigin(textureSizes[smallAsteroid].width / 2, textureSizes[smallAsteroid].height / 2);
    sprites[bullet].setOrigin(textureSizes[bullet].width / 2, textureSizes[bullet].height / 2);
    wasted.setOrigin(250, 250);
    wasted.setTextureRect(sf::IntRect(0, 0, 500, 500));
    background.setTextureRect(sf::IntRect(0, 0, 1200, 800));
    background.setPosition(0, 0);
    wasted.setPosition(600, 400);
    game_over = false;
}

void Artist::draw(const std::list<std::shared_ptr<Object>> &objects, sf::RenderWindow &window) {
    if (p_player->completelyDead()) {
        finalDraw(window);
    } else {
        if (objects.empty()) { return; }
        std::_List_const_iterator<std::shared_ptr<Object>> iter = objects.begin();
        while (iter != objects.end()) {
            draw(**iter++, window);
        }
    }
}

void Artist::draw(const std::list<std::shared_ptr<Bullet>> &objects, sf::RenderWindow &window) {
    if (p_player->completelyDead()) {
        finalDraw(window);
    } else {
        if (objects.empty()) { return; }
        std::_List_const_iterator<std::shared_ptr<Bullet>> iter = objects.begin();
        while (iter != objects.end()) {
            draw(*(*iter++), window);
        }
    }
}

void Artist::finalDraw(sf::RenderWindow &window) {
    window.draw(wasted);
}

void Artist::gameOver() {
    game_over = true;
}

Artist::~Artist() {
    p_instance = nullptr;
    p_player = nullptr;
}

void Artist::drawBackground(sf::RenderWindow &window) {
    window.draw(background);
}

void Artist::tieWithPlayer(Player *p) {
    p_player = p;
}
