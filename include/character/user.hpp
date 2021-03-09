#ifndef USER_HPP
#define USER_HPP

#include "character/damageable.hpp"
#include "character/skill.hpp"
#include "character/item.hpp"

class User : public Damageable {
private:
  std::vector<Skill*> skills;
  std::vector<Item*> inventory;

public:
  User(std::string name, int gold, int health, int defense, int strength) : Damageable(name, gold, health, defense, strength) {
  
  }
	
  ~User() {
    for(int i = 0; i < skills.size(); ++i) {
      delete skills[i];
    }
    for(int i = 0; i < inventory.size(); ++i) {
      delete inventory[i];
    }
  }

  std::vector<Skill*> getSkills() {
    return skills;
  }

  std::vector<Item*> getInventory() {
    return inventory;
  }

  void addSkill(Skill* skill) {
    skills.push_back(skill);
  }
  
  void addItem(Item* item) {
    inventory.push_back(item);
  }
};

#endif
