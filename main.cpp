#include "character/user.hpp"
#include "interface/menu.hpp"
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

  Menu interface(win, {"skill 1", "skill 2", "skill 3"}, 10, 10);

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
