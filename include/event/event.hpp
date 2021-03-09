#ifndef EVENT_HPP
#define EVENT_HPP

#include "enemy_factory.hpp"
#include "damageable.hpp"
#include "character.hpp"
#include "enemy.hpp"
#include "user.hpp"
#include <ncurses.h>
#include <cmath> // For Rand
#include <time.h>

class EventBus;

class Event {
private:
   int row;
   int col;
   int enemyNumber;
   Factory* enemyFactory;
   Enemy* enemy1;
   Enemy* enemy2;
   Enemy* enemy3;
   User* user; // Pointer to user
   WINDOW * eventBox;
   Enemy* getAliveEnemy(); // Get best target for attack
   int sumEnemiesHealth(); // Event ends when summed health is 0
   int getEnemyGold(); // Sum up all Enemy gold
   void printHP(); // Print Enemies' Health

public:
  Event(User* maincharacter, string input, int enemies);
  void run();

};

#endif
