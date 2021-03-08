#ifndef __EVENT_TEST_HPP__
#define __EVENT_TEST_HPP__

TEST(EventTest, OneCavernEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Cavern", 1);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, TwoCavernEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Cavern", 2);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, ThreeCavernEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Cavern", 3);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, OneDesertEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Desert", 1);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, TwoDesertEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Desert", 2);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, ThreeDesertEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Desert", 3);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, OneMountainEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Mountain", 1);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, TwoMountainEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Mountain", 2);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, ThreeMountainEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Mountain", 3);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, AliveTest) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Cavern", 0);
   EXPECT_NE(testEvent->getAliveEnemy(), nullptr);
   delete testEvent;
   delete dummy;
}

TEST(EventTest, EnemyGold) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Cavern", 0);
   EXPECT_EQ(testEvent->getEnemyGold(), 30);
   delete testEvent;
   delete dummy;
}

// Should Never Happen, For Testing Purposes
TEST(EventTest, ZeroEnemy) {
   User* dummy = new User("dummy", 0);
   Event* testEvent = new Event(dummy, "Cavern", 0);
   delete testEvent;
   delete dummy;
}

#endif // __EVENT_TEST_HPP__