#ifndef USER_HPP
#define USER_HPP

#include "character/damageable.hpp"
#include "character/skill.hpp"

class User : public Damageable {
private:
  std::vector<Skill*> skills;

public:
  User(std::string name, int gold, int health, int defense, int strength) : Damageable(name, gold, health, defense, strength) {
  
  }

  std::vector<Skill*> getSkills() {
    return skills;
  }

  void addSkill(Skill* skill) {
    this->skills.push_back(skill);
  }
  
};

#endif
