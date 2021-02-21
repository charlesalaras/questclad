#include "game.hpp"
#include <ncurses>
#include <fstream>
#include <time.h>
#include <string>

// 2021-02-13T03:00:53
Game::Game() {
   char timestamp[20];
   strftime(timestamp, 20, "%Y-%m-%dT%h-%m-%S");
   filename = "Save-" + timestamp + ".txt";
}

void Game::build() {
   clear();
   // Initialize Variables
   int row = 0; // Window Row
   int col = 0; // Window Column
   int winrow = 0; // Box Row
   int wincol = 0; // Box Column
   int selection = 0; // User Input
   int highlight = 0;
   int skillType = -1; // User Type
   std::string inputname = "";
   std::string skills[3] = {"Warrior", "Swordsman", "Mage"};
   char insertion[1];
   // Initialize Screen
   getmaxyx(stdscr, row, col);
   winrow = row / 2;
   wincol = col / 2;
   WINDOW * instanceWin = newwin(winrow, wincol, row / 4, col / 4);
   keypad(instanceWin, true);
   box(instanceWin, 0, 0);
   // Print Prompt
   mvwprintw(instanceWin, 2, 2, "Traveller, what is your name?");
   mvwprintw(instanceWin, 4, 2, "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
   refresh();
   wrefresh(instanceWin);
   // Get Name
   while(selection != 10) {
      selection = wgetch(instanceWin);
      // Nothing Entered
      if(inputname == "" && selection == 10) {
         selection = 0;
         mvwprintw(instanceWin, winrow - 1, 2, "Name must be at least 1 character!");
      }
      // (65-90 OR 97-122) AND name isn't full
      else if((selection > 64 && selection < 91) || (selection > 96 && selection < 123) && inputname.size() < 16) {
         inputname += selection;
         for(int i = 0; i < 16; i++) {
            if(i < inputname.size()) {
               if(i == inputname.size() - 1) {
                  wattron(instanceWin, A_REVERSE);
                  wattron(instanceWin, A_UNDERLINE);
               }
               insertion[0] = inputname.at(i);
               mvwprintw(instanceWin, 4, 2 + (2*i), insertion);
               wattroff(instanceWin, A_REVERSE);
               wattroff(instanceWin, A_UNDERLINE);
               mvwprintw(instanceWin, 4, 2 + (2*i) + 1, " ");
            }
            else {
               mvwprintw(instanceWin, 4, 2 + (2*i), "_ ");
            }
         }
      }
      else if(selection == KEY_BACKSPACE && !inputname.empty()) {
         inputname.pop_back();
         for(int i = 0; i < 16; i++) {
            if(i < inputname.size()) {
               if(i == inputname.size() - 1) {
                  wattron(instanceWin, A_REVERSE);
                  wattron(instanceWin, A_UNDERLINE);
               }
               insertion[0] = inputname.at(i);
               mvwprintw(instanceWin, 4, 2 + (2*i), insertion);
               wattroff(instanceWin, A_REVERSE);
               wattroff(instanceWin, A_UNDERLINE);
               mvwprintw(instanceWin, 4, 2 + (2*i) + 1, " ");
            }
            else {
               mvwprintw(instanceWin, 4, 2 + (2*i), "_ ");
            }
         }
      }
      // Invalid Character / No More Space
      refresh();
      wrefresh(instanceWin);
   }
   mvwprintw(instanceWin, 2, 2, "Traveller, what is your skill?");
   selection = 0;
   while(selection != 10) {
      selection = wgetch(instanceWin);
      for(int i = 0; i < 3; i++) {
         // Highlight if Option is Hovered
         if(highlight == i) {
            wattron(A_REVERSE);
         }
         mvwprintw(instanceWin, 4 + i, (wincol - skills[i].size()) / 2, skills[i].c_str());
         wattroff(A_REVERSE);
      }
      // Option Goes Up
      if(selection == KEY_UP) {
         highlight--;
         if(highlight < 0) {
            highlight = 0;
         }
      }
      // Option Goes Down
      else if(selection == KEY_DOWN) {
         highlight++;
         if(highlight > 2) {
            highlight = 2;
         }
      }
      // Option Gets Selected
      else if(selection == 10) {
         skillType = highlight;
      }
   }
   mainCharacter = new User(inputname, 10, skillType);
}

void Game::runGame() {
   int gameOver = 0;
   while(!eventBuffer.empty()) {
      bool success = eventBuffer.front->runEvent();
      if(!success) {
         gameOver = 1;
         endScreen();
         return;
      }
      eventBuffer.pop();
      saveGame(); // Asks User if They Would Like to Save
      if(passingPrompt()) {
         return;
      } // Asks User if they Would like to Use / Change Items
   }
   return;
}

void Game::saveGame() {
   clear();
   int row = 0;
   int col = 0;
   int winrow = 0;
   int wincol = 0;
   int selection = -1;
   int highlight = 0;
   getmaxyx(stdscr, row, col);
   winrow = row / 2;
   wincol = col / 2;
   WINDOW * saveWin = newwin(winrow, wincol, row / 4, col / 4);
   keypad(saveWin, true);
   box(saveWin, 0, 0);
   string promptString = mainCharacter->name + ", would you like to save?";
   mvwprintw(saveWin, 4, wincol / 2, promptString.c_str());
   refresh();
   wrefresh(saveWin);
   while(selection == -1) {
      if(highlight == 0) {
         wattron(A_REVERSE);
      }
      mvprintw(saveWin, 6, (wincol - 3) / 2, "Yes");
      wattroff(A_REVERSE);
      if(highlight == 1) {
         wattron(A_REVERSE);
      }
      mvprintw(saveWin, 8, (winrow - 2) / 2, "No");
      wattroff(A_REVERSE);
      refresh();
      wrefresh(saveWin);
      selection = getch();
      // Down to No
      if(selection == KEY_DOWN) {
         highlight++;
         if(highlight > 1) {
            highlight = 1;
         }
         selection = -1;
      }
      // Up to Yes
      else if(selection == KEY_UP) {
         highlight--;
         if(highlight < 0) {
            highlight = 0;
         }
         selection = -1;
      }
      // Select What is Chosen
      else if(selection == 10) {
         selection = highlight;
      }
      // Invalid Character
      else {
         selection = -1;
      }
   }
   if(selection == 1) {
      return;
   }
   // TODO: Write File Here
}

void endScreen() {
   clear();
   int row = 0;
   int col = 0;
   getmaxyx(stdscr, row, col);
   init_pair(9, COLOR_RED, COLOR_BLACK);
   wattron(COLOR_PAIR(9));
   wattron(A_BOLD);
   box(0, 0);
   mvprintw(row / 2, col / 2, "%s", "GAME OVER");
}

bool Game::passingPrompt() {
   clear();
   int row = 0;
   int col = 0;
   int winrow = 0;
   int wincol = 0;
   int selection = -1;
   int highlight = 1;
   getmaxyx(stdscr, row, col);
   std::string options[4] = {"What would you like to do?", "Access Inventory", "Continue Journey", "Quit Game"};
   winrow = row / 2;
   wincol = col / 2;
   WINDOW * promptWin = newwin(winrow, wincol, row / 4, col / 4);
   keypad(promptWin, true);
   box(promptWin, 0, 0);
   while(selection != 10) {
      selection = wgetch(promptWin);
      for(int i = 0; i < 4; i++) {
         if(highlight == i) {
            wattron(A_REVERSE);
         }
         mvwprintw(promptWin, 2*i + 2, (wincol - options[i].size()) / 2, options[i].c_str());
         wattroff(A_REVERSE);
      }
      if(selection == KEY_UP) {
         higlight--;
         if(highlight < 1) {
            highlight = 1;
         }
      }
      else if(selection == KEY_DOWN) {
         highlight++;
         if(highlight > 3) {
            higlight = 3;
         }
      }
      else if (selection == 10) {
         if(highlight == 1) {
            mainCharacter->accessInventory();
            clear();
            return false;
         }
         else if(highlight == 2) {
            clear();
            return false;
         }
         else if(highlight == 3) {
            clear();
            return true;
         }
      }
   }
}
