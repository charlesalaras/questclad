#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "damageable.hpp"
#include <string>

class Enemy : public Damageable {
public:
  Enemy(std::string name, int gold, int health, int defense, int strength) : Damageable(name, gold, health, defense, strength) {};
  
  int simpleAttack(Damageable* target);  
};

#endif
