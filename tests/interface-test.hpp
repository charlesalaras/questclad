#ifndef __INTERFACE_TEST_HPP__
#define __INTERFACE_TEST_HPP__

#include <pair>

TEST(UserInterface, Run) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(2, 0);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

TEST(AttackInterface, Attack1) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(0, 0);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

TEST(AttackInterface, Attack2) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(0, 1);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

TEST(AttackInterface, Attack3) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(0, 2);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

TEST(AttackInterface, Attack4) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(0, 3);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

TEST(InventoryInterface, Item1) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(1, 0);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

TEST(InventoryInterface, Item2) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(1, 1);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

TEST(InventoryInterface, Item3) {
   User* dummy = new User("dummy", 0);
   std::pair<int, int> testpair(1, 2);
   EXPECT_EQ(dummy->drawInt().first, testpair.first);
   EXPECT_EQ(dummy->drawInt().second, testpair.second);
   delete dummy;
}

#endif // __INTERFACE_TEST_HPP__