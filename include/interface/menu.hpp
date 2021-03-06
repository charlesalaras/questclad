#ifndef MENU_HPP
#define MENU_HPP

#include "interface/interface.hpp"
#include <ncurses.h>
#include <vector>
#include <string>
#include <algorithm>

class Menu : public Interface {
private:
  WINDOW* win;
  std::vector<std::string> options;
  int startX;
  int startY;
  int selection = 0;

  void limitSelection() {
    selection = std::min((int)options.size() - 1, std::max(selection, 0));
  }

public:
  Menu(WINDOW* win, std::vector<std::string> options, int startY, int startX) : win(win), options(options),
  startX(startX), startY(startY) {
  
  };

  ~Menu() {
  
  }

  virtual void draw() {
    for(int i = 0; i < options.size(); ++i) {
      if(selection == i) {
        wattron(this->win, A_REVERSE);
      }

      mvwprintw(this->win, startY + i, startX, options[i].c_str());

      if(selection == i) {
        wattroff(this->win, A_REVERSE);
      }
    }

  }


  virtual int update(int c) {
    switch(c) {
      case KEY_DOWN:
        selection++;
        break;
      case KEY_UP:
        selection--;
        break;
      case 10:
        return selection + 1;
    }
    limitSelection();
    return 0; 
  }

  void updateOptions(std::vector<std::string> options) {
    this->options = options;
    limitSelection();
  }
};

#endif
