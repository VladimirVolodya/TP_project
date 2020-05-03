#include "Artist.h"
#include "Object.h"

Artist *Artist::p_instance = 0;
ArtistDestroyer Artist::destroyer;

ArtistDestroyer::~ArtistDestroyer() {
    delete p_instance;
}

void ArtistDestroyer::initialize(Artist *p_artist) {
    p_instance = p_artist;
}

Artist &Artist::getInstance() {
    if (!p_instance) {
        p_instance = new Artist();
        destroyer.initialize(p_instance);
    }
    return *p_instance;
}

void Artist::draw(const Object &object, sf::RenderWindow &window) {
    sprites[object.type].setTextureRect(sf::IntRect(textureSizes[object.type].width * int(object.currFrame), 0, textureSizes[object.type].width, textureSizes[object.type].height));
    sprites[object.type].setPosition(object.x, object.y);
    sprites[object.type].setRotation(object.angle + 90);
    window.draw(sprites[object.type]);
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
    sprites[player].setTexture(textures[player]);
    sprites[ordinaryAsteroid].setTexture(textures[ordinaryAsteroid]);
    sprites[smallAsteroid].setTexture(textures[smallAsteroid]);
    sprites[bullet].setTexture(textures[bullet]);
    sprites[player].setOrigin(textureSizes[player].width / 2, textureSizes[player].height / 2);
    sprites[ordinaryAsteroid].setOrigin(textureSizes[ordinaryAsteroid].width / 2, textureSizes[ordinaryAsteroid].height / 2);
    sprites[smallAsteroid].setOrigin(textureSizes[smallAsteroid].width / 2, textureSizes[smallAsteroid].height / 2);
    sprites[bullet].setOrigin(textureSizes[bullet].width / 2, textureSizes[bullet].height / 2);
}

void Artist::draw(const std::list<Object *> &objects, sf::RenderWindow &window) {
    if (objects.empty()) {return;}
    std::_List_const_iterator<Object *> iter = objects.begin();
    while (iter != objects.end()) {
        draw(**iter++, window);
    }
}
