#ifndef MOCK_SKILL_HPP
#define MOCK_SKILL_HPP

#include "skill.hpp"

class MockSkill : public Skill {

public: 
  MockSkill(std::string name, int classType) : Skill(name, classType) { };
  
  virtual void use(Damageable* target) {
    //do nothing
  }
};

#endif
