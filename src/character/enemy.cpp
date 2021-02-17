#include "character/enemy.hpp"
#include <string>

std::string Enemy::attack(Damageable* target) {
  return this->dialogue + std::to_string(target->takeDamage(this->strength));
}

