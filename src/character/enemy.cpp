#include "character/enemy.hpp"
#include <string>

int Enemy::simpleAttack(Damageable* target) {
  return this->attack(target, this->strength);
}

