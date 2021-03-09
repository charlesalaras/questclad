#ifndef BATTLE_INTERFACE_HPP
#define BATTLE_INTERFACE_HPP

#include "interface/menu.hpp"

class BattleInterface : public Interface {
private:
  Interface* skillInter;
  Interface* itemInter;
  Menu* menu;
  int selection = 0;

public:
  BattleInterface(WINDOW* win, Interface* skillInter, Interface* itemInter) : skillInter(skillInter), itemInter(itemInter) {
    menu = new Menu(win, {"Attack", "Items"}, 10, 10);
  }

  ~BattleInterface() {
    delete menu;
  }

  virtual void draw() {
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
