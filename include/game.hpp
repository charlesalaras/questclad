#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <fstream>
#include <string>
#include <queue>
#include <map>

class Game {
private:
   std::string filename;
   std::queue<Event*>eventBuffer;
   User* user = nullptr;
   bool loadGame(); // Helper to Loaded Constructor
   void buildInstance(); // Helper to Default Constructor
public:
   Game();
   ~Game();
   Game(std::string fname); // Calls loadGame
   void runGame();
   bool saveGame();
};