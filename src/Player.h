#ifndef TP_PROJECT_PLAYER_H
#define TP_PROJECT_PLAYER_H

#include "Object.h"
#include "Bullet.h"

enum ObjectType;

class Player;

class PlayerDestroyer {
private:
    Player *p_instance;
    void initialize(Player *);
    friend class Player;
public:
    ~PlayerDestroyer();
};

class Player : public Object {
private:
    static Player *p_instance;
    bool engineOn;
    static PlayerDestroyer destroyer;
    Player();
    Player(const Player &);
    Player &operator=(const Player &);
    ~Player() = default;
    friend class PlayerDestroyer;
public:
    static Player *getInstance();
    void update(float) override;
    void go();
    void turnRight();
    void turnLeft();
    Bullet *shoot() const;
};


#endif
