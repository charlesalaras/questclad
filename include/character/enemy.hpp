#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "damageable.hpp"
#include <string>

class Enemy : public Damageable {
protected:
  std::string dialogue;

public:
  Enemy(std::string dialogue, int health, int defense, int strength) : Damageable(health, defense, strength), dialogue(dialogue) {};
  
  virtual std::string attack(Damageable* target);  
  std::string getDialogue();
};

#endif
