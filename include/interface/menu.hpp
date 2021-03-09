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

public:
  Menu(WINDOW* win, std::vector<std::string> options, int startX, int startY) : win(win), options(options),
  startX(startX), startY(startY) {
  
  };

  ~Menu() {
  
  }

  virtual void draw() {
    for(int i = 0; i < options.size(); ++i) {
      if(selection == i) {
        wattron(this->win, A_REVERSE);
      }

      mvwprintw(this->win, startX + i + 1, startY + 1, options[i].c_str());

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
    selection = std::min((int)this->options.size() - 1, std::max(0, selection));
    return 0; 
  }
};

#endif
