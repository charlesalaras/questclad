#include "gtest/gtest.h"
#include "test_enemy_factory.hpp"
#include "test_enemy.hpp"
#include "test_item.hpp"
#include "test_skill.hpp"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
