#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character {
private:
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
