#include "character/user.hpp"
#include "interface/skill_interface.hpp"
#include "character/mock_skill.hpp"
#include <ncurses.h>

int main() {
  
  initscr();
  clear();
  noecho();
  raw();
  keypad(stdscr, TRUE);
  
  WINDOW* win = create_newwin(10, 10, 0, 0);

  User newChar("name", 100, 10, 10, 10);
  newChar.addSkill(new MockSkill("skill 1", 1));
  newChar.addSkill(new MockSkill("skill 2", 1));
  
  SkillInterface interface(&newChar, win);
  interface.draw();
  
  while(true) {
    char c = getch();
    std::string res = interface.update(c);
    if(res == "end") {
      break;
    }
  }
  
  delwin(win);

  return 0;
}
