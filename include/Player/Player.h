#ifndef TP_PROJECT_PLAYER_H
#define TP_PROJECT_PLAYER_H

#include "BaseObject/Object.h"
#include "Adapters/BulletAdapter.h"

class Player : public Object {
private:
    static int16_t lifes;
    static Player *p_instance;
    bool engineOn;
    Player();
    Player(const Player &);
    Player &operator=(const Player &);
public:
    static Player *getInstance();
    void update(float) override;
    void go();
    void turnRight();
    void turnLeft();
    Bullet *shoot() const;
    ~Player() override;
    bool died(const std::list<std::shared_ptr<Object>> &);
    void respawn();
    int32_t getLifes() const;
    bool completelyDead() const;
};


#endif
