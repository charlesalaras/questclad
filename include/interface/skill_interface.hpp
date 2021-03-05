#ifndef SKILL_INTERFACE_HPP
#define SKILL_INTERFACE_HPP

#include "interface/interface.hpp"
#include "character/character.hpp"
#include <ncurses.h>

class SkillInterface : public Interface {
private:
  WINDOW* win;
  User* character;
  ITEM** skills;
  int skillSize;  
  MENU menu;

public:
  SkillInterface(WINDOW* win, User* character) : win(win), character(character) {
    this->initMenu();  
  };

  void freeMenu() {
    unpost_menu(this->menu);
    free_menu(this->menu);
    for(int i = 0; i < skillSize; ++i) {
      free_item(this->skills[i]);
    }
  }

  void refresh() {
    this->initMenu();
  }
  
  void initMenu() {
    std::vector<Skill*> newSkills = this->character->getSkills();
    this->skills[] = new (ITEM*)[newSkills.size()];
    for(int i = 0; i < newSkills.size(); ++i) {
      this->skills[i] = new_item(newSkills[i]->getName().c_str(), newSkills[i]->getName().c_str());
    }   

    this->menu = new_menu_win(this->win, this->skills);
    post_menu(this->menu);
    
    wrefresh(this->win); 
  }

  virtual std::string update(char c) {
    switch(c) {
      case KEY_DOWN:
        menu_driver(this->menu, REQ_DOWN_ITEM);
        break;
      case KEY_UP:
        menu_driver(this->menu, REQ_UP_ITEM);
        break;
      case KEY_RIGHT:
        menu_driver(this->menu, REQ_RIGHT_ITEM);
        break;
      case KEY_LEFT:
        menu_driver(this->menu, REQ_LEFT_ITEM);
        break;
      case KEY_ENTER:
        return "end";
    }
    wrefresh(this->win);
    return ""; 
  }
};

#endif
