#ifndef BATTLE_INTERFACE_HPP
#define BATTLE_INTERFACE_HPP

#include "character/user.hpp"
#include "character/enemy.hpp"
#include "interface/menu.hpp"
#include <string>

class BattleInterface : public Interface {
private:
  WINDOW* win;
  Interface* skillInter;
  Interface* itemInter;
  User* user;
  Enemy* enemy;
  Menu* menu;
  int selection = 0;


  std::string userName;
  std::string userStats;
  std::string enemyName;
  std::string enemyStats;


void drawStats() {

  userStats = std::to_string(user->getCurrentHealth()) + " / " + std::to_string(user->getHealth());
  enemyStats = std::to_string(enemy->getCurrentHealth()) + " / " + std::to_string(enemy->getHealth());
  mvwprintw(win, 1, 2, userName.c_str());
  mvwprintw(win, 2, 2, userStats.c_str());
  mvwprintw(win, 1, 40, enemyName.c_str());
  mvwprintw(win, 2, 40, enemyStats.c_str());
}

public:
  BattleInterface(WINDOW* win, Interface* skillInter, Interface* itemInter, User* user, Enemy* enemy) : win(win), skillInter(skillInter), itemInter(itemInter), user(user), 
  enemy(enemy), userName(user->getName()), enemyName(enemy->getName()) {
    menu = new Menu(win, {"Attack", "Items", "Run"}, 4, 2);
  }

  ~BattleInterface() {
    delete menu;
    delete skillInter;
    delete itemInter;
  }

  virtual void draw() {
    drawStats();
    switch(selection) {
      case 0:
        menu->draw();
        break;
      case 1:
        skillInter->draw();
        break;
      case 2:
        itemInter->draw();
        break;
    }
  }

  virtual int update(int c) {
    switch(selection) {
      case 0:
        selection = menu->update(c);
        break;
      case 1: {
        int res = skillInter->update(c);
        if(res != 0) {
          selection = 0;
          return 10 + res;
        }
        break;
      }
      case 2: {
        int res = itemInter->update(c);
        if(res != 0) {
          selection = 0;
          return 20 + res;
        }
        break;
      }
      case 3:
        selection = 0;
        return 3;
    }
    return 0;
  }
};

#endif
