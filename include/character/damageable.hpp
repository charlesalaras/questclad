#ifndef DAMAGEABLE_HPP
#define DAMAGEABLE_HPP

#include <string>

class Damageable {
protected:
  int health;
  int defense;
  int strength;

public:
  Damageable(int health, int defense, int strength) : health(health), defense(defense), strength(strength) {}
  bool isAlive();

  int takeDamage(int damage);

  virtual std::string attack(Damageable* target) = 0;

};

#endif
