#ifndef __GAME_HPP__
#define __GAME_HPP__

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
   void buildInstance(); // Helper to Default Constructor
   void passingPrompt();
public:
   Game();
   Game(std::string fname); // Calls loadGame
   void runGame();
   void saveGame();
};