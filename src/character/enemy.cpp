#include "character/enemy.hpp"
#include <string>

std::string Enemy::simpleAttack(Damageable* target) {
  return this->attack(target, this->dialogue, this->strength);
}

