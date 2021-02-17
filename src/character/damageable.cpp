#include "character/damageable.hpp"
#include <algorithm>

bool Damageable::isAlive() {
  return this->health > 0;
}

int Damageable::takeDamage(int damage) {
  damage = std::max(1, damage - this->defense);
  this->health -= damage;
  return damage;
}

