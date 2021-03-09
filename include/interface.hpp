#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include <ncurses.h>
#include "item.hpp"
#include "skill.hpp"
#include "character.hpp"
#include "damageable.hpp"
#include "user.hpp"
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
   vector<Item*>* invPtr; // Accesses User's Items
public:
   InventoryInterface(vector<Item*> inventory);
   int DrawInt(); // Returns Item Consumed (Index)
}

class SkillInterface: public Interface {
private:
   vector<Skill*>* skillPtr; // Accesses User's Skills
   void printSkills(); // Helper Function to Print User Skill Names
public:
   SkillInterface(vector<Skill*> skills);
   void setProperties(int colors, int rows, int cols); // Skill relies on UI to build itself
   int DrawInt(WINDOW *); // Returns Skill Number Used
}

class UserInterface: public Interface {
private:
   User* user;
   Interface* skillInt;
   Interface* inventoryInt;
   WINDOW * uiwin;
public:
   UserInterface(vector<Skill*> skills, vector<Item*> inventory, int type);
   ~UserInterface();
   pair<int, int> DrawInt();
   /*
   First Int: Attack or Consume
   Second Int: Index Based On First
   */
}

#endif //__INTERFACE_HPP__