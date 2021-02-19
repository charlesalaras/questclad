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
   buildInstance();
}

Game::buildInstance() {
   clear();
   int row = 0;
   int col = 0;
   int winrow = 0;
   int wincol = 0;
   int selection = 0;
   getmaxyx(stdscr, row, col);
   winrow = row / 2;
   wincol = col / 2;
   WINDOW * instanceWin = newwin(winrow, wincol, row / 4, col / 4);
   keypad(instanceWin, true);
   box(instanceWin, ' ', 0);
   mvwprintw(instanceWin, 2, 2, "Traveller, what is your name?");
   mvwprintw(instanceWin, 4, 2, "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
   std::string inputname = "";
   char insertion[1];
   refresh();
   wrefresh(instanceWin);
   while(selection != 10) {
      selection = wgetch(instanceWin);
      // Nothing Entered
      if(inputname == "" && selection == 10) {
         selection = 0;
         mvwprintw(instanceWin, winrow - 1, 2, "Name must be at least 1 character!");
      }
      // (65-90 OR 97-122) and there's space
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
   mainCharacter = new User(inputname, 10);
}

void Game::runGame() {
   int gameOver = 0;
   while(!eventBuffer.empty()) {
      bool success = eventBuffer.front->runEvent();
      if(!success) {
         gameOver = 1;
         break;
      }
      saveGame(); // Asks User if They Would Like to Save
      passingPrompt(); // Asks User if they Would like to Use / Change Items
   }
}