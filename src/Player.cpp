#include "Player.h"
#include "BulletAdapter.h"

Player *Player::p_instance = 0;
PlayerDestroyer Player::destroyer;

Player *Player::getInstance() {
    if (!p_instance) {
        p_instance = new Player();
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

Player::Player() {
    type = player;
    x = 600;
    y = 400;
    dy = dx = 0;
    speed = 6;
    currFrame = 0;
    alive = true;
    angle = 0;
    engineOn = false;
    frozen = false;
}

void Player::go() {
    engineOn = true;
}

void Player::turnRight() {
    angle += 12;
}

void Player::turnLeft() {
    angle -= 12;
}

Bullet * Player::shoot() const {
    return BulletAdapter(new Bullet).adapt(this);
}

void Player::update(float time) {
    if (engineOn) {
        dx = std::cos( angle * DEGTORAD) * speed * time;
        dy = std::sin(angle * DEGTORAD) *  speed * time;
        currFrame = 1;
        engineOn = false;
    } else {
        dx = dy = 0;
        currFrame = 0;
    }
    x += dx;
    y += dy;
    checkScreenBorders();
}
