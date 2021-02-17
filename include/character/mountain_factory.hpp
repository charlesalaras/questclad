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
    double scale = 1 + level / 10;
    Enemy newEnemy(this->names[0], 10 * scale, 20 * scale, 5 * scale, 5 * scale, this->sounds[0]);
    return newEnemy;
  }

};

#endif
