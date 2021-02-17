#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Damageable.hpp"

class Enemy : public Damageable {
protected:
  string name;
  int gold;

public:
  Enemy(string name, int gold) : name(name), gold(gold) {};

};

#endif
