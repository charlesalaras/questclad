#ifndef MOUNTAIN_FACTORY_HPP
#define MOUNTAIN_FACTORY_HPP

#include "enemy_factory.hpp"
#include "enemy.hpp"
#include <vector>
#include <string>
#include <iostream>

class MountainFactory : public EnemyFactory {
private:
  std::vector<std::string> names = {"Snake", "Boar", "Bird"};

public:

  MountainFactory() { }

  virtual Enemy* getEnemy(int level) {
    int i = level % names.size();
    double scale = 1 + (level / 10.0);
    return new Enemy(this->names[i], 10 * scale, 20 * scale, 5 * scale, 5 * scale);
  }

};

#endif
