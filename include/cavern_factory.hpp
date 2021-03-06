#ifndef __CAVERN_FACTORY__
#define __CAVERN_FACTORY__

#include "enemy_factory.hpp"
#include "enemy.hpp"
#include <vector>
#include <string>
#include <iostream>

class CavernFactory: public EnemyFactory {
private:
   std::vector<std::string> names = {"Ogre", "Goblin"};
   std::vector<std::string> sounds = {"graa", "mgwaga"};
public:
   CavernFactory() { }

   virtual Enemy getEnemy(int level) {
      double scale = 1 + level / 10;
      Enemy newEnemy(this->names[0], 10* scale, 20 * scale, 5 * scale, 5 * scale, this->sounds[0]);
      return newEnemy;
   }
};

#endif // __CAVERN_FACTORY__