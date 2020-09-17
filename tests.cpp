#include <gtest/gtest.h>
#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Asteroids/OrdinaryAsteroid.h"
#include "Asteroids/SmallAsteroid.h"
#include "Timer/Timer.h"
#include "SpecialEffects/HydraEffect.h"
#include "SpecialEffects/FreezeEffect.h"
#include "Adapters/BulletAdapter.h"
#include "Adapters/SmallAsteroidAdapter.h"
#include "Factories/FrozenAsteroidFactory.h"
#include "Factories/OrdinaryAsteroidFactory.h"
#include <vector>
#include <memory>

TEST(PlayerTesting, ConstructorTest) {
    Player *player = Player::getInstance();
    EXPECT_EQ(player->getType(), ObjectType::player);
    EXPECT_EQ(player->getX(), 600);
    EXPECT_EQ(player->getY(), 400);
    EXPECT_EQ(player->getAngle(), 0);
    EXPECT_EQ(player->getSpeed(), 6);
}

TEST(PlayerTesting, TimerTest) {
    Player *player = Player::getInstance();
    player->setTimer(10);
    player->update(2);
    player->update(2);
    player->update(2);
    player->update(2);
    player->update(2);
    player->update(2);
    player->update(2);
}

TEST(PlayerTesting, FreezeTest) {
    Player *player = Player::getInstance();
    player->freeze();
    player->unfreeze();
    player->freeze();
    player->setTimer(10);
    EXPECT_TRUE(player->isFrozen());
    player->update(2);
    EXPECT_TRUE(player->isFrozen());
    player->update(2);
    EXPECT_TRUE(player->isFrozen());
    player->update(2);
    EXPECT_TRUE(player->isFrozen());
    player->update(2);
    EXPECT_TRUE(player->isFrozen());
    player->update(2);
    EXPECT_FALSE(player->isFrozen());
    player->update(2);
    EXPECT_FALSE(player->isFrozen());
}

TEST(PlayerTesting, RespawnTests) {
    Player *player = Player::getInstance();
    float start_x = player->getX(), start_y = player->getY();
    player->turnRight();
    player->go();
    player->update(0.02);
    float old_angle = player->getAngle(), old_x = player->getX(), old_y = player->getY();
    player->respawn();
    EXPECT_EQ(start_x, player->getX());
    EXPECT_EQ(start_y, player->getY());
    EXPECT_EQ(old_angle, player->getAngle());
    EXPECT_NE(old_x, player->getX());
    EXPECT_NE(old_y, player->getY());
}

TEST(PlayerTesting, PlayerOnlyOne) {
    Player *player1 = Player::getInstance();
    Player *player2 = Player::getInstance();
    EXPECT_EQ(player1, player2);
}

TEST(PlayerTesting, PlayerCanMove) {
    Player *player = Player::getInstance();
    float curr_x = player->getX();
    player->go();
    player->update(0.001);
    EXPECT_NE(curr_x, player->getX());
}

TEST(PlayerTesting, TurningTest) {
    Player *player = Player::getInstance();
    float old_x = player->getX(), old_y = player->getY(), old_angle = player->getAngle();
    player->turnLeft();
    EXPECT_EQ(old_x, player->getX());
    EXPECT_EQ(old_y, player->getY());
    EXPECT_NE(old_angle, player->getAngle());
    player->turnRight();
    EXPECT_EQ(old_x, player->getX());
    EXPECT_EQ(old_y, player->getY());
    EXPECT_EQ(old_angle, player->getAngle());
    player->turnRight();
    EXPECT_EQ(old_x, player->getX());
    EXPECT_EQ(old_y, player->getY());
    EXPECT_NE(old_angle, player->getAngle());
}

TEST(PlayerTesting, ShootTest) {
    Player *player = Player::getInstance();
    Object *bullet = player->shoot();
    EXPECT_FALSE(dynamic_cast<Bullet *>(bullet) == nullptr);
    EXPECT_EQ(player->getX(), bullet->getX());
    EXPECT_EQ(player->getY(), bullet->getY());
    EXPECT_EQ(player->getAngle(), bullet->getAngle());
    delete bullet;
}

TEST(PlayerTesting, DieTest) {
    Player *player = Player::getInstance();
    std::list<std::shared_ptr<Object>> objects;
    objects.emplace_back(new OrdinaryAsteroid);
    objects.emplace_back(new OrdinaryAsteroid);
    objects.back()->setX(player->getX() + 100);
    objects.back()->setY(player->getY());
    objects.front()->setX(player->getX() + 100);
    objects.front()->setY(player->getY());
    int32_t old_lifes = player->getLifes();
    EXPECT_FALSE(player->died(objects));
    EXPECT_EQ(player->getLifes(), old_lifes);
    objects.back()->setX(player->getX());
    objects.back()->setY(player->getY());
    EXPECT_TRUE(player->died(objects));
    EXPECT_EQ(player->getLifes() + 1, old_lifes);
    delete player;
}

TEST(BulletTesting, TypeTest) {
    Bullet *bullet = new Bullet;
    EXPECT_EQ(bullet->getType(), ObjectType::bullet);
    delete bullet;
}

TEST(BulletTesting, KillTest) {
    Bullet *bullet = new Bullet;
    std::list<std::shared_ptr<Object>> asteroids;
    asteroids.emplace_back(new OrdinaryAsteroid);
    asteroids.emplace_back(new OrdinaryAsteroid);
    asteroids.front()->setX(bullet->getX() + 200);
    asteroids.back()->setX(bullet->getX() + 200);
    asteroids.front()->setY(bullet->getY());
    asteroids.back()->setY(bullet->getY());
    EXPECT_EQ(bullet->findSomeoneToKill(asteroids), asteroids.end());
    asteroids.back()->setX(bullet->getX());
    EXPECT_EQ(bullet->findSomeoneToKill(asteroids), --asteroids.end());
    delete bullet;
}

TEST(BulletTesting, UpdateXTest) {
    Bullet *bullet = new Bullet;
    bullet->setAngle(45);
    bullet->setX(0);
    bullet->setY(0);
    bullet->setDy(10);
    bullet->setDx(10);
    float old_x = bullet->getX();
    float old_y = bullet->getY();
    float old_angle = bullet->getAngle();
    bullet->update(0.1);
    EXPECT_NE(old_x, bullet->getX());
    EXPECT_NE(old_y, bullet->getY());
    EXPECT_EQ(old_angle, bullet->getAngle());
    delete bullet;
}

TEST(TimerTesting, BaseTest) {
    Timer timer(10);
    EXPECT_FALSE(timer.Tick(2));
    EXPECT_FALSE(timer.Tick(2));
    EXPECT_FALSE(timer.Tick(2));
    EXPECT_FALSE(timer.Tick(2));
    EXPECT_TRUE(timer.Tick(2));
    EXPECT_TRUE(timer.Tick(2));
}

TEST(SmallAsteroidTesting, ConstructorTest) {
    SmallAsteroid *asteroid = new SmallAsteroid;
    EXPECT_EQ(asteroid->getEffect(), nullptr);
    EXPECT_EQ(asteroid->getType(), ObjectType::smallAsteroid);
    delete asteroid;
}

TEST(SmallAsteroidTesting, FreezeTest) {
    SmallAsteroid *asteroid = new SmallAsteroid;
    asteroid->freeze();
    EXPECT_EQ(asteroid->getEffect(), nullptr);
    asteroid->unfreeze();
    EXPECT_EQ(asteroid->getEffect(), nullptr);
    delete asteroid;
}

TEST(SmallAsteroidAdapterTesting, BaseTest) {
    OrdinaryAsteroid asteroid;
    SmallAsteroid *small_asteroid = new SmallAsteroid;
    asteroid.setX(0);
    asteroid.setY(0);
    small_asteroid->setX(20);
    small_asteroid->setY(20);
    EXPECT_NE(asteroid.getX(), small_asteroid->getX());
    EXPECT_NE(asteroid.getY(), small_asteroid->getY());
    small_asteroid = SmallAsteroidAdapter(small_asteroid).adapt(&asteroid);
    EXPECT_EQ(asteroid.getX(), small_asteroid->getX());
    EXPECT_EQ(asteroid.getY(), small_asteroid->getY());
    delete small_asteroid;
}

TEST(BulletAdapterTesting, BaseTest) {
    Player *player = Player::getInstance();
    Bullet *bullet = new Bullet;
    bullet->setX(player->getX() + 20);
    bullet->setY(player->getY() + 20);
    bullet->setAngle(player->getAngle() + 20);
    EXPECT_NE(bullet->getX(), player->getX());
    EXPECT_NE(bullet->getY(), player->getY());
    EXPECT_NE(bullet->getAngle(), player->getAngle());
    bullet = BulletAdapter(bullet).adapt(player);
    EXPECT_EQ(bullet->getX(), player->getX());
    EXPECT_EQ(bullet->getY(), player->getY());
    EXPECT_EQ(bullet->getAngle(), player->getAngle());
    delete bullet;
    delete player;
}

TEST(OrdinaryAsteroidTesting, ConstructorTest) {
    OrdinaryAsteroid *asteroid = new OrdinaryAsteroid;
    EXPECT_EQ(asteroid->getType(), ObjectType::ordinaryAsteroid);
    EXPECT_EQ(asteroid->getEffect(), nullptr);
    delete asteroid;
}

TEST(OrdinaryAsteroidTesting, FreezeUnfreezeTest) {
    OrdinaryAsteroid *asteroid = new OrdinaryAsteroid;
    asteroid->setEffect(new HydraEffect);
    asteroid->setEffect(new FreezeEffect);
    asteroid->setDx(2);
    float old_x = asteroid->getX();
    float old_y = asteroid->getY();
    asteroid->freeze();
    asteroid->setTimer(10);
    EXPECT_NE(dynamic_cast<FreezeEffect *>(asteroid->getEffect()), nullptr);
    EXPECT_TRUE(asteroid->isFrozen());
    asteroid->update(2);
    EXPECT_NE(dynamic_cast<FreezeEffect *>(asteroid->getEffect()), nullptr);
    asteroid->update(2);
    asteroid->update(2);
    asteroid->update(2);
    asteroid->update(2);
    asteroid->update(2);
    asteroid->update(2);
    asteroid->update(2);
    EXPECT_EQ(dynamic_cast<FreezeEffect *>(asteroid->getEffect()), nullptr);
    EXPECT_NE(dynamic_cast<HydraEffect *>(asteroid->getEffect()), nullptr);
    EXPECT_FALSE(asteroid->isFrozen());
    delete asteroid;
}

TEST(OrdinaryAsteroidTesting, MoveTest) {
    OrdinaryAsteroid *asteroid = new OrdinaryAsteroid;
    asteroid->setDx(2);
    float old_x = asteroid->getX();
    float old_y = asteroid->getY();
    EXPECT_EQ(old_x, asteroid->getX());
    EXPECT_EQ(old_y, asteroid->getY());
    asteroid->update(0.1);
    EXPECT_NE(old_x, asteroid->getX());
    EXPECT_NE(old_y, asteroid->getY());
    delete asteroid;
}

TEST(SpecialEffectsTesting, HydraEffectTest) {
    OrdinaryAsteroid *first_asteroid = new OrdinaryAsteroid, *second_asteroid = new OrdinaryAsteroid;
    first_asteroid->setEffect(new HydraEffect);
    second_asteroid->setEffect(new HydraEffect);
    std::list<std::shared_ptr<Object>> asteroids;
    asteroids.emplace_back(first_asteroid);
    asteroids.emplace_back(second_asteroid);
    second_asteroid->effect(asteroids);
    auto pre_last = --asteroids.end();
    auto last = pre_last--;
    EXPECT_EQ(asteroids.size(), 4);
    EXPECT_EQ(second_asteroid->getX(), (*pre_last)->getX());
    EXPECT_EQ(second_asteroid->getX(), (*last)->getX());
    EXPECT_EQ(second_asteroid->getY(), (*pre_last)->getY());
    EXPECT_EQ(second_asteroid->getY(), (*last)->getY());
    EXPECT_NE(dynamic_cast<HydraEffect *>(second_asteroid->getEffect()), nullptr);
}

TEST(SpecialEffectsTesting, FreezeEffectTest) {
    OrdinaryAsteroid *asteroid = new OrdinaryAsteroid, *pre_pre_last = new OrdinaryAsteroid,
    *pre_last = new OrdinaryAsteroid, *last = new OrdinaryAsteroid;
    asteroid->setEffect(new FreezeEffect);
    std::list<std::shared_ptr<Object>> asteroids;
    asteroids.emplace_back(new OrdinaryAsteroid);
    asteroids.emplace_back(asteroid);
    asteroids.emplace_back(pre_pre_last);
    asteroids.emplace_back(pre_last);
    asteroids.emplace_back(last);
    pre_pre_last->setY(asteroid->getY());
    pre_pre_last->setX(asteroid->getX() + 100);
    pre_last->setY(asteroid->getY());
    pre_last->setX(asteroid->getX() + 190);
    last->setY(asteroid->getY());
    last->setX(asteroid->getX() + 500);
    EXPECT_EQ(pre_pre_last->getEffect(), nullptr);
    EXPECT_EQ(pre_last->getEffect(), nullptr);
    EXPECT_EQ(last->getEffect(), nullptr);
    EXPECT_FALSE(pre_pre_last->isFrozen());
    EXPECT_FALSE(pre_last->isFrozen());
    EXPECT_FALSE(last->isFrozen());
    asteroid->effect(asteroids);
    EXPECT_NE(dynamic_cast<FreezeEffect *>(pre_pre_last->getEffect()), nullptr);
    EXPECT_NE(dynamic_cast<FreezeEffect *>(pre_last->getEffect()), nullptr);
    EXPECT_EQ(dynamic_cast<FreezeEffect *>(last->getEffect()), nullptr);
    EXPECT_TRUE(pre_pre_last->isFrozen());
    EXPECT_TRUE(pre_last->isFrozen());
    EXPECT_FALSE(last->isFrozen());
}

TEST(FreezeEffectTesting, FreezeSetsTimer) {
    OrdinaryAsteroid *first_asteroid = new OrdinaryAsteroid,
    *second_asteroid = new OrdinaryAsteroid;
    std::list<std::shared_ptr<Object>> asteroids;
    asteroids.emplace_back(first_asteroid);
    asteroids.emplace_back(second_asteroid);
    first_asteroid->setEffect(new FreezeEffect);
    second_asteroid->setEffect(new HydraEffect);
    EXPECT_NE(dynamic_cast<HydraEffect *>(second_asteroid->getEffect()), nullptr);
    EXPECT_FALSE(second_asteroid->isFrozen());
    second_asteroid->setX(first_asteroid->getX() + 100);
    second_asteroid->setY(first_asteroid->getY());
    first_asteroid->effect(asteroids);
    EXPECT_NE(dynamic_cast<FreezeEffect *>(second_asteroid->getEffect()), nullptr);
    EXPECT_TRUE(second_asteroid->isFrozen());
    second_asteroid->update(1000);
    EXPECT_NE(dynamic_cast<HydraEffect *>(second_asteroid->getEffect()), nullptr);
    EXPECT_FALSE(second_asteroid->isFrozen());
}

TEST(FrozenAsteroidFacroryTesting, BaseTest) {
    FrozenAsteroidFactory fact;
    Object *frozen_object = fact.createObject();
    EXPECT_EQ(frozen_object->getType(), ObjectType::ordinaryAsteroid);
    EXPECT_NE(dynamic_cast<OrdinaryAsteroid *>(frozen_object), nullptr);
    EXPECT_TRUE(frozen_object->isFrozen());
    OrdinaryAsteroid *frozen_asteroid = dynamic_cast<OrdinaryAsteroid *>(frozen_object);
    EXPECT_NE(dynamic_cast<FreezeEffect *>(frozen_asteroid->getEffect()), nullptr);
    frozen_object->update(1000);
    EXPECT_TRUE(frozen_object->isFrozen());
    EXPECT_NE(dynamic_cast<FreezeEffect *>(frozen_asteroid->getEffect()), nullptr);
    delete frozen_object;
}

TEST(OrdinaryAsteroidFactoryTesting, BaseTest) {
    OrdinaryAsteroidFactory fact;
    Object *object = fact.createObject();
    EXPECT_NE(dynamic_cast<OrdinaryAsteroid *>(object), nullptr);
    EXPECT_FALSE(object->isFrozen());
    OrdinaryAsteroid *asteroid = dynamic_cast<OrdinaryAsteroid *>(object);
    EXPECT_NE(asteroid, nullptr);
    EXPECT_NE(dynamic_cast<HydraEffect *>(asteroid->getEffect()), nullptr);
    object->update(1000);
    EXPECT_FALSE(object->isFrozen());
    EXPECT_NE(dynamic_cast<HydraEffect *>(asteroid->getEffect()), nullptr);
    delete object;
}



