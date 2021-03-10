#include "character/user.hpp"
#include <algorithm>
#include <vector>

// Skill Format: Name, Damage, User
// Item Format: Name, Effect, ItemType, User
User::User(std::string name, int classtype): Damageable(name, 10, 50, 0, 1), classtype(classtype) {
   if(classtype == 0) {
      skills.push_back(new Skill("Punch", 5, 0));
      skills.push_back(new Skill("Jab", 8, 0));
      skills.push_back(new Skill("Chop", 10, 0));
      skills.push_back(new Skill("Furious Fists", 20, 0));
      inventory.push_back(new Item("Hand Wraps", 1, 0, 0));
      currentWeapon = 0;
      currentArmor = 1;
   }
   if(classtype == 1) {
      skills.push_back(new Skill("Slice", 5, 0));
      skills.push_back(new Skill("Stab", 8, 0));
      skills.push_back(new Skill("Shank", 10, 0));
      skills.push_back(new Skill("Sword Flurry", 20, 0));
      inventory.push_back(new Item("Rusty Broadsword", 1, 0, 1));
      currentWeapon = 0;
      currentArmor = 1;
   }
   if(classtype == 2) {
      skills.push_back(new Skill("Fireball", 5, 0));
      skills.push_back(new Skill("Thunderbolt", 8, 0));
      skills.push_back(new Skill("Frostbite", 10, 0));
      skills.push_back(new Skill("Magic Missile", 20, 0));
      inventory.push_back(new Item("Tree Branch", 1, 0, 2));
      currentWeapon = 0;
      currentArmor = 1;
   }
   inventory.push_back(new Item("Traveller's Clothes", 2, 1, -1));
   inventory.push_back(new Item("Heal Potion", 10, 2, -1));
   inventory.push_back(new Item("Big Heal Potion", 25, 2, -1));
}

User::~User() {
   for(int i = 0; i < skills.size(); i++) {
      delete skills.at(i);
   }
   for(int i = 0; i < inventory.size(); i++) {
      delete inventory.at(i);
   }
}

std::string User::getAttack(int index) { 
  return skills[index]->getName(); 
}

int User::getItemType(int index) { 
  return inventory[index]->getType(); 
}

Skill* User::getSkill(int i) {
  return skills[i];
}

Item* User::getItem(int i) {
  return inventory[i];
}

std::vector<Skill*> User::getSkills() {
  return skills;
}

std::vector<Item*> User::getItems() {
  return inventory;
}

void User::useItem(int index) {
   // VISITOR PATTERN
   /*
   In this scenario, we need to apply a bonus to user, but we don't know what kind.
   The visitor pattern works by making User itself a visitor to the item, and the
   item telling the visitor what kind of function it should call on itself in order
   to apply changes to its own local variables
   */
   inventory.at(index)->accept(this);
}

void User::setArmor(Item* item) {
  auto vit = std::find(inventory.begin(), inventory.end(), item);
  currentArmor = vit - inventory.begin();
}

void User::setWeapon(Item* item) {
  auto vit = std::find(inventory.begin(), inventory.end(), item);
  currentWeapon = vit - inventory.begin();
}

void User::removeItem(Item* item) {
  auto vit = std::find(inventory.begin(), inventory.end(), item);
  delete *vit;
  inventory.erase(vit);
}
