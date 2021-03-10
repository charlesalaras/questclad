#include "character/user.hpp"
#include "interface/battle_interface.hpp"
#include "interface/item_interface.hpp"
#include "interface/skill_interface.hpp"
#include "character/item.hpp"
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

  User user("name", 1); 

  Enemy enemy("Goblin", 10, 100, 10, 10, "afsd");

  SkillInterface skillInter(win, &user);
  ItemInterface itemInter(win, &user);


  BattleInterface interface(win, &skillInter, &itemInter, &user, &enemy); 

  while(true) {
    wclear(win);
    interface.draw();
    int c = wgetch(win);
    int res = interface.update(c);
  }
  
  delwin(win);
  endwin();
  exit_curses(0);
  return 0;
}
