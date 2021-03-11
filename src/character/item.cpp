#include "character/item.hpp"
#include "character/user.hpp"
#include <string>

Item::Item(std::string name, int effect, int type, int whoCanUse) : name(name), effect(effect), type(type), whoCanUse(whoCanUse) {
  
}

std::string Item::getName() {
  return name;
}

std::string Item::printItem() {
  std::string output = name;
  if(name.size() < 15) {
    output += "\t";
  }
  output += "\t" + std::to_string(effect);
  if(type == 0) {
    output += "\tWeapon";
  }
  if(type == 1) {
    output += "\tArmor";
  }
  if(type == 2) {
    output += "\tConsumable";
  }
  if(whoCanUse == 0) {
    output += "\tWarrior";
  }
  if(whoCanUse == 1) {
    output += "\tSwordsman";
  }
  if(whoCanUse == 2) {
    output += "\tMage";
  }
  return output;
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


