#include "character/damageable.hpp"
#include <algorithm>

bool Damageable::isAlive() {
  return this->currentHealth > 0;
}

int Damageable::takeDamage(int damage) {
  damage = std::max(1, damage - (this->defense + this->defenseBonus));
  this->currentHealth -= damage;
  return damage;
}

void Damageable::addStrengthBonus(int bonus) {
  this->strengthBonus += bonus;
}

void Damageable::addDefenseBonus(int bonus) {
  this->defenseBonus += bonus;
}

void Damageable::addHealthBonus(int bonus) {
  this->healthBonus += bonus;
  this->currentHealth += bonus;
}

int Damageable::attack(Damageable* target, int damage) {
  return target->takeDamage(((this->strengthBonus + this->strength) / 20) * damage);
}
