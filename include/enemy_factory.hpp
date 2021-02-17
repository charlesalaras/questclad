#ifndef ENEMY_FACTORY_HPP
#define ENEMY_FACTORY_HPP

#include "enemy.hpp"

class EnemyFactory {
public:
  virtual Enemy getWarrior() = 0;
  virtual Enemy getArcher() = 0;
  virtual Enemy getWizard() = 0;

};

#endif
