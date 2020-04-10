#include "Player.h"
#include <cmath>

const int W = 1200, H = 800;

float DEGTORAD = 0.017453f;

Player *Player::p_instance = 0;
PlayerDestroyer Player::destroyer;

Player *Player::getInstance() {
    if (!p_instance) {
        p_instance = new Player("spaceship.png", 40, 40);
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void PlayerDestroyer::initialize(Player *player) {
    p_instance = player;
}

PlayerDestroyer::~PlayerDestroyer() {
    delete p_instance;
}

Player::Player(std::string textureName, float h, float w) {
    x = 600;
    y = 400;
    height = h;
    width = w;
    textureImgName = textureName;
    texture.loadFromFile("images/" + textureImgName);
    sprite.setTexture(texture);
    sprite.setOrigin(width / 2, height / 2);
    sprite.setTextureRect(sf::IntRect(40, 0, height, width));
    dy = dx = 0;
    alive = true;
    angle = 0;
    engineOn = false;
    speed = 6;
}

void Player::update(float time) {
    if (engineOn) {
        dx = cos( angle * DEGTORAD) * speed * time;
        dy = sin(angle * DEGTORAD) *  speed * time;
        sprite.setTextureRect(sf::IntRect(40, 40, height, width));
        engineOn = false;
    } else {
        dx = dy = 0;
        sprite.setTextureRect(sf::IntRect(40, 0, height, width));
    }
    x += dx;
    y += dy;
}

float Player::getX() {
    return x;
}
