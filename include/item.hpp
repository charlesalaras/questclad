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
};

#endif // __ITEM_HPP__