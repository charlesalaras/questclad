#ifndef MOCK_ENEMY_HPP
#define MOCK_ENEMY_HPP

#include "enemy.hpp"

class MockEnemy : public Enemy {
public:
  MockEnemy(string dialogue, string name, int gold) : Enemy(dialogue, name, gold) {}

};

#endif
