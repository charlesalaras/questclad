#include "character/user.hpp"
#include "interface/skill_interface.hpp"
#include "character/mock_skill.hpp"
#include <ncurses.h>
#include <iostream>

int main() {
  int row;
  int col;

  getmaxyx(stdscr, row, col);

  initscr();
  clear();
  noecho();
  cbreak();
  refresh();
  WINDOW* win = newwin(row / 2, col / 2, 0, 0);
  box(win, 0, 0);
  keypad(win, true);

  User newChar("name", 100, 10, 10, 10);
  newChar.addSkill(new MockSkill("skill 1", 1));
  newChar.addSkill(new MockSkill("skill 2", 1));
  
  SkillInterface interface(win, &newChar);
  interface.draw();

  while(true) {
    interface.draw();
    int c = wgetch(win);
    int res = interface.update(c);
    if(res == 1) {
      break;
    }
  }
  
  delwin(win);
  endwin();
  exit_curses(0);
  return 0;
}
