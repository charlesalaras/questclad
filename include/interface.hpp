#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include <ncurses.h>
#include "item.hpp"
#include "skill.hpp"
#include <vector>
#include <string>
#include <pair>

class Interface {
protected:
   int colors;
   int introw;
   int intcol;
};

class InventoryInterface: public Interface {
private:
   vector<Item*>* charInv; // Accesses User's Items
public:
   InventoryInt();
   int DrawInt(); // Returns Item Consumed (Index)
}

class SkillInterface: public Interface {
private:
   vector<Skill*>* skill; // Accesses User's Skills
   void printSkills(); // Helper Function to Print User Skill Names
public:
   SkillInt();
   int DrawInt(); // Returns Skill Number Used
}

class UserInterface: public Interface {
private:
   Interface* skillInt;
   Interface* inventoryInt;
public:
   UserInterface(vector<Skill*>, vector<Item*>);
   pair<int, int> DrawInt();
   /*
   First Int: Attack or Consume
   Second Int: Index Based On First
   */
}

#endif //__INTERFACE_HPP__