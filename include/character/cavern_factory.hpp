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

public:
   CavernFactory() { }

   virtual Enemy* getEnemy(int level) {
      int i = level % names.size();
      double scale = 1 + (level / 5.0);
      return new Enemy(this->names[i], 10 * scale, 20 * scale, 5 * scale, 10 * scale);
   }
};

#endif // __CAVERN_FACTORY__
