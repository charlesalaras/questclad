#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include "character.hpp"
#include "user.hpp"
#include <string>

class Item {
private:
   std::string name; // What is the item called?
   int effect; // How much does it heal, protect, or increase damage?
   int type; // Is this a weapon, armor piece, or consumable?
   int whoCanUse; // What class can use it?
public:
   Item(std::string name, int effect, int type, int whoCanUse): name(name), effect(effect), type(type), whoCanUse(whoCanUse) {}
   std::string printItem() {
      std::string output = name + "\t" + to_string(effect);
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
   int getType() { return type; }
   void accept(User* character) {
      if(type == 0) {
         character->addStrengthBonus(effect);
         character->setWeapon(this);
      }
      if(type == 1) {
         character->addDefenseBonus(effect);
         character->setArmor(this);
      }
      if(type == 2) {
         character->addHealthBonus(effect);
         character->removeItem(this);
      }
   }
};

#endif // __ITEM_HPP__
