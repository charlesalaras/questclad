#ifndef __USER_TEST_HPP__
#define __USER_TEST_HPP__

#include "damageable.hpp"
#include "character.hpp"
#include "enemy.hpp"
#include "user.hpp"

// Test The Warrior Elements of User
TEST(UserTest, WarriorTest) {

}
// Test The Swordsman Elements of User
TEST(UserTest, SwordsmanTest) {
   
}
// Test The Mage Elements of User
TEST(UserTest, MageTest) {
   
}
// Tests is Skills are Instantiated Correctly
TEST(UserTest, SkillsTest) {
   
}
// Tests if Inventory Is Spawned Correctly
TEST(UserTest, InventoryTest) {
   
}
// Tests is Constructor Works Correctly
TEST(UserTest, ConstructorTest) {
   
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
}
// Tests Gold Given Correctly
TEST(UserTest, GoldTest) {
   User* testuser = new User("dummy", 0);
   testuser->giveGold(100);
   EXPECT_EQ(testuser->getGold(), 100);
   delete testuser;
}




#endif // __USER_TEST_HPP__