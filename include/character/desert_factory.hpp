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

public:
   DesertFactory() { }

   virtual Enemy* getEnemy(int level) {
      int i = level % names.size();
      double scale = 1 + (level / 20.0);
      return new Enemy(this->names[i], 10 * scale, 20 * scale, 5 * scale, 5 * scale);
   }
};

#endif //__CAVERN_FACTORY__
