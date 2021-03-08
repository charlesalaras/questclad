#ifndef __USER_TEST_HPP__
#define __USER_TEST_HPP__

#include "damageable.hpp"
#include "character.hpp"
#include "enemy.hpp"
#include "user.hpp"

TEST(UserTest, UseItem) {
   User* dummy = new User("dummy", 0);
   dummy->removeItem(0);
   delete dummy;
}

TEST(UserTest, CurrentHealth) {
   User* dummy = new User("dummy", 0);
   dummy->takeDamage(10);
   EXPECT_EQ(dummy->currentHealth(), 40);
   delete dummy;
}

TEST(UserTest, Health) {
   User* dummy = new User("dummy", 0);
   dummy->takeDamage(10);
   EXPECT_EQ(dummy->currentHealth(), 50);
   delete dummy;
}

TEST(UserTest, Defense) {
   User* dummy = new User("dummy", 0);
   EXPECT_EQ(dummy->getDefense(), 0);
   delete dummy;
}

TEST(UserTest, Strength) {
   User* dummy = new User("dummy", 0);
   EXPECT_EQ(dummy->getStrength(), 5);
   delete dummy;
}

TEST(UserTest, HealthBonus) {
   User* dummy = new User("dummy", 0);
   dummy->addHealthBonus(10);
   EXPECT_EQ(dummy->getCurrentHealth(), 60);
   delete dummy;
}

TEST(UserTest, DefenseBonus) {
   User* dummy = new User("dummy", 0);
   dummy->addDefenseBonus(10);
   EXPECT_EQ(dummy->getDefense(), 10);
   delete dummy;
}

TEST(UserTest, StrengthBonus) {
   User* dummy = new User("dummy", 0);
   dummy->addStrengthBonus(10);
   EXPECT_EQ(dummy->getStrength(), 15);
   delete dummy;
}

// Tests Attack Function
TEST(UserTest, AttackTest) {
   Enemy* dummyTarget = new Enemy("target", 10, 10, 10);
   User* testuser = new User("dummy", 1);
   testuser->attack(dummyTarget, 0); // Attack with Attack 1
   testuser->attack(dummyTarget, 1); // Attack with Attack 2
   testuser->attack(dummyTarget, 2); // Attack with Attack 3
   testuser->attack(dummyTarget, 3); // Attack with Attack 4
   EXPECT_EQ(dummyTarget->getCurrentHealth(), -40);
   delete testuser;
   delete dummyTarget;
}
// Tests Gold Given Correctly
TEST(UserTest, GoldTest) {
   User* testuser = new User("dummy", 0);
   testuser->giveGold(100);
   EXPECT_EQ(testuser->getGold(), 100);
   delete testuser;
}




#endif // __USER_TEST_HPP__