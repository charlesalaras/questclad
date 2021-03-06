#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "event_bus.hpp"
#include "event.hpp"
#include "character.hpp"
#include <ncurses.h>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>

class Game {
private:
   std::string saveName;
   EventBus events;
   std::vector<std::string>storyElements;
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