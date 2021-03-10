#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include "character/user.hpp"
#include <string>

class Item {
private:
  std::string name; // What is the item called?
  int effect; // How much does it heal, protect, or increase damage?
  int type; // Is this a weapon, armor piece, or consumable?
  int whoCanUse; // What class can use it?

public:
  Item(std::string name, int effect, int type, int whoCanUse) : name(name), effect(effect), type(type), whoCanUse(whoCanUse) {
  
  }

  std::string getName() {
    return name;
  }

  int getCompatibility() {
    return whoCanUse;
  }

  int getType() {
    return type;
  }

  void accept(User* user) {
    switch(type) {
      case 0:
        user->addStrengthBonus(effect);
        user->setWeapon(this);
        break;
      case 1:
        user->addDefenseBonus(effect);
        user->setArmor(this);
        break;
      case 2:
        user->addHealthBonus(effect);
        character->removeItem(this);
        break;
    }
  }


};

#endif // __ITEM_HPP__
