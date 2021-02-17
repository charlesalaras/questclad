#ifndef MOUNTAIN_FACTORY_HPP
#define MOUNTAIN_FACTORY_HPP

#include "enemy_factory.hpp"
#include "enemy.hpp"
#include <vector>
#include <string>
#include <iostream>

class MountainFactory : public EnemyFactory {
private:
  std::vector<std::string> names = {"Snake", "Boar"};
  std::vector<std::string> sounds = {"sssss", "moo"};

public:

  MountainFactory() { }

  virtual Enemy getEnemy(int level) {
    Enemy newEnemy(this->sounds[0], 100, 50, 10);
    return newEnemy;
  }

};

#endif
