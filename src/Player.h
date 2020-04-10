#ifndef TP_PROJECT_PLAYER_H
#define TP_PROJECT_PLAYER_H

#include "Object.h"

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
    static PlayerDestroyer destroyer;
    Player(std::string textureName, float h, float w);
    Player(const Player &);
    Player &operator=(const Player &);
    ~Player() = default;
    friend class PlayerDestroyer;
public:
    static Player *getInstance();
    void update(float) override;
    bool engineOn;
    float getX();
};


#endif
