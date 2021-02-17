#include "src/character/MountainFactory.hpp"

TEST(Enemy, MountainFactoryEnemy) {
  EnemyFactory* factory = new MountainFactory();
  Enemy enemy = factory->getEnemy(10);


  EXPECT_EQ(enemy.isAlive(), true);
  EXPECT_EQ(enemy.takeDamage(10), 10);
}
