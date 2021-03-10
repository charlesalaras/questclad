#ifndef __SKILL_HPP__
#define __SKILL_HPP__

#include "character/damageable.hpp"
#include <string>

class Skill {
private:
   std::string name;
   int classType;

public:
  Skill(std::string name, int classType) : name(name), classType(classType) { }
   
  std::string getName() {
    return this->name;
  }

  virtual void use(Damageable* target) = 0;

};

#endif // __SKILL_HPP__