#ifndef __SKILL_HPP__
#define __SKILL_HPP__

#include <string>

class Skill {
private:
   std::string name;
   int damage;
   int classType;
public:
   Skill(string name, int damage): name(name), damage(damage) {};
};

#endif // __SKILL_HPP__