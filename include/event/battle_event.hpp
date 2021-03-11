#ifndef BATTLE_EVENT_HPP
#define BATTLE_EVENT_HPP

#include "character/user.hpp"
#include "character/enemy.hpp"
#include "event/event.hpp"
#include "interface/battle_interface.hpp"
#include "interface/skill_interface.hpp"
#include "interface/item_interface.hpp"

class BattleEvent : public Event {
private:

  User* user;
  Enemy* enemy;
  BattleInterface* battleInterface;

public:

  BattleEvent(WINDOW* win, User* user, Enemy* enemy) : user(user), enemy(enemy) {
    battleInterface = new BattleInterface(win, new SkillInterface(win, user), new ItemInterface(win, user), user, enemy, user->getClass());
  } 

  ~BattleEvent() {
    delete battleInterface;
    delete enemy;
  }

  virtual void draw() {
    battleInterface->draw();    
  }

  virtual void select(int c) {
    int res = battleInterface->update(c);
    if(res == 3) {
      finish();
    }

    int menu = res / 10;
    if(res >= 10) {
      int selected = (res % 10) - 1;
      if(menu == 1) {
        user->getSkill(selected)->use(enemy);  
      } else {
        user->useItem(selected);
      }

      enemy->simpleAttack(user);
    }

    if(!user->isAlive() || !enemy->isAlive()) {
      finish();
    }
  }  
};

#endif
