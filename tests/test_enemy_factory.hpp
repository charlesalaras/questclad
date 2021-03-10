#include "character/mountain_factory.hpp"
#include "character/cavern_factory.hpp"
#include "character/desert_factory.hpp"
#include <iostream>

TEST(MountainFactory, EnemyLosesHealth) {
  MountainFactory factory;
  Enemy* enemy = factory.getEnemy(0);

  EXPECT_EQ(enemy->isAlive(), true);
  int health = enemy->getCurrentHealth();
  enemy->takeDamage(100);
  EXPECT_LT(enemy->getCurrentHealth(), health);

  delete enemy;
}

TEST(MountainFactory, EnemyDies) {
  MountainFactory factory;
  Enemy* enemy = factory.getEnemy(0);
  EXPECT_EQ(enemy->isAlive(), true);

  enemy->takeDamage(1000000);
  EXPECT_EQ(enemy->isAlive(), false);

  delete enemy;
}


TEST(MountainFactory, EnemyNameChangesPerLevel) {
  MountainFactory factory;
  Enemy* enemy = factory.getEnemy(0);
  std::string name1 = enemy->getName();
  delete enemy;
  enemy = factory.getEnemy(1);
  std::string name2 = enemy->getName();
  delete enemy;
  
  EXPECT_NE(name1, name2);
}

TEST(MountainFactory, ScalesWithLevel) {
  MountainFactory factory;
  Enemy* enemy1 = factory.getEnemy(0);
  Enemy* enemy2 = factory.getEnemy(1);

  EXPECT_LT(enemy1->getHealth(), enemy2->getHealth());
  EXPECT_LT(enemy1->getStrength(), enemy2->getStrength());
  EXPECT_LT(enemy1->getDefense(), enemy2->getDefense());

  delete enemy1;
  delete enemy2;
}


TEST(DesertFactory, EnemyLosesHealth) {
  DesertFactory factory;
  Enemy* enemy = factory.getEnemy(0);

  EXPECT_EQ(enemy->isAlive(), true);
  int health = enemy->getCurrentHealth();
  enemy->takeDamage(100);
  EXPECT_LT(enemy->getCurrentHealth(), health);

  delete enemy;
}

TEST(DesertFactory, EnemyDies) {
  DesertFactory factory;
  Enemy* enemy = factory.getEnemy(0);
  EXPECT_EQ(enemy->isAlive(), true);

  enemy->takeDamage(1000000);
  EXPECT_EQ(enemy->isAlive(), false);

  delete enemy;
}

TEST(DesertFactory, EnemyNameChangesPerLevel) {
  DesertFactory factory;
  Enemy* enemy = factory.getEnemy(0);
  std::string name1 = enemy->getName();
  delete enemy;
  enemy = factory.getEnemy(1);
  std::string name2 = enemy->getName();
  delete enemy;
  
  EXPECT_NE(name1, name2);
}

TEST(DesertFactory, ScalesWithLevel) {
  DesertFactory factory;
  Enemy* enemy1 = factory.getEnemy(0);
  Enemy* enemy2 = factory.getEnemy(1);

  EXPECT_LT(enemy1->getHealth(), enemy2->getHealth());
  EXPECT_LT(enemy1->getStrength(), enemy2->getStrength());
  EXPECT_LT(enemy1->getDefense(), enemy2->getDefense());

  delete enemy1;
  delete enemy2;
}



TEST(CavernFactory, EnemyLosesHealth) {
  CavernFactory factory;
  Enemy* enemy = factory.getEnemy(0);

  EXPECT_EQ(enemy->isAlive(), true);
  int health = enemy->getCurrentHealth();
  enemy->takeDamage(100);
  EXPECT_LT(enemy->getCurrentHealth(), health);

  delete enemy;
}

TEST(CavernFactory, EnemyDies) {
  CavernFactory factory;
  Enemy* enemy = factory.getEnemy(0);
  EXPECT_EQ(enemy->isAlive(), true);

  enemy->takeDamage(1000000);
  EXPECT_EQ(enemy->isAlive(), false);

  delete enemy;
}

TEST(CavernFactory, EnemyNameChangesPerLevel) {
  CavernFactory factory;
  Enemy* enemy = factory.getEnemy(0);
  std::string name1 = enemy->getName();
  delete enemy;
  enemy = factory.getEnemy(1);
  std::string name2 = enemy->getName();
  delete enemy;
  
  EXPECT_NE(name1, name2);
}

TEST(CavernFactory, ScalesWithLevel) {
  CavernFactory factory;
  Enemy* enemy1 = factory.getEnemy(0);
  Enemy* enemy2 = factory.getEnemy(1);

  EXPECT_LT(enemy1->getHealth(), enemy2->getHealth());
  EXPECT_LT(enemy1->getStrength(), enemy2->getStrength());
  EXPECT_LT(enemy1->getDefense(), enemy2->getDefense());

  delete enemy1;
  delete enemy2;
}
