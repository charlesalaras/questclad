#ifndef SKILL_INTERFACE_HPP
#define SKILL_INTERFACE_HPP

#include "character/user.hpp"
#include "interface/menu.hpp"

class SkillInterface : public Interface {
private:
  Menu* menu;
  User* user;
  
  void updateOptions() {
    std::vector<std::string> options;
    auto skills = user->getSkills();
    for(auto skill : skills) {
      options.push_back(skill->getName());
    }
    menu->updateOptions(options);
  }

public:
  SkillInterface(WINDOW* win, User* user) : user(user) {
    menu = new Menu(win, {}, 4, 2);
  }

  ~SkillInterface() {
    delete menu;
  }

  virtual void draw() {
    updateOptions();
    menu->draw();
  }

  virtual int update(int c) {
    return menu->update(c);
  }
};

#endif
