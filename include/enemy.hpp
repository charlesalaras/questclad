#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "damageable.hpp"
#include <string>

class Enemy : public Damageable {
protected:
  std::string dialogue;

public:
  Enemy(std::string dialogue, std::string name, int gold) : Damageable() {};
  
  std::string getDialogue();
};

#endif
