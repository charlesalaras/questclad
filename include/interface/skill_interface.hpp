#ifndef SKILL_INTERFACE_HPP
#define SKILL_INTERFACE_HPP

#include "interface/interface.hpp"
#include "character/character.hpp"
#include <ncurses.h>
#include <menu.h>

class SkillInterface : public Interface {
private:
  WINDOW* win;
  User* character;
  ITEM** skills;
  int skillSize;  
  MENU* menu;

public:
  SkillInterface(WINDOW* win, User* character) : win(win), character(character) {
    this->initMenu();  
  };

  ~SkillInterface() {
    this->freeMenu();
  }

  void freeMenu() {
    this->undraw();
    for(int i = 0; i < skillSize; ++i) {
      free_item(this->skills[i]);
    }
    free_menu(this->menu);
    delete this->skills;
  }

  void refresh() {
    this->freeMenu();
    this->initMenu();
  }
  
  void initMenu() {
    std::vector<Skill*> newSkills = this->character->getSkills();
    this->skills = new ITEM*[newSkills.size()];
    for(int i = 0; i < newSkills.size(); ++i) {
      const char* name = newSkills[i]->getName().c_str();

      this->skills[i] = new_item(name, "");
    }
    this->menu = new_menu(this->skills);
    set_menu_win(this->menu, this->win);
    set_menu_sub(this->menu, derwin(this->win, 15, 15, 5, 5));
  }

  virtual void draw() {
    post_menu(this->menu);
  }

  virtual void undraw() {
    unpost_menu(this->menu);
  }

  virtual int update(int c) {
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
      case 10:
        return 1;
    }
    return 0; 
  }
};

#endif
