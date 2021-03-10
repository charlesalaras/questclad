#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character {
protected:
  int gold;
  const std::string name;

public:
  Character(std::string name, int gold) : name(name), gold(gold) { }
  
  int getGold() {
    return gold;
  }

  std::string getName() {
    return name;
  }

};

#endif
