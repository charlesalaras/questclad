#ifndef ENEMY_FACTORY_HPP
#define ENEMY_FACTORY_HPP

#include "enemy.hpp"

class EnemyFactory {
public:
  virtual Enemy* getEnemy(int level) = 0;

};

#endif
