#include "interface.hpp"

UserInterface::UserInterface(vector<Skill*> skills, vector<Item*> inventory, int type)
: skillInt(new SkillInterface(skills)), inventoryInt(new InventoryInterface(inventory)) {
   //Warrior Color Scheme
   if(type == 0) {
      colors = 10; // Pair # for Red on Black
   }
   // Swordsman Color Scheme
   if(type == 1) {
      colors = 11; // Pair # for Green on Black
   }
   // Mage Color Scheme
   if(type == 2) {
      colors = 12; // Pair # for Blue on Black
   }
   getmaxyx(stdscr, introw, intcol);
   uiwin = newwin(introw / 4, intcol, introw - (introw / 4), 0);
   introw = introw / 4;
   skillInt->setProperties(colors, introw, intcol);
 }

UserInterface::~UserInterface() {
   delete skillInt;
   delete inventoryInt;
}

pair<int, int> UserInterface::drawInt() {
   wattron(uiwin, COLOR_PAIR(colors));
   keypad(uiwin, true);
   std::string options[3] = {"Attack", "Use Items", "Run"};
   int highlight = 0;
   int selection = -1;
   int type = -1;
   box(uiwin, 0, 0); // Draw Box with Default Properties
   while(selection != 10) {
      mvwprintw(uiwin, 0, 3, "What Will You Do?");
      for(int i = 0; i < 3; i++) {
         if(highlight == i) {
            wattron(uiwin, A_REVERSE);
         }
            mvwprintw(uiwin, 2*i + 2, (intcol - options[i].size()) / 2, options[i].c_str());
         if(highlight == i) {
            wattroff(uiwin, A_REVERSE);
         }
      }
      refresh();
      wrefresh(uiwin);
      if(selection == KEY_DOWN) {
         highlight--;
         if(highlight < 0) {
            highlight = 0;
         }
      }
      else if(selection == KEY_UP) {
         highlight++;
         if(highlight > 2) {
            highlight = 2;
         }
      }
      selection = wgetch(uiwin);
   }
   switch(highlight) {
      // Tell Event That Player Wants to Attack With Attack Specified
      case 0:
         return std::make_pair(0, skillInt->DrawInt());
         break;
      // Tell Event That Player Wants to Access Inventory Using Item Specified
      case 1:
         return std::make_pair(1, inventoryInt->DrawInt());
         break;
      // Tell Event That Player Wants to Attempt an Escape
      case 2:
         return std::make_pair(2, 0);
         break;
   }
   return std::make_pair(-1, -1); // Worse Case Scenario: Something Went Wrong
}