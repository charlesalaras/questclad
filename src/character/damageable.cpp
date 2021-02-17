#include "character/damageable.hpp"

bool Damageable::isAlive() {
  return this->health > 0;
}

int Damageable::takeDamage(int damage) {
  this->health -= damage;
  return damage;
}

