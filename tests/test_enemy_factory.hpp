#include "character/mountain_factory.hpp"
#include <iostream>

TEST(Enemy, MountainFactoryEnemy) {
  EnemyFactory* factory = new MountainFactory();
  Enemy* enemy = factory->getEnemy(10);

  EXPECT_EQ(enemy->isAlive(), true);
  EXPECT_EQ(enemy->takeDamage(10), 1);
}

