#ifndef ITEM_INTERFACE_HPP
#define ITEM_INTERFACE_HPP

#include "character/user.hpp"
#include "interface/menu.hpp"


class ItemInterface : public Interface {
private:
  Menu* menu;
  User* user;

  void updateOptions() {   
    std::vector<std::string> options;
    auto items = user->getItems();
    for(auto item : items) {
      options.push_back(item->getName());
    }

    menu->updateOptions(options);
  }

public:
  ItemInterface(WINDOW* win, User* user) : user(user) {
    menu = new Menu(win, {}, 4, 2);
  }

  ~ItemInterface() {
    delete menu;
  }

  virtual void draw() {
    updateOptions();
    menu->draw();
  }

  virtual int update(int c) {
    return menu->update(c);
  }
};


#endif
