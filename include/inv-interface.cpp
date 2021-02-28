#include "interface.hpp"

InventoryInterface::InventoryInterface(vector<Item*> inventory): invPtr(&inventory) {
   getmaxyx(stdscr, introw, intcol);
}

int drawInt() {
   box(stdscr, 0, 0);
   
}