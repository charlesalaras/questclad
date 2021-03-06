#ifndef __DESERT_FACTORY__
#define __DESERT_FACTORY__

#include "enemy_factory.hpp"
#include "enemy.hpp"
#include <vector>
#include <string>
#include <iostream>

class DesertFactory : public EnemyFactory {
private:
   std::vector<std::string> names = {"Lizard", "Golem"};
   std::vector<std::string> sounds = {"cliiik", "roar"};
public:
   DesertFactory() { }

   virtual Enemy getEnemy(int level) {
      double scale = 1 + level / 10;
      Enemy newEnemy(this->names[0], 10* scale, 20 * scale, 5 * scale, 5 * scale, this->sounds[0]);
      return newEnemy;
   }
};

#endif //__CAVERN_FACTORY__