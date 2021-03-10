#ifndef BATTLE_INTERFACE_HPP
#define BATTLE_INTERFACE_HPP

#include "character/user.hpp"
#include "character/enemy.hpp"
#include "interface/menu.hpp"
#include <string>

class BattleInterface : public Interface {
private:
  Interface* skillInter;
  Interface* itemInter;
  Enemy* enemy;
  Menu* menu;
  int selection = 0;

void drawStats() {
  mvwprintw(win, 2, 2, std::to_string(user->getCurrentHealth()) + " / " + std::to_string(user->getHealth()));
  mvwprintw(win, 20, 2, std::to_string(enemy->getCurrentHealth()) + " / " + std::to_string(enemy->getHealth());
}

public:
  BattleInterface(WINDOW* win, Interface* skillInter, Interface* itemInter, User* user, Enemy* enemy) : skillInter(skillInter), itemInter(itemInter), enemy(enemy) {
    menu = new Menu(win, {"Attack", "Items", "Run"}, 10, 10);
  }

  ~BattleInterface() {
    delete menu;
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
      }
      case 2: {
        int res = itemInter->update(c);
        if(res != 0) {
          selection = 0;
          return 20 + res;
        }
      }
    }
    return 0;
  }
};

#endif
