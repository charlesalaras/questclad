#include "character/user.hpp"
#include "event/battle_event.hpp"
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
  Enemy* enemy = new Enemy("Goblin", 10, 100, 10, 10, "afsd");

  BattleEvent event(win, &user, enemy);

  while(event.isActive()) {
    event.draw();
    int c = wgetch(win);
    event.select(c);
    wclear(win);
  }
  
  delwin(win);
  endwin();
  exit_curses(0);
  return 0;
}
