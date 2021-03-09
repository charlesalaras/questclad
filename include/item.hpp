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
   Item(std::string name, int effect, int type, int whoCanUse): name(name), effect(effect), type(type), whoCanUse(whoCanUse) {}
   void printItem(int i) {
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
      mvprintw(2 + i, 2, output.c_str());
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
