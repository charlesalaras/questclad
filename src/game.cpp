#include "game.hpp"
#include "event/battle_event.hpp"
#include "character/desert_factory.hpp"
#include "character/mountain_factory.hpp"
#include "character/cavern_factory.hpp"
#include <fstream>
#include <time.h>
#include <string>
#include <iostream>
#include <ctime>

// CLASSES
// WARRIOR == 0
// SWORDSMAN == 1
// MAGE == 2

// Desert
// Mountain
// Cavern

// 2021-02-13T03:00:53
Game::Game() {
   time_t rawtime;
   struct tm * timeinfo;
   time (&rawtime);
   timeinfo = localtime(&rawtime);
   char timestamp[20];
   strftime(timestamp, 20, "%Y-%m-%dT%h-%m-%S", timeinfo);
   saveName = std::string("Save-") + timestamp + ".txt";
   storyElements.push_back("The journey begins for our lone traveller, to get the Carvysian Talisman!");
   storyElements.push_back("The desert sands rumbled with ancient proverbs from a forgotten time.");
   storyElements.push_back("Creatures of many different forms roamed over this land.");
   storyElements.push_back("The question arose, why have these creatures lusted for blood?");
   storyElements.push_back("The mountainous regions proved no easier, as the foes became stronger.");
   storyElements.push_back("Surviving became a struggle, as nature also fought against your pursuit.");
   storyElements.push_back("Eventually, you reach a secluded forest to rest in the mountainous region.");
   storyElements.push_back("Moving along, you reach the cavernous depths of the land, long forgotten.");
   storyElements.push_back("The darkness consumes you, but you can feel the light at the end of the tunnel.");
   storyElements.push_back("\"One last time.\", you say to yourself, feeling the Talisman bode forth.");
}
Game::~Game() {
   delete mainCharacter;
   delwin(instanceWin);
}

void Game::build() {
   clear();
   wbkgd(stdscr, COLOR_PAIR(1));
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
   instanceWin = newwin(winrow, wincol, row / 4, col / 4);
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
      else if(((selection > 64 && selection < 91) || (selection > 96 && selection < 123)) && inputname.size() < 16) {
         inputname += selection;
         for(unsigned int i = 0; i < 16; i++) {
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
         for(unsigned int i = 0; i < 16; i++) {
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
   wclear(instanceWin);
   box(instanceWin, 0, 0);
   mvwprintw(instanceWin, 2, 2, "Traveller, what is your skill?");
   selection = 0;
   while(selection != 10) {
      for(int i = 0; i < 3; i++) {
         // Highlight if Option is Hovered
         if(highlight == i) {
            wattron(instanceWin, A_REVERSE);
         }
         mvwprintw(instanceWin, 4 + i*2, (wincol - skills[i].size()) / 2, skills[i].c_str());
         wattroff(instanceWin, A_REVERSE);
      }
      wrefresh(instanceWin);
      selection = wgetch(instanceWin);
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
   mainCharacter = new User(inputname, skillType);
   DesertFactory desertFac;
   MountainFactory mountFac;
   CavernFactory cavFac;
   for(int i = 0; i < 3; ++i) {
      events.registerEvent(new BattleEvent(instanceWin, mainCharacter, desertFac.getEnemy(i)));
   }
   for(int i = 0; i < 3; ++i) {
      events.registerEvent(new BattleEvent(instanceWin, mainCharacter, mountFac.getEnemy(i + 5)));
   }
   for(int i = 0; i < 3; ++i) {
      events.registerEvent(new BattleEvent(instanceWin, mainCharacter, cavFac.getEnemy(i + 15)));
   }
}

void Game::runGame() {
   std::string dialogue = "[ Press any key to continue. ]";
   int gameOver = 0;
   int i = 0;
   int row = 0;
   int col = 0;
   getmaxyx(stdscr,row,col);
   while(events.hasNext()) {
      clear();
      attron(COLOR_PAIR(1));
      mvprintw(0, (col - storyElements[i].size()) / 2, storyElements[i].c_str());
      mvprintw(2, (col - dialogue.size()) / 2, dialogue.c_str());
      refresh();
      getch(); // Wait for User Input before continuing
      attroff(COLOR_PAIR(1));
      clear();
      refresh();
      Event* curr = events.getNext();
        
      while(curr->isActive()) {
        wclear(instanceWin);
        curr->draw();
        wrefresh(instanceWin);

        int c = wgetch(instanceWin);
        curr->select(c);
      }
      delete curr;

      if(mainCharacter->getCurrentHealth() <= 0) {
         endScreen();
         return;
      }

      //saveGame(); // Automatically Saves Game
      // if(passingPrompt()) { // Returns True if User Wants to Quit
      //   return;
      // } // Asks User if they Would like to Use / Change Items
      ++i;
   }
   finishGame();
   return;
}

void Game::saveGame() {
   std::cout << "Saving game..." << std::endl;
   // TODO: Write File Here
   time_t my_time = time(NULL);
   std::cout << "Game saved at: " << std::ctime(&my_time) << std::endl;
}

void Game::endScreen() {
   wclear(instanceWin);
   int row = 0;
   int col = 0;
   getmaxyx(instanceWin, row, col);
   init_pair(9, COLOR_RED, COLOR_BLACK);
   wattron(instanceWin, COLOR_PAIR(9));
   wattron(instanceWin, A_BOLD);
   box(instanceWin, 0, 0);
   mvwprintw(instanceWin, row / 2, col / 2 - 5, "%s", "GAME OVER");
   wrefresh(instanceWin);
   wgetch(instanceWin);
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
            wattron(promptWin, A_REVERSE);
         }
         mvwprintw(promptWin, 2*i + 2, (wincol - options[i].size()) / 2, options[i].c_str());
         wattroff(promptWin, A_REVERSE);
      }
      if(selection == KEY_UP) {
         highlight--;
         if(highlight < 1) {
            highlight = 1;
         }
      }
      else if(selection == KEY_DOWN) {
         highlight++;
         if(highlight > 3) {
            highlight = 3;
         }
      }
      else if (selection == 10) {
         if(highlight == 1) {
            //mainCharacter->accessInventory();
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
   return true;
}

void Game::finishGame() {
   int row = 0;
   int col = 0;
   getmaxyx(stdscr, row, col);
   clear();
   std::string finale = "Press to take the Carvysian Talisman.";
   mvprintw(row / 2, (col - storyElements[storyElements.size() - 1].size()) / 2, storyElements[storyElements.size() - 1].c_str());
   init_pair(16, COLOR_CYAN, COLOR_BLACK);
   attron(COLOR_PAIR(16));
   mvprintw((row / 2) + 1, (col - finale.size()) / 2, finale.c_str());
   refresh();
   wgetch(instanceWin);
   clear();
   init_pair(17, COLOR_YELLOW, COLOR_BLACK);
   attron(COLOR_PAIR(17));
   attron(A_BOLD);
   box(stdscr, 0, 0);
   std::string congrats = "Congratulations! You won!!";
   std::vector<std::string> credits = {"Game made by:", "Charles Alaras", "Roth Vann", "Yazhou Shen"};
   std::string thanks = "Thank you for playing!";
   mvprintw(row / 2, (col - congrats.size()) / 2, congrats.c_str());
   for(int i = 0; i < credits.size(); i++) {
      mvprintw((row / 2) + (i + 1), (col - credits[i].size()) / 2, credits[i].c_str());
   }
   mvprintw((row / 2) + 6, (col - thanks.size()) / 2, thanks.c_str());
   refresh();
   getch();
   return;
}
