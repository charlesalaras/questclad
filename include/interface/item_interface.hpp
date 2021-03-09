#ifndef ITEM_INTERFACE_HPP
#define ITEM_INTERFACE_HPP

#include "character/user.hpp"
#include "interface/menu.hpp"


class ItemInterface : public Interface {
private:
  Menu* menu;

public:
  ItemInterface(WINDOW* win, User* user) {   
    std::vector<std::string> options;
    auto items = user->getInventory();
    for(auto item : items) {
      options.push_back(item->getName());
    }

    menu = new Menu(win, options, 10, 10);
  }

  ~ItemInterface() {
    delete menu;
  }

  virtual void draw() {
    menu->draw();
  }

  virtual int update(int c) {
    return menu->update(c);
  }
};


#endif
