#include <gtest/gtest.h>
#include "src/Player.h"

namespace {
    class PlayerTesting : public testing::Test {
    public:
        PlayerTesting() {}
    };
}

TEST(PlayerTesting, PlayerOnlyOne) {
    Player *player1 = Player::getInstance();
    Player *player2 = Player::getInstance();
    ASSERT_EQ(player1, player2);
}

TEST(PlayerTesting, PlayerCanMove) {
    Player *player = Player::getInstance();
    float curr_x = player->getX();
    player->engineOn = true;
    player->update(0.001);
    ASSERT_NE(curr_x, player->getX());
}
