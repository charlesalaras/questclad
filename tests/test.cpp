#include "gtest/gtest.h"
#include "event-test.hpp"
#include "game-test.hpp"
#include "interface-test.hpp"
#include "user-test.hpp"
#include "test_enemy_factory.hpp"
#include <ncurses.h>

int main(int argc, char** argv) {
   initscr();
   start_color();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
