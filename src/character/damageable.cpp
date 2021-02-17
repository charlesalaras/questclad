#include "damageable.hpp"

bool Damageable::isAlive() {
  return this->health > 0;
}

void Damageable::takeDamage(int damage) {
  this->health -= damage;
}

