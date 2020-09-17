#include "Player/Player.h"

Player *Player::p_instance = nullptr;
int16_t Player::lifes = 2;

Player *Player::getInstance() {
    if (!p_instance) {
        p_instance = new Player();
    }
    return p_instance;
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
    radius = 21.5;
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
    if (timer) {
        if (timer->Tick(time)) {
            delete timer;
            timer = nullptr;
            if (frozen) {
                unfreeze();
            }
        }
    }
    x += dx;
    y += dy;
    checkScreenBorders();
}

Player::~Player() {
    delete timer;
    p_instance = nullptr;
}

bool Player::died(const std::list<std::shared_ptr<Object>> &objects) {
    if (completelyDead()) { return true; }
    auto iter = objects.begin();
    ++iter;
    while (iter != objects.end()) {
        if (checkCollision(*this, **iter)) {
            --lifes;
            return true;
        }
        ++iter;
    }
    return false;
}

void Player::respawn() {
    x = 600;
    y = 400;
    frozen = false;
    delete timer;
    timer = nullptr;
}

int32_t Player::getLifes() const {
    return lifes;
}

bool Player::completelyDead() const {
    return lifes <= 0;
}
