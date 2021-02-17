#include "src/character/mock_enemy.hpp"

TEST(Enemy, MockEnemy) {
  MockEnemy enemy("test dialogue", "dale", 100);

  EXPECT_EQ(enemy.getDialogue(), "test dialogue");
}
