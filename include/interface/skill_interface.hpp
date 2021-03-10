#ifndef SKILL_INTERFACE_HPP
#define SKILL_INTERFACE_HPP

#include "character/user.hpp"
#include "interface/menu.hpp"

class SkillInterface : public Interface {
private:
  Menu* menu;

public:

  SkillInterface(WINDOW* win, User* user) {
    std::vector<std::string> options;
    auto skills = user->getSkills();
    for(auto skill : skills) {
      options.push_back(skill->getName());
    }
    menu = new Menu(win, options, 10, 10);
  }

  ~SkillInterface() {
    delete menu;
  }

  virtual void draw() {
    menu->draw();
  }

  virtual int update(int c) {
    return menu->update(c);
  }
};

#endif
