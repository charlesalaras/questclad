CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(include)

SET(SRC
  src/character/enemy.cpp
  src/character/damageable.cpp
  src/character/user.cpp
  src/character/skill.cpp
  src/character/item.cpp
)

ADD_EXECUTABLE(test tests/test.cpp
  ${SRC}
  test-main.cpp
)

ADD_EXECUTABLE(main main.cpp
  ${SRC}
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(test ncurses)

TARGET_LINK_LIBRARIES(main ncurses)
TARGET_LINK_LIBRARIES(main menu)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
