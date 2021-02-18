CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/ncurses/include)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/ncurses/lib)

SET(SRC
  src/character/enemy.cpp
  src/character/damageable.cpp
)

ADD_EXECUTABLE(test tests/test.cpp 
  ${SRC}
  )

TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(test ncurses)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
