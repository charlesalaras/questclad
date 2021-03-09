#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <string>

class Item {
private:
  std::string name; // What is the item called?
  int effect; // How much does it heal, protect, or increase damage?
  int type; // Is this a weapon, armor piece, or consumable?
  int whoCanUse; // What class can use it?

public:
  Item(std::string name) : name(name) {
  
  }

  std::string getName() {
    return name;
  }


};

#endif // __ITEM_HPP__
