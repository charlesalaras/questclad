#include "character/item.hpp"
#include "character/user.hpp"
#include <string>

Item::Item(std::string name, int effect, int type, int whoCanUse) : name(name), effect(effect), type(type), whoCanUse(whoCanUse) {
  
}

std::string Item::getName() {
  return name;
}

int Item::getCompatibility() {
  return whoCanUse;
}

int Item::getType() {
  return type;
}

void Item::accept(User* user) {
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
      user->removeItem(this);
      break;
  }
}


