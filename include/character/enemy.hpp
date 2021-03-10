#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "damageable.hpp"
#include <string>

class Enemy : public Damageable {
protected:
  std::string dialogue;

public:
  Enemy(std::string name, int gold, int health, int defense, int strength, std::string dialogue) : Damageable(name, gold, health, defense, strength), dialogue(dialogue) {};
  
  int simpleAttack(Damageable* target);  
  std::string getDialogue();
};

#endif
