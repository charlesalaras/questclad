#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <ncurses.h>
#include <fstream>
#include <string>
#include <queue>
#include <map>

class Game {
private:
   std::string saveName;
   std::queue<Event*>eventBuffer;
   User* mainCharacter = nullptr;
   bool loadGame(); // Helper to Parametrized Constructor
   std::string getName();
   void endScreen();
   void build();
public:
   Game();
   Game(std::string fname); // Calls loadGame
   void runGame();
   void saveGame();
   bool passingPrompt();
};

#endif //__GAME_HPP__
