#ifndef DAMAGEABLE_HPP
#define DAMAGEABLE_HPP

#include "character/character.hpp"
#include <string>

class Damageable : public Character {
protected:
  int health;
  int defense;
  int strength;

public:
  Damageable(std::string name, int gold, int health, int defense, int strength) : Character(name, gold), health(health), defense(defense), strength(strength) {}
  bool isAlive();

  int takeDamage(int damage);

  std::string attack(Damageable* target, std::string attackName, int damage);

};

#endif
