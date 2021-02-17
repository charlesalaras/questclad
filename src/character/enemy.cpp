#include "character/enemy.hpp"
#include <string>

std::string Enemy::attack(Damageable* target) {
  return this->getName() + " " + this->dialogue + " " + target->getName() + " for " + std::to_string(target->takeDamage(this->strength)) + " damage!";
}

