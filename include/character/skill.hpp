#ifndef __SKILL_HPP__
#define __SKILL_HPP__

#include "character/damageable.hpp"
#include <string>

class Skill {
private:
  std::string name;
  int damage;
  int classType;

public:
  Skill(std::string name, int damage, int classType);
  std::string getName();
  virtual void use(Damageable* target);

};

#endif // __SKILL_HPP__
