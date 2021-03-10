#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

class Character {
protected:
  int gold;
  const std::string name;

public:
  Character(std::string name, int gold) : name(name), gold(gold) { }
  
  int getGold() {
    return this->gold;
  }

  std::string getName() {
    return this->name;
  }
};

#endif
