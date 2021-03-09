#ifndef __SKILL_HPP__
#define __SKILL_HPP__

#include <string>

struct Skill {
   std::string name;
   int damage;
   int classType;
   Skill(std::string name, int damage, int classType): name(name), damage(damage): name(name), damage(damage), classType(classType) {};
};

#endif // __SKILL_HPP__
