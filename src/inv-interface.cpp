#include "interface.hpp"

InventoryInterface::InventoryInterface(vector<Item*> inventory): invPtr(&inventory) {
   getmaxyx(stdscr, introw, intcol);
}

int drawInt() {
   box(stdscr, 0, 0);
   int highlight = 0;
   int selection = -1;
   while(selection != 10) {
      for(int i = 0; i < invPtr->size(); i++) {
         if(highlight == i) {
            attron(A_REVERSE);
         }
            invPtr->at(i)->printItem(i);
         if(highlight == i) {
            attroff(A_REVERSE);
         }
      }
      selection = getch();
      if(selection == CASE_UP) {
         higlight--;
         if(highlight < 0) {
            highlight = 0;
         }
      }
      else if(selection == CASE_DOWN) {
         highlight++;
         if(highlight > invPtr->size() - 1) {
            highlight = invPtr->size() - 1;
         }
      }
      else {
         selection = -1;
      }
   }
   return highlight;
}