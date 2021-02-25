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

void Damageable::addStrengthBonus(int bonus) {
  this->strength += bonus;
}

void Damageable::addDefenseBonus(int bonus) {
  this->defense += bonus;
}

void Damageable::addHealthBonus(int bonus) {
  this->health += bonus;
}

int Damageable::attack(Damageable* target, int damage) {
  return target->takeDamage(damage);

}
