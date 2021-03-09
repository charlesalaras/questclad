#ifndef BATTLE_EVENT_HPP
#define BATTLE_EVENT_HPP

#include "character/user.hpp"
#include "character/damageable.hpp""
#include "event/event.hpp"

class BattleEvent : public Event {
private:
  User* user;
  Damageable* enemy;

public:

  BattleEvent(User* user, Damageable* enemy) : user(user), enemy(enemy) {
    
  } 

  virtual void draw() {
        
  }

  virtual void select(int c) {

  }  

}

#endif
