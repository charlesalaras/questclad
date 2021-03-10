
#include "character/skill.hpp"
#include <string>

Skill::Skill(std::string name, int damage, int classType) : name(name), damage(damage), classType(classType) { }
   
std::string Skill::getName() {
  return this->name;
}

void Skill::use(Damageable* target) {
  target->takeDamage(damage);
}


